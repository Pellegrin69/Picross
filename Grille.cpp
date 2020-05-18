//
// Created by pellegrin.pierre on 11/05/2020.
//

#include "Grille.h"

Grille::Grille(int caseParCote) : m_caseParCote(caseParCote) {
}

void Grille::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Color noir = sf::Color(75, 75, 75);
    for (int i = 0; i < m_caseParCote; i++)
        for (int j = 0; j < m_caseParCote; j++) {

            sf::RectangleShape carre(sf::Vector2f(60, 60));
            carre.setOutlineThickness(3);
            carre.setOutlineColor(noir);
            carre.setFillColor(sf::Color::White);
            carre.setPosition(i * 60, j * 60);
            target.draw(carre);
        }
}


//target.draw(...);
//target.draw(...);
//target.draw(...);
//target.draw(...);
//target.draw(...);
//target.draw(...);
