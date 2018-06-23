# Quick Sort

Algorithm :- 

1.  if n = 1, return
2.  P = choosePivot(A, n)
3.  Partition A around P
4.  Recursively sort 1st Part before P
5.  Recursively sort 2nd Part after P

Partitioning Algorithm :-

1.  P = A[l]
2.  i = l + 1
3.  for j = l + 1 to r
4.    if A[j] < P
5.      swap A[j] & A[i+1], ++i
6.  swap A[l] & A[i]

Note:- choice of pivot is essential for the runtime of quick sort. For randomized pivot selection, quick sort runs at O(nlog(n))
at average.