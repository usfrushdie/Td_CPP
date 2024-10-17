#include "MatrixBase.h"  // Inclure le fichier d'en-tête de la classe MatrixBase
#include <iostream>

int main() {
    // Création d'une matrice 3x3 de type double
    MatrixBase<double> matrix(3, 3);

    // Ajout d'éléments à la matrice
    try {
        matrix.addElement(1.1);
        matrix.addElement(2.2);
        matrix.addElement(3.3);
        matrix.addElement(4.4);
        matrix.addElement(5.5);
        matrix.addElement(6.6);
        matrix.addElement(7.7);
        matrix.addElement(8.8);
        matrix.addElement(9.9);

        // Tenter d'ajouter un élément supplémentaire pour déclencher une exception
        std::cout << "Ajout d'un élément supplémentaire (devrait provoquer une exception):" << std::endl;
        matrix.addElement(10.1);  // Ceci déclenchera une exception

    } catch (const std::out_of_range& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    // Affichage de la matrice
    std::cout << "Matrice 3x3:" << std::endl;
    matrix.Display();

    // Récupération d'un élément spécifique
    try {
        int row = 2, col = 2;
        double element = matrix.getElement(row, col);
        std::cout << "Élément à la position (" << row << ", " << col << ") : " << element << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Erreur lors de l'accès à l'élément : " << e.what() << std::endl;
    }

    return 0;
}
