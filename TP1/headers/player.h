#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "card.h"         // Inclure la classe de base Card
#include "pokemon_card.h"  // Inclure la classe dérivée PokemonCard

class Player {



public:

    std::string playerName;                     // Nom du joueur
    std::vector<Card*> benchCards;              // Cartes en réserve (deck)
    std::vector<PokemonCard*> actionCards;      // Cartes Pokémon en action

    // Constructeur
    Player(const std::string& name);

    // Ajouter une carte à la réserve (deck)
    void addCardToBench(Card* card);

    // Activer une carte Pokémon en action depuis le deck
    void activatePokemonCard(int index);

    // Attacher une carte d'énergie à un Pokémon en action
    void attachEnergyCard(int actionIndex, int energyIndex);

    // Afficher les cartes en réserve (deck)
    void displayBench() const;

    // Afficher les cartes Pokémon en action
    void displayAction() const;

    void attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex);

    void useTrainer(int trainerCardIndex);


    // Destructeur pour libérer la mémoire allouée
    ~Player();
};

#endif // PLAYER_H
