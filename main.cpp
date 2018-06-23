#include <cstdlib>
#include <ctime>
#include "quickSort.h"

int main(int argc, char* argv[]){

    if(argc != 4){
        std::cerr << "Usage: " << argv[0] << " <vector size>, <low val>, <high val>" << std::endl;
        return 0;
    }
    int n = atoi(argv[1]);
    std::vector<int> a(n);

    srand(time(NULL));
    int LO = atoi(argv[2]);
    int HI = atoi(argv[3]);
    for(int i=0; i<n; ++i){
        a[i] = LO + (rand()/(RAND_MAX/(HI - LO)));
    }
    std::cout << "        Before Sort       " << std::endl;
    printVec(a);
    std::cout << std::endl;
    quickSort(a);
    std::cout << "        After Sort        " << std::endl;
    printVec(a);
    std::cout << std::endl;
    return 0;
}

