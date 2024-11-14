#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include <vector>
#include <iostream>

class TimeSeriesGenerator {
protected:
    int seed;

public:
    // Constructeurs
    TimeSeriesGenerator();
    TimeSeriesGenerator(int seed);

    // Méthode virtuelle pure
    virtual std::vector<double> generateTimeSeries(int size) = 0;

    // Méthode statique pour imprimer la série temporelle
    static void printTimeSeries(const std::vector<double>& series);
};

#endif // TIMESERIESGENERATOR_H
