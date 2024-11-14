#include "TimeSeriesGenerator.h"
#include "GaussianGenerator.h"
#include "StepGenerator.h"
#include "SinWaveGenerator.h"
#include <iostream>
#include <vector>

int main() {
    // Question 1: Générer une série temporelle de base (pas directement applicable ici)
    // Utilisation de la fonction printTimeSeries pour afficher les séries

    // Question 2: Génération d'une série gaussienne
    std::cout << "Gaussian Series:" << std::endl;
    GaussianGenerator gaussGen(0.0, 1.0, 42); // Moyenne = 0, écart-type = 1, seed = 42
    std::vector<double> gaussianSeries = gaussGen.generateTimeSeries(10); // Série de 10 valeurs
    TimeSeriesGenerator::printTimeSeries(gaussianSeries);

    // Question 3: Génération d'une série de type "saut"
    std::cout << "\nStep Series:" << std::endl;
    StepGenerator stepGen(42); // Seed = 42
    std::vector<double> stepSeries = stepGen.generateTimeSeries(10); // Série de 10 valeurs
    TimeSeriesGenerator::printTimeSeries(stepSeries);

    // Question 4: Génération d'une série sinusoïdale
    std::cout << "\nSinusoidal Series:" << std::endl;
    SinWaveGenerator sinGen(1.0, 0.1, 0.0, 42); // Amplitude = 1.0, fréquence = 0.1, phase = 0, seed = 42
    std::vector<double> sinSeries = sinGen.generateTimeSeries(10); // Série de 10 valeurs
    TimeSeriesGenerator::printTimeSeries(sinSeries);

    return 0;
}
