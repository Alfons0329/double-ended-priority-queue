double-ended-priority-queue
===========================

About
---------------

- c++ implementation of DoubleEndedPriorityQueue

Implemented Algorithm
----------------------------------

- MinMaxHeap [[Atkinson et al., 86]](http://www.akira.ruc.dk/~keld/teaching/algoritmedesign_f03/Artikler/02/Atkinson86.pdf)

performance
--------------------------

- N=1000000

| Algorithm     | PUSH(s) | DELETE(s) |
|---------------|--------:|----------:|
| std::multiset |0.762    |1.151      |
| MinMaxHeap    |0.03     |0.207      |
