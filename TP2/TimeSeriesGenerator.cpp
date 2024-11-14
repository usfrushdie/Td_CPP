#include "TimeSeriesGenerator.h"

// Constructeur par défaut
TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {}

// Constructeur avec paramètre
TimeSeriesGenerator::TimeSeriesGenerator(int seed) : seed(seed) {}

// Méthode statique pour imprimer la série temporelle
void TimeSeriesGenerator::printTimeSeries(const std::vector<double>& series) {
    for (double value : series) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
