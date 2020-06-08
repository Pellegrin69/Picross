//
// Created by pellegrin.pierre on 11/05/2020.
//

#ifndef PICROSS_FENETRE_H
#define PICROSS_FENETRE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grille.h"

class Fenetre : public sf::RenderWindow {

protected:
    Grille m_grille;
    int m_width;
    int m_height;

public:
    Fenetre(int width, int height);

    void clique();

    void run();

};


#endif //PICROSS_FENETRE_H
