# Fuzz binutils with MOPT

Get MOPT docker and binutils

```
docker pull zjuchenyuan/mopt
wget https://ftp.gnu.org/gnu/binutils/binutils-2.28.tar.gz --no-check-certificate
tar -xzvf binutils-2.28.tar.gz
cd binutils-2.28
```


Build binutils with fuzzing instrumentation
```
export CFLAGS="-fprofile-arcs -ftest-coverage" # (only when we use lcov)
CC=$PWD/../mopt/afl-gcc ./configure --prefix="/MOpt-AFL/install/" --disable-shared 
make
make install
```

Create input folder and add seed file inside input folder

Also add abinary file (here, helloworld)
Run fuzzer
```
afl-fuzz -V 3600 -i in -o out install/bin/strings helloworld @@
```

Measure Coverage
```
mkdir gcov
cd gcov
wget https://ftp.gnu.org/gnu/binutils/binutils-2.28.tar.gz --no-check-certificate
tar -xzvf binutils-2.28.tar.gz
cd binutils-2.28
```

Resetting counters for lcov

```
lcov --zerocounters --directory .
```

Capturing the current coverage state to a file
```
lcov --capture --initial --directory . --output-file base.info
```

export CFLAGS="-fprofile-arcs -ftest-coverage"
./configure  --prefix="/MOpt-AFL/gcov/install/" 
make
make install

./afl-cov -d ../../../afl_out --coverage-cmd \
"cat AFL_FILE | ../../gcov/install/bin/strings" \
--code-dir . --enable-branch-coverage
```



Combine the 'before tests' and 'after tests' snapshots

```
cd binutils-2.28
mkdir cc_report
lcov --no-external --capture --directory ../binutils-2.28/binutils --output-file test.info --rc lcov_branch_coverage=1

lcov --add-tracefile app.info --add-tracefile test.info --output-file total.info --rc lcov_branch_coverage=1 
```
Generate html coverage
```
genhtml --show-details --highlight --legend -output-directory ./html-coverage/ ./total.info --rc lcov_branch_coverage=1 
```

