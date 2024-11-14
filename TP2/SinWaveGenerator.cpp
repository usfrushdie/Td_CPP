#include "SinWaveGenerator.h"
#include <cmath>

// Constructeur de SinWaveGenerator
SinWaveGenerator::SinWaveGenerator(double amplitude, double frequency, double phase, int seed)
    : TimeSeriesGenerator(seed), amplitude(amplitude), frequency(frequency), phase(phase) {}

// Génération de séries temporelles sinusoïdales
std::vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    for (int i = 0; i < size; ++i) {
        double value = amplitude * std::sin(frequency * i + phase);
        series.push_back(value);
    }
    return series;
}
