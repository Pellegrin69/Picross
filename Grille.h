//
// Created by pellegrin.pierre on 11/05/2020.
//

#ifndef PICROSS_GRILLE_H
#define PICROSS_GRILLE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Logique.h"

class Grille : public sf::Drawable {

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    Logique m_logique;
    int m_caseParCote;
    int m_tailleCoteCase;
    std::vector<std::vector<int>> m_grilleCaseClique;
    std::vector<std::vector<int>> m_grilleSolution;

public:
    Grille(int caseParCote, int tailleCoteCase);

    int getCaseParCote() const;

    int getTailleCoteCase() const;

    sf::Vector2i convertirGrilleEnPixels(int caseX, int caseY) const;

    sf::Vector2i convertirPixelsEnGrille(int coordoneesX, int coordoneesY) const;

    void caseDejaClique(std::vector<std::vector<int>> &grille, sf::Vector2i coordonnees) const;

    void ajoutCaseClique(sf::Vector2i coordonnees);

};


#endif //PICROSS_GRILLE_H
