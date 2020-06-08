//
// Created by pellegrin.pierre on 11/05/2020.
//

#include "Fenetre.h"
#include <SFML/Graphics.hpp>


Fenetre::Fenetre(int width, int height) : sf::RenderWindow(sf::VideoMode(width, height), "Le Double P-cross"),
                                          m_grille(10, 50), m_width(width), m_height(height) {
}

void Fenetre::clique() {

    sf::Vector2i caseClique;
    int caseParCote = m_grille.getCaseParCote();
    int tailleCase = m_grille.getTailleCoteCase();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        sf::Vector2i position = sf::Mouse::getPosition(*this);
        if (position.x >= 0 && position.y >= 0 && position.x <= caseParCote * (tailleCase + 3) &&
            position.y <= caseParCote * (tailleCase + 3)) {
            caseClique = m_grille.convertirPixelsEnGrille(position.x, position.y);
            m_grille.ajoutCaseClique(caseClique);
        }
    }
}

void Fenetre::run() {
    setVerticalSyncEnabled(true);
    while (isOpen()) {
        sf::Event event{};
        while (pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                close();
            }
            clique();
        }
        clear();
        draw(m_grille);
        display();
    }
    std::cout << "J'ai quitte la fenetre proprement !" << std::endl;
}
