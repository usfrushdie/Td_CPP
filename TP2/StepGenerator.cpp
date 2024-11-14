#include "StepGenerator.h"
#include <cstdlib>

// Constructeur
StepGenerator::StepGenerator(int seed) : TimeSeriesGenerator(seed) {
    srand(seed);
}

// Génération de séries temporelles de type saut
std::vector<double> StepGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    double currentValue = 0;
    series.push_back(currentValue);

    for (int i = 1; i < size; ++i) {
        if (rand() % 2 == 0) {
            currentValue = (rand() % 101); // Nouvelle valeur entre 0 et 100
        }
        series.push_back(currentValue);
    }
    return series;
}
