# Fuzz binutils with MOPT
docker pull zjuchenyuan/mopt

wget https://ftp.gnu.org/gnu/binutils/binutils-2.28.tar.gz
tar -xzvf binutils-2.28.tar.gz
cd binutils-2.28
CC=afl-gcc ./configure
make
mkdir afl_in afl_out
cp /bin/ps afl_in/
afl-fuzz -i afl_in -o afl_out ./binutils/strings -t 3600 @@
