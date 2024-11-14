#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double amplitude;
    double frequency;
    double phase;

public:
    // Constructeur
    SinWaveGenerator(double amplitude, double frequency, double phase, int seed = 0);

    // Méthode pour générer une série temporelle sinusoïdale
    std::vector<double> generateTimeSeries(int size) override;
};

#endif // SINWAVEGENERATOR_H
