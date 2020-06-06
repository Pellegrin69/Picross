//
// Created by pellegrin.pierre on 11/05/2020.
//

#include "Grille.h"

Grille::Grille(int caseParCote, int tailleCoteCase) : m_caseParCote(caseParCote), m_tailleCoteCase(tailleCoteCase) {
}

void Grille::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < m_caseParCote; i++)
        for (int j = 0; j < m_caseParCote; j++) {
            //std::vector<std::vector<int>> grilleSolution = Logique::recupGrilleSolution();
            //int contenu = grilleSolution[caseCliqueY][caseCliqueX];

            sf::RectangleShape cases(sf::Vector2f(m_tailleCoteCase, m_tailleCoteCase));
            cases.setOutlineThickness(3);
            cases.setOutlineColor(sf::Color(75, 75, 75));
            cases.setFillColor(sf::Color::White);
            cases.setPosition(i * m_tailleCoteCase + 3, j * m_tailleCoteCase + 3);
            target.draw(cases);
        }
}

sf::Vector2i Grille::convertirGrilleEnPixels(int caseX, int caseY) const {
    sf::Vector2i coordonnees(caseX * m_tailleCoteCase, caseY * m_tailleCoteCase);
    return coordonnees;
}

sf::Vector2i Grille::convertirPixelsEnGrille(int coordoneesX, int coordoneesY) const {
    int caseX = coordoneesX / m_tailleCoteCase;
    int caseY = coordoneesY / m_tailleCoteCase;
    sf::Vector2i coordonnees(caseX, caseY);
    return coordonnees;
}

