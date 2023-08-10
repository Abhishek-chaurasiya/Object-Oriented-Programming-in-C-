MEMORY MANAGEMENT  - 
  It is all aboubt managing finite of main memory to increase the degree of multiprogramming to its most optimal level.
   1.Fixed Partitioning of Memory(Contagious memory allocation): Main memory is distributed in some amount of sizes like 2mb,4mb,10mb,etc.
    But there is problem that if a process of size 1 mb is running in 4mb section 3 mb is wasted so this is called internal fragmentation.
    other problem limitation of problem size. 
    degree of multiprogramming is limited and fixed .
    This also leads to external fragmentation let say we have 1mb left in 2mb process,1 mb in 4 mb process and 1 mb in 10 mb process we have 3 mb vacant but when a 3 mb
    process comes into picture there is no room for this process to load.
    Think of fixed partitioning as a cake divided into some fixed parts.
  
   2.Dynamic partitioning : As the name suggest we allocate the memory based on the demand of process size dynamically.This fixed the problem of internal fragmentation 
