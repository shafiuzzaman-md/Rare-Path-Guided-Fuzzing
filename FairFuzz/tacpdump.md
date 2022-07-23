
```
docker pull aflplusplus/aflplusplus

cd $HOME
mkdir fuzzing_tcpdump && cd fuzzing_tcpdump/

wget https://github.com/the-tcpdump-group/tcpdump/archive/refs/tags/tcpdump-4.9.2.tar.gz
tar -xzvf tcpdump-4.9.2.tar.gz

wget https://github.com/the-tcpdump-group/libpcap/archive/refs/tags/libpcap-1.8.0.tar.gz
tar -xzvf libpcap-1.8.0.tar.gz

mv libpcap-libpcap-1.8.0/ libpcap-1.8.0
```
```
cd $HOME/fuzzing_tcpdump/libpcap-1.8.0/
CC=$PWD/../../../afl-rb/afl-gcc ./configure --disable-shared 
make

cd $HOME/fuzzing_tcpdump/tcpdump-tcpdump-4.9.2/
CC=$PWD/../../../afl-rb/afl-gcc --prefix="$HOME/fuzzing_tcpdump/install/"
make
make install
```
Seed: docker cp /Users/mdshafiuzzaman/PReachFuzzResult/PreachExp/tcpdump/random/tcpdump.pcap 8360257441ae://root/fuzzing_tcpdump/in


```
timeout 86400 $PWD/../../../afl-rb/afl-fuzz -i in -o out -- $HOME/fuzzing_tcpdump/install/sbin/tcpdump -vvvvXX -ee -nn -r @@
```
# Code coverage

```
mkdir $HOME/fuzzing_tcpdump/gcov-project && cd $HOME/fuzzing_tcpdump/gcov-project
wget https://github.com/the-tcpdump-group/tcpdump/archive/refs/tags/tcpdump-4.9.2.tar.gz
tar -xzvf tcpdump-4.9.2.tar.gz

wget https://github.com/the-tcpdump-group/libpcap/archive/refs/tags/libpcap-1.8.0.tar.gz
tar -xzvf libpcap-1.8.0.tar.gz

mv libpcap-libpcap-1.8.0/ libpcap-1.8.0
```

```
cd  gcov-project/libpcap-1.8.0
./configure --enable-shared=no CFLAGS="-fprofile-arcs -ftest-coverage"
make

cd  gcov-project/tcpdump-tcpdump-4.9.2
./configure --prefix="$HOME/fuzzing_tcpdump/gcov-project/install/" CFLAGS="-fprofile-arcs -ftest-coverage"
make
make install
```

```
./afl-cov/afl-cov -d ../../out --coverage-cmd "../install/sbin/tcpdump -vvvvXX -ee -nn -r < AFL_FILE" --code-dir . --enable-branch-coverage  --overwrite
```
