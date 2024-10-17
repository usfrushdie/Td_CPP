#include "SearchingAlgorithm.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> data = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 9;

    SearchingAlgorithm searchAlgo;

    // Recherche linéaire
    int result = searchAlgo.linearSearch(data, target);
    searchAlgo.displaySearchResults(std::cout, result, target);

    // Recherche par saut
    result = searchAlgo.jumpSearch(data, target);
    searchAlgo.displaySearchResults(std::cout, result, target);

    // Recherche binaire
    result = searchAlgo.binarySearch(data, target);
    searchAlgo.displaySearchResults(std::cout, result, target);

    return 0;
}
