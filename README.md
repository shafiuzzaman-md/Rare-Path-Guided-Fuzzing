# Fuzz binutils with MOPT

Get MOPT docker and binutils

```
docker pull zjuchenyuan/mopt
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


Build binutils with fuzzing instrumentation
```
export CFLAGS="-fprofile-arcs -ftest-coverage"
CC=$PWD/../mopt/afl-gcc ./configure --prefix="/MOpt-AFL/install/" --disable-shared 
make
make install
```

Run fuzzer
```
mkdir afl_in afl_out
afl-fuzz -V 60 -i afl_in -o afl_out /MOpt-AFL/install/bin/strings hello.o
```

Measure Coverage with afl-cov
```
mkdir gcov
cd gcov
wget https://ftp.gnu.org/gnu/binutils/binutils-2.28.tar.gz --no-check-certificate
tar -xzvf binutils-2.28.tar.gz
cd binutils-2.28

export CFLAGS="-fprofile-arcs -ftest-coverage"
./configure  --prefix="/gcov/install/" 
make
make install

./afl-cov -d ../MOpt-AFL/binutils-2.28/afl_out --coverage-cmd \
"cat AFL_FILE | ../MOpt-AFL/gcov/install/bin/strings" \
--code-dir . --enable-branch-coverage
```



Combine the 'before tests' and 'after tests' snapshots

```
lcov --add-tracefile app.info --add-tracefile test.info --output-file total.info --rc lcov_branch_coverage=1 
export CFLAGS="-fprofile-arcs -ftest-coverage"
```
Generate html coverage
```
genhtml -k total.info --highlight --legend -output-directory html-output ./html-coverage/ ./total.info --rc lcov_branch_coverage=1
```


