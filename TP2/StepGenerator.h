#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include "TimeSeriesGenerator.h"

class StepGenerator : public TimeSeriesGenerator {
public:
    // Constructeur
    StepGenerator(int seed);

    // Méthode pour générer une série temporelle de type "saut"
    std::vector<double> generateTimeSeries(int size) override;
};

#endif // STEPGENERATOR_H
