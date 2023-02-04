# Run AFL++ on SV-Comp

## Docker: 
```docker pull mdshafiuzzaman/aflplusplus_rarefuzz:svcomp```

## Build:
```
cd ..
cd aflsvcomp
```
```afl-gcc prog.c -o prog.out -fprofile-arcs -ftest-coverage```

## Testcases:
```
mkdir in
cd in
wget https://raw.githubusercontent.com/Shafiuzzaman-Hira/RareFuzz/main/SV-Comp/seq-mthreaded/rare-input.txt
cd ..
```
## Fuzz:
```
timeout 300 afl-fuzz -i in/ -o out ./prog.out @@
```
## Showmap:
```
cd out/default 

afl-showmap -c -o output ./../../prog.out queue 
```

## Cov:
```
afl-cov  -d out --coverage-cmd \
"cat AFL_FILE |  ./prog.out @@" \
--code-dir . --enable-branch-coverage --overwrite
```
# Run FairFuzz on SV-Comp

## docker
```docker pull zjuchenyuan/fairfuzz```
## Build:
```../afl-rb/afl-gcc prog.c svcompwrapper.h -o prog.out -fprofile-arcs -ftest-coverage```

## Testcases:
```
mkdir in
cd in
wget https://raw.githubusercontent.com/Shafiuzzaman-Hira/RareFuzz/main/SV-Comp/seq-mthreaded/rare-input.txt
cd ..
```
## Fuzz:
```
timeout 450 ../afl-rb/afl-fuzz -i in/ -o out ./prog.out @@

```
## Showmap:
```
cd out/default 

afl-showmap -c -o output ./../../prog.out queue 
```

## Cov:
```
afl-cov  -d out --coverage-cmd \
"cat AFL_FILE |  ./prog.out @@" \
--code-dir . --enable-branch-coverage --overwrite
```