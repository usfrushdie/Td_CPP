#include "GaussianGenerator.h"
#include <cmath>
#include <cstdlib>

// Constructeur
GaussianGenerator::GaussianGenerator(double mean, double stddev, int seed)
    : TimeSeriesGenerator(seed), mean(mean), stddev(stddev) {
    srand(seed);
}

// Génération de séries temporelles avec distribution gaussienne
std::vector<double> GaussianGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    for (int i = 0; i < size; ++i) {
        double u1 = ((double) rand() / (RAND_MAX));
        double u2 = ((double) rand() / (RAND_MAX));
        double z0 = sqrt(-2.0 * log(u1)) * cos(2 * M_PI * u2);
        series.push_back(mean + z0 * stddev);
    }
    return series;
}
