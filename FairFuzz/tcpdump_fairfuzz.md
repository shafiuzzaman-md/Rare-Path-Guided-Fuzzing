
Prepare fuzzing target. Create a new directory for the project you want to fuzz:
```
cd $HOME
mkdir fair_tcpdump && cd fair_tcpdump/
```
Download and uncompress tcpdump-4.9.2.tar.gz

```
wget https://github.com/the-tcpdump-group/tcpdump/archive/refs/tags/tcpdump-4.9.2.tar.gz
tar -xzvf tcpdump-4.9.2.tar.gz
```

We also need to download libpcap, a cross-platform library that is needed by TCPdump. Download and uncompress libpcap-1.8.0.tar.gz:

```
wget https://github.com/the-tcpdump-group/libpcap/archive/refs/tags/libpcap-1.8.0.tar.gz
tar -xzvf libpcap-1.8.0.tar.gz
```

We need to rename libpcap-libpcap-1.8.0 to libpcap-1.8.0. Otherwise, tcpdump doesn't find the libpcap.a local path:
```
mv libpcap-libpcap-1.8.0/ libpcap-1.8.0
```

Build and install libpcap:

```
cd $HOME/fair_tcpdump/libpcap-1.8.0/
CC=$PWD/../../../afl-rb/afl-gcc ./configure --disable-shared 
make
```

cd $HOME/fuzzing_tcpdump/tcpdump-tcpdump-4.9.2/
CC=$PWD/../../../afl-rb/afl-gcc ./configure --prefix="$HOME/fuzzing_tcpdump/install/"
make
make install
```
Seed: docker cp /Users/mdshafiuzzaman/PReachFuzzResult/PreachExp/tcpdump/random/tcpdump.pcap c7ebb1e86f4a://root/fuzzing_tcpdump/in


```
timeout 86400 $PWD/../../../afl-rb/afl-fuzz -d -r -i in -o out -- $HOME/fuzzing_tcpdump/install/sbin/tcpdump -nr @@
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
cd  libpcap-1.8.0
./configure --enable-shared=no CFLAGS="-fprofile-arcs -ftest-coverage"
make

cd  tcpdump-tcpdump-4.9.2
./configure --prefix="$HOME/fuzzing_tcpdump/gcov-project/install/" CFLAGS="-fprofile-arcs -ftest-coverage"
make
make install
```

```
./afl-cov/afl-cov -d ../../out --coverage-cmd "../install/sbin/tcpdump -nr < AFL_FILE" --code-dir . --enable-branch-coverage  --overwrite
```
