#include "SearchingAlgorithm.h"

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0) {}

void SearchingAlgorithm::resetComparisons() {
    numberComparisons = 0;
}

int SearchingAlgorithm::linearSearch(std::vector<int>& arr, int target) {
    resetComparisons();
    for (size_t i = 0; i < arr.size(); ++i) {
        numberComparisons++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int SearchingAlgorithm::jumpSearch(std::vector<int>& arr, int target) {
    resetComparisons();
    size_t n = arr.size();
    size_t step = std::sqrt(n);  // Taille du saut
    size_t prev = 0;

    while (arr[std::min(step, n) - 1] < target) {
        numberComparisons++;
        prev = step;
        step += std::sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }

    for (size_t i = prev; i < std::min(step, n); ++i) {
        numberComparisons++;
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int SearchingAlgorithm::binarySearch(std::vector<int>& arr, int target) {
    resetComparisons();
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        numberComparisons++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void SearchingAlgorithm::displaySearchResults(std::ostream& ost, int result, int target) {
    totalSearch++;
    totalComparisons += numberComparisons;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;

    if (result != -1) {
        ost << "Element " << target << " found at index " << result
            << " after " << numberComparisons << " comparisons." << std::endl;
    } else {
        ost << "Element " << target << " not found after " 
            << numberComparisons << " comparisons." << std::endl;
    }

    ost << "Total searches: " << totalSearch << std::endl;
    ost << "Total comparisons: " << totalComparisons << std::endl;
    ost << "Average comparisons per search: " << averageComparisons << std::endl;
}
