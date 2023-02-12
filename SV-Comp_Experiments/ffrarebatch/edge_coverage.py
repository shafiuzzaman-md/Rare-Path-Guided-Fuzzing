#!/usr/bin/env python3

import os
import time
import sys


dir = sys.argv[1] + "_out" + "/default/"
os.chdir(dir)


queue_out = r'queue_out'
if not os.path.exists(queue_out):
  os.makedirs(queue_out)

for filename in os.listdir("queue"):
    if not "id" in filename:
        continue
    with open(os.path.join("queue", filename), 'r') as f:
        in_filename = "queue/" + filename
        out_filename = "queue_out/" + filename + ".out"
        command = "afl-showmap -o " + out_filename + " ./../../"+ sys.argv[1] + ".out " + in_filename
        print(command)
        os.system(command)
        time.sleep(0.25)


log_dict = {}

for filename in os.listdir("queue_out"):
    if not "out" in filename:
        continue
    if "time:" in filename:
        log_key = int(filename.split("time:")[1].split(",")[0])
        log_val = filename
        log_dict[log_key] = log_val

sorted_log_dict = dict(sorted(log_dict.items(), key=lambda item: item[0]))


log = "time\tedge covered\n"

tuple_dict = {}
total_count = 0

for time,filename in sorted_log_dict.items():
	log += str(time) + "\t"
	with open(os.path.join("queue_out", filename), 'r') as f:
		lines = f.readlines()
		count = 0
		unique_count = 0

		for line in lines:
			key_val = line.strip().split(":")
			key = key_val[0]
			val = int(key_val[1])
			if key in tuple_dict:
				tuple_dict[key] += val
			else:
				tuple_dict[key] = val
				unique_count += 1
				total_count += 1
			count +=1
	print("Number of tuples for input file " + filename + " : " + str(count))
	print("Unique number of tuples for input file " + filename + " : " + str(unique_count))
	print("Total number of tuples : " + str(total_count))

	log += str(total_count) + "\n"

#print(log)
command = "echo \"" + log + "\" > coverage_log.txt"
os.system(command)


min_log =  sys.argv[1] + "\ntime (min)\tedge covered\n"
log_lines = log.split("\n")
min_to_compare = 1
last_coverage = 0
for line in log_lines:
    line_split = line.split("\t")
    if not line_split[0].isdigit():
        continue
    time_in_ms = int(line_split[0])
    if not line_split[1].isdigit():
        continue
    coverage = int(line_split[1])
    time_in_min = time_in_ms / (60000)
    #print(time_in_min)
    if time_in_min >= min_to_compare:
        min_log += str(min_to_compare) + "\t" + str(coverage) + "\n"
        min_to_compare += 1
    last_coverage = coverage
    if time_in_min > 10:
        break
if min_to_compare <10:
    min_log += str(min_to_compare) + "\t" + str(last_coverage)
print(min_log)
command = "echo \"" + min_log + "\" >> ../../coverage_data"
os.system(command)

