# BTreeThreads.cpp
C++ implementation of https://github.com/malbrain/Btree-source-code/blob/master/threads2/threads2j.c

1. Replace unmap for hashmap with boost::serialization
2. Replace pthread/locks with C++14 threads/mutex/condition_variable
3. Replace hashmap with boost::concurrent_flat_map