#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include <iostream>
#include <string>
#include "Card.h"  // Inclure la classe de base Card

class TrainerCard : public Card {

public:

    std::string trainerEffect;  // Effet de l'entraîneur
    
    // Constructeur
    TrainerCard(const std::string& name, const std::string& effect);

    // Fonction pour afficher les informations de la carte
    void displayInfo() const override;

    // Fonction pour appliquer l'effet du Trainer (soin des Pokémon)
    void applyEffect();
};

#endif // TRAINERCARD_H
