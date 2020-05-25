#include <iostream>
#include <SFML/Graphics.hpp>
#include "Fenetre.h"
#include "Grille.h"

int main() {
    Fenetre fenetre(800, 800);
    fenetre.run();


    //const int WIDTH = 512;
    //const int HEIGHT = 512;
    //sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "LeDoublePcross");
    //window.setVerticalSyncEnabled(true);

    //while (window.isOpen()) {
    //    sf::Event event{};
    //    while (window.pollEvent(event)) {
    //        if (event.type == sf::Event::Closed) {
    //            window.close();
    //        }
    //    }
    //    window.clear();
    //    window.display();
    //}
    //std::cout << "J'ai quitte la fenetre proprement !" << std::endl;

    return 0;
}
