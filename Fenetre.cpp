//
// Created by pellegrin.pierre on 11/05/2020.
//

#include "Fenetre.h"
#include "Logique.h"
#include <SFML/Graphics.hpp>


Fenetre::Fenetre(int width, int height) : sf::RenderWindow(sf::VideoMode(width, height), "Le Double P-cross"),
                                          m_grille(10, 50), m_width(width), m_height(height) {
}

void Fenetre::run() {
    setVerticalSyncEnabled(true);
    while (isOpen()) {
        sf::Event event{};
        while (pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i position = sf::Mouse::getPosition(*this);

                auto pixelEnGrille = m_grille.convertirGrilleEnPixels
                        ((m_grille.convertirPixelsEnGrille(position.x, position.y).x),
                         (m_grille.convertirPixelsEnGrille(position.x, position.y).y));

                float coordCaseCliqueX = pixelEnGrille.x;
                float coordCaseCliqueY = pixelEnGrille.y;

                int caseCliqueX = m_grille.convertirPixelsEnGrille(position.x, position.y).x;
                int caseCliqueY = m_grille.convertirPixelsEnGrille(position.x, position.y).y;

                std::vector<std::vector<int>> grilleSolution = Logique::recupGrilleSolution();
                int contenu = grilleSolution[caseCliqueY][caseCliqueX];

                std::cout << "Coordonnees : " << coordCaseCliqueX << " / " << coordCaseCliqueY << std::endl
                          << "Cases : " << caseCliqueX << " / " << caseCliqueY << std::endl
                          << "Contenu : " << contenu << std::endl;
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                std::cout << "neah" << std::endl;
            }
        }
        clear();
        draw(m_grille);
        display();
    }

    std::cout << "J'ai quitte la fenetre proprement !" <<
              std::endl;
}

