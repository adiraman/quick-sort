#include "quickSort.h"

// function to set up the quickSort
void quickSort(std::vector<int>& v){
    int l = 0;
    int r = v.size() - 1;
    qsrt(v, l, r);
}

// the real quicksort routine
void qsrt(std::vector<int>& v, const int l, const int r){

    // Base case ( exit condition )
    // if the input vector has only 1 element, then it is
    // already sorted (l = r).
    // the execution of this routine is invalid for l > r.
    if(l >= r) return;

    // Choose a pivot element and move it to the front
    choosePivot(v, l , r);

    // Partition the vector around the pivot, this ensures that
    // the pivot is moved to its rightful position. Also all the
    // elements before the pivot are smaller than the pivot, and all
    // the elements after the pivot are greater than it.
    int part = partition(v, l, r);

    // Recursively sort the left and right partitions
    qsrt(v, l, part - 1);
    qsrt(v, part + 1, r);

    return;
}

void choosePivot(std::vector<int>& v, const int l, const int r){

    // Choose the pivot point uniformly at random from the given
    // vector. For more info on how to do this refer
    // http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd;// used to obtain a seed for random # gen
    std::mt19937 gen(rd());// mersenne_twister_engine seeded with rd
    std::uniform_int_distribution<> dis(l, r);

    int pivotInd = dis(gen);

    // bring the pivot element at the beginning
    if(pivotInd != l){
        interchange(&v[l], &v[pivotInd]);
    }

    return;
}

int partition(std::vector<int>& v, const int l, const int r){

    int pivot = v[l];

    // i = index that keeps track of the interface between all the
    //     less than and greater than pivot elements
    // j = index that keeps track of the interface between all the
    //     seen ( partitioned ) and unseen ( unpartitioned ) elements
    int i = l;
    for(int j = i+1; j <= r; ++j){
        if(v[j] <= pivot){
            interchange(&v[i+1], &v[j]);
            ++i;
        }
    }

    interchange(&v[l], &v[i]);
    return i;
}

void interchange(int* a, int* b){

    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}

void printVec(const std::vector<int>& v){
    for(auto i:v){
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}
