#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "Card.h" // Inclure le fichier de la classe de base

class PokemonCard : public Card {

public:

    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    std::vector<std::tuple<int, int, std::string, int>> attacks;

    // Constructeur
    PokemonCard(const std::string& name, const std::string& type, const std::string& family,
                int level, int max_hp, int current_hp,
                const std::vector<std::tuple<int, int, std::string, int>>& atk);

    // Fonction pour afficher les informations de la carte
    void displayInfo() const override;

    // Méthodes d'accès
    void setHP(int newHP);
    int getHP() const;
    int getMaxHP() const;
};

#endif // POKEMONCARD_H
