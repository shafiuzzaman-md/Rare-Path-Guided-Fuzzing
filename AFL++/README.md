
```
docker pull aflplusplus/aflplusplus
wget https://ftp.gnu.org/gnu/binutils/binutils-2.28.tar.gz
tar -xzvf binutils-2.28.tar.gz
```

Build binary for afl-cov support
```
mkdir gcov-project
cp -r binutils-2.28 gcov-project/binutils-2.28
cd  gcov-project/binutils-2.28
./configure --prefix="/gcov-project/install/" CC="gcc" CXX="g++" CFLAGS="-fprofile-arcs -ftest-coverage" --disable-shared
