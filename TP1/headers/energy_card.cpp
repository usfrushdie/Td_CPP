#include "energy_card.h"

// Constructeur
EnergyCard::EnergyCard(const std::string& type)
    : Card("Energy"), energyType(type) {}

// Fonction pour afficher les informations de la carte
void EnergyCard::displayInfo() const {
    std::cout << "Energy Card - Type: " << energyType << std::endl;
}
