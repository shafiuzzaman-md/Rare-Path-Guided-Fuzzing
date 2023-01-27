Run AFL++ on SV-Comp
Build:

```afl-gcc prog.c -o prog.out -fprofile-arcs -ftest-coverage```

Testcases:

mkdir in
cd in
vi testcase.txt
cd ..

Fuzz:

timeout 300 afl-fuzz -i in/ -o out ./prog.out @@

Showmap:

cd out/default 

afl-showmap -c -o output ./../../prog.out queue 


Cov:

afl-cov  -d out --coverage-cmd \
"cat AFL_FILE |  ./prog.out @@" \
--code-dir . --enable-branch-coverage --overwrite
