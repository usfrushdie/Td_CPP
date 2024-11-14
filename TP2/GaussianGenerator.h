#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.h"

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;
    double stddev;

public:
    // Constructeur
    GaussianGenerator(double mean, double stddev, int seed);

    // Méthode pour générer une série temporelle gaussienne
    std::vector<double> generateTimeSeries(int size) override;
};

#endif // GAUSSIANGENERATOR_H
