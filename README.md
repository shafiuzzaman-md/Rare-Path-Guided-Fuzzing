# Rare-Path Guided Fuzzing

Starting with a random initial seed, fuzzers search for inputs that trigger bugs or vulnerabilities. However, fuzzers often fail to generate inputs for program paths guarded by restrictive branch conditions. In this project, we show that by first identifying rare-paths in programs (i.e., program paths with path constraints that are unlikely to be satisfied by random input generation), and then, generating inputs/seeds that trigger rare-paths, one can improve the coverage of fuzzing tools. 

# Docker 
AFL++

```
docker pull mdshafiuzzaman/aflplusplus_rarefuzz
```

Fairfuzz

```
docker pull mdshafiuzzaman/fairfuzz
```


# Tool setup 

[afl-cov installation](https://github.com/Shafiuzzaman-Hira/PReachFuzz/blob/main/afl-cov)


# Fuzzing working examples

[Fuzz tcpdump with afl++](https://github.com/Shafiuzzaman-Hira/PReachFuzz/blob/2f2df725a9bdc213d8257fc1bc3aab1c026d0f8c/AFL++/Fuzz%20tcpdump)

[Fuzz tcpdump with FairFuzz](https://github.com/Shafiuzzaman-Hira/PReachFuzz/blob/156f1fde28a33829e7d996244d68bc23ef8bc19e/FairFuzz/tacpdump.md)

[Fuzz binutils with MOPT](https://github.com/Shafiuzzaman-Hira/PReachFuzz/blob/main/MOPT/README.md)
