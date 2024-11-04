#include "pokemon_card.h"

// Constructeur
PokemonCard::PokemonCard(const std::string& name, const std::string& type, const std::string& family,
                         int level, int max_hp, int current_hp,
                         const std::vector<std::tuple<int, int, std::string, int>>& atk)
    : Card(name), pokemonType(type), familyName(family), evolutionLevel(level),
      maxHP(max_hp), hp(current_hp), attacks(atk) {}

// Fonction pour afficher les informations de la carte
void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card - Name: " << cardName << ", Type: " << pokemonType
              << ", Evolution Level: " << evolutionLevel << ", Family: " << familyName
              << ", HP: " << hp << "/" << maxHP << std::endl;

    std::cout << "Attacks:" << std::endl;
    for (size_t i = 0; i < attacks.size(); ++i) {
        int cost, currentEnergy, damage;
        std::string description;
        std::tie(cost, currentEnergy, description, damage) = attacks[i];
        
        std::cout << "  Attack #" << i + 1 << ":" << std::endl;
        std::cout << "    Attack cost: " << cost << std::endl;
        std::cout << "    Current energy storage: " << currentEnergy << std::endl;
        std::cout << "    Attack description: " << description << std::endl;
        std::cout << "    Attack damage: " << damage << std::endl;
    }
}

// Méthodes d'accès
void PokemonCard::setHP(int newHP) {
    hp = std::min(newHP, maxHP);
}

int PokemonCard::getHP() const {
    return hp;
}

int PokemonCard::getMaxHP() const {
    return maxHP;
}
