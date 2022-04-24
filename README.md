# Fuzz binutils with MOPT

### Get MOPT docker and binutils
```
docker pull zjuchenyuan/mopt
wget https://ftp.gnu.org/gnu/binutils/binutils-2.28.tar.gz --no-check-certificate
tar -xzvf binutils-2.28.tar.gz
cd binutils-2.28
```

### afl-cov Installation
```
$ apt-get install afl-cov
# this version seemes not supporting branch coverage statistics

$ apt-get install lcov
$ git clone https://github.com/mrash/afl-cov.git
$ ./afl-cov/afl-cov -V
$ afl-cov-0.6.2
# this way you get latest version
```

### Build binary for afl-cov support
```
cp -r binutils-2.28 gcov-project
cd  gcov-project/binutils-2.28
$ make clean 
$ ./configure --prefix="/MOpt-AFL/gcov-project/install/" CC="gcc" CXX="g++" CFLAGS="-fprofile-arcs -ftest-coverage" --disable-shared
$ make
$ make install
```

### Build binutils
```
export CFLAGS="-fprofile-arcs -ftest-coverage" # (only when we use lcov)
CC=$PWD/../mopt/afl-gcc ./configure --prefix="/MOpt-AFL/install/" --disable-shared 
make
make install
```



### Run fuzzer
```
# Create input folder and add seed file inside input folder

/MOpt-AFL/mopt/afl-fuzz -V 3600 -i in -o out install/bin/strings @@



### Measure Coverage

```
cd gcov-project/binutils-2.28/binutils
afl-cov -d ../../out --coverage-cmd "cat AFL_FILE | ../install/bin/strings" --code-dir . --overwrite
```

Copy result to host
```
docker cp 2263eb931329://MOpt-AFL/out/  /Users/mdshafiuzzaman/Research/PReachFuzzResult
```

