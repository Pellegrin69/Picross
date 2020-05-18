//
// Created by pellegrin.pierre on 11/05/2020.
//

#ifndef PICROSS_GRILLE_H
#define PICROSS_GRILLE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Grille : public sf::Drawable {

public:
    Grille(int caseParCote);


private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    int m_caseParCote;


};


#endif //PICROSS_GRILLE_H
