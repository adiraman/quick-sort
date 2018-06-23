#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <iostream>
#include <vector>
#include <random>

void choosePivot(std::vector<int>& v, const int l, const int r);

int partition(std::vector<int>& v, const int l, const int r);

void quickSort(std::vector<int>& v);

void qsrt(std::vector<int>& v, const int l, const int r);

void interchange(int* a, int* b);

void printVec(const std::vector<int>& v);

#endif /* ifndef QUICK_SORT_H*/
