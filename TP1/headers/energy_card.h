#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include <iostream>
#include <string>
#include "Card.h"  // Inclure la classe de base Card

class EnergyCard : public Card {

public:
    // Constructeur
    EnergyCard(const std::string& type);

        std::string energyType;  // Type d'énergie (ex : Electric, Water)

    // Fonction pour afficher les informations de la carte
    void displayInfo() const override;
};

#endif // ENERGYCARD_H
