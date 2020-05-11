//
// Created by pellegrin.pierre on 11/05/2020.
//

#ifndef PICROSS_FENETRE_H
#define PICROSS_FENETRE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Fenetre : public sf::RenderWindow {

public:

    Fenetre(int width, int height);

    void run();

};


#endif //PICROSS_FENETRE_H
