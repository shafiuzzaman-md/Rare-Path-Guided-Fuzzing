# Fuzz binutils with MOPT

Get MOPT docker and binutils

```
docker pull zjuchenyuan/mopt

wget https://ftp.gnu.org/gnu/binutils/binutils-2.28.tar.gz --no-check-certificate
tar -xzvf binutils-2.28.tar.gz

```


cd binutils-2.28

Resetting counters for lcov

```
lcov --zerocounters --directory .
```

Capturing the current coverage state to a file

```
lcov --capture --initial --directory . --output-file base.info
```

Flag for code coverage

```
export CFLAGS="-fprofile-arcs -ftest-coverage"
```

Build binutils with fuzzing instrumentation

```
CC=afl-gcc ./configure

make
```

Run fuzzer

```
mkdir afl_in afl_out

cp /bin/ps afl_in/

afl-fuzz -i afl_in -o afl_out ./binutils/strings -V 3600 @@

```
