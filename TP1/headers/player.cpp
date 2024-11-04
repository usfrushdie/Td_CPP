#include "Player.h"
#include "pokemon_card.h"    // Inclure la classe EnergyCard pour vérifier le type
#include "trainer_card.h"   // Inclure la classe TrainerCard pour vérifier le type
#include "energy_card.h"
#include "Card.h"


// Constructeur
Player::Player(const std::string& name) : playerName(name) {}

// Ajouter une carte au deck (benchCards)
void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

// Activer une carte Pokémon en action depuis le deck (benchCards)
void Player::activatePokemonCard(int index) {
    if (index >= 0 && index < benchCards.size()) {
        PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(benchCards[index]);
        if (pokemonCard) {
            actionCards.push_back(pokemonCard);
            std::cout << playerName << " is activating a Pokemon Card: " << pokemonCard->cardName << std::endl;
            benchCards.erase(benchCards.begin() + index);  // Retirer la carte de la réserve
        } else {
            std::cout << "Selected card is not a Pokemon Card." << std::endl;
        }
    } else {
        std::cout << "Invalid index for benchCards." << std::endl;
    }
}

// Attacher une carte d'énergie à un Pokémon en action
void Player::attachEnergyCard(int actionIndex, int energyIndex) {
    if (actionIndex >= 0 && actionIndex < actionCards.size() && energyIndex >= 0 && energyIndex < benchCards.size()) {
        EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards[energyIndex]);
        if (energyCard) {
            std::cout << playerName << " is attaching Energy Card of type " << energyCard->energyType << " to the Pokemon " << actionCards[actionIndex]->cardName << std::endl;
            // Logique d'attachement de l'énergie (mise à jour de l'énergie du Pokémon)
            benchCards.erase(benchCards.begin() + energyIndex);  // Retirer la carte de la réserve
        } else {
            std::cout << "Selected card is not an Energy Card." << std::endl;
        }
    } else {
        std::cout << "Invalid index for actionCards or benchCards." << std::endl;
    }
}

// Afficher les cartes en réserve (benchCards)
void Player::displayBench() const {
    std::cout << "Bench cards for Player " << playerName << ":" << std::endl;
    for (const auto& card : benchCards) {
        card->displayInfo();
    }
}

// Afficher les cartes Pokémon en action
void Player::displayAction() const {
    std::cout << "Action cards for Player " << playerName << ":" << std::endl;
    for (const auto& pokemonCard : actionCards) {
        pokemonCard->displayInfo();
    }
}

// Destructeur pour libérer la mémoire allouée
Player::~Player() {
    for (auto& card : benchCards) {
        delete card;
    }
    for (auto& pokemonCard : actionCards) {
        delete pokemonCard;
    }
}

void Player::attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex) {
    // Vérifier les indices
    if (attackerIndex >= 0 && attackerIndex < actionCards.size() && targetIndex >= 0 && targetIndex < opponent.actionCards.size()) {
        PokemonCard* attacker = actionCards[attackerIndex];
        PokemonCard* target = opponent.actionCards[targetIndex];

        // Vérifier l'existence de l'attaque
        if (attackIndex >= 0 && attackIndex < attacker->attacks.size()) {
            int cost, currentEnergy, damage;
            std::string description;
            std::tie(cost, currentEnergy, description, damage) = attacker->attacks[attackIndex];

            // Vérifier si l'énergie est suffisante
            if (currentEnergy >= cost) {
                std::cout << playerName << " attacking " << opponent.playerName << "'s Pokemon " << target->cardName
                          << " with the Pokemon " << attacker->cardName << " using attack: " << description << std::endl;
                std::cout << "Reducing " << damage << " HP from " << target->cardName << std::endl;

                // Appliquer les dégâts
                target->hp -= damage;
                if (target->hp <= 0) {
                    target->hp = 0;
                    std::cout << "Pokemon " << target->cardName << " has fainted." << std::endl;
                } else {
                    std::cout << "Pokemon " << target->cardName << " is still alive with " << target->hp << " HP." << std::endl;
                }
            } else {
                std::cout << "Not enough energy to perform the attack." << std::endl;
            }
        } else {
            std::cout << "Invalid attack index." << std::endl;
        }
    } else {
        std::cout << "Invalid attacker or target index." << std::endl;
    }
}

void Player::useTrainer(int trainerCardIndex) {
    // Vérifier que l'indice est valide dans benchCards
    if (trainerCardIndex >= 0 && trainerCardIndex < benchCards.size()) {
        TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(benchCards[trainerCardIndex]);

        if (trainerCard && trainerCard->trainerEffect == "heal all your action pokemon") {
            std::cout << playerName << " is using the Trainer Card to \"" << trainerCard->trainerEffect << "\"" << std::endl;

            // Appliquer l'effet : soigner tous les Pokémon en action
            for (auto& pokemon : actionCards) {
                pokemon->hp = pokemon->maxHP;
            }

            // Retirer la carte de la réserve après utilisation
            delete trainerCard;
            benchCards.erase(benchCards.begin() + trainerCardIndex);
        } else {
            std::cout << "Selected card is not a Trainer Card or does not have the correct effect." << std::endl;
        }
    } else {
        std::cout << "Invalid index for benchCards." << std::endl;
    }
}