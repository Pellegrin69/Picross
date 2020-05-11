//
// Created by pellegrin.pierre on 11/05/2020.
//

#include "Fenetre.h"
#include <SFML/Graphics.hpp>


void Fenetre::run() {
    setVerticalSyncEnabled(true);
    while (isOpen()) {
        sf::Event event{};

        while (pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                close();
            }
        }
        clear();
        display();
    }
    std::cout << "J'ai quitte la fenetre proprement !" << std::endl;
}

Fenetre::Fenetre(int width, int height) : sf::RenderWindow(sf::VideoMode(width, height), "Le Double P-cross") {
}
