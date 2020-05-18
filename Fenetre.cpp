//
// Created by pellegrin.pierre on 11/05/2020.
//

#include "Fenetre.h"
#include <SFML/Graphics.hpp>

Fenetre::Fenetre(int width, int height) : sf::RenderWindow(sf::VideoMode(width, height), "Le Double P-cross"),
                                          grille(10) {
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
                std::cout << "(" << position.x << " , " << position.y << ")" << std::endl;
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                std::cout << "neah" << std::endl;
            }
        }
        clear();
        draw(grille);
        display();
    }

    std::cout << "J'ai quitte la fenetre proprement !" <<
              std::endl;
}
