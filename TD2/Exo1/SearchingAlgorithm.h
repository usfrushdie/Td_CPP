#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

#include <vector>
#include <iostream>
#include <cmath>

class SearchingAlgorithm {
public:
    int numberComparisons;
    static int totalComparisons;
    static int totalSearch;
    static double averageComparisons;

    SearchingAlgorithm();
    
    int linearSearch(std::vector<int>&, int);
    int jumpSearch(std::vector<int>&, int);
    int binarySearch(std::vector<int>&, int);

    void displaySearchResults(std::ostream&, int result, int target);

private:
    void resetComparisons();
};

#endif
