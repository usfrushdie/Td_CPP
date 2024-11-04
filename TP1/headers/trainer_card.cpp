#include "trainer_card.h"

// Constructeur
TrainerCard::TrainerCard(const std::string& name, const std::string& effect)
    : Card(name), trainerEffect(effect) {}

// Fonction pour afficher les informations de la carte
void TrainerCard::displayInfo() const {
    std::cout << "Trainer Card - Name: " << cardName << ", Effect: " << trainerEffect << std::endl;
}

// Fonction pour appliquer l'effet du Trainer
void TrainerCard::applyEffect() {
    if (trainerEffect == "heal all your action pokemon") {
        std::cout << cardName << " is using the effect: " << trainerEffect << std::endl;
        // Logique pour soigner tous les Pokémon en action.
        // Ce code nécessitera une référence à un objet de type Player
        // pour accéder aux Pokémon en action et les soigner.
    }
}
