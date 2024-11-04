#ifndef CARD_H    // Vérifie si CARD_H n'est pas déjà défini
#define CARD_H    // Définit CARD_H

#include <string>

class Card {
protected:
    std::string cardName;  // Nom de la carte

public:
    Card(const std::string& name) : cardName(name) {}

    virtual void displayInfo() const = 0;

    // Ajouter un accesseur pour cardName
    std::string getCardName() const { return cardName; }

    virtual ~Card() {}
};

#endif // CARD_H
