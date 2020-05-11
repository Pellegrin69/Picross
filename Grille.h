//
// Created by pellegrin.pierre on 11/05/2020.
//

#ifndef PICROSS_GRILLE_H
#define PICROSS_GRILLE_H

#include <SFML/Graphics.hpp>

class Grille : sf::Drawable {

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

protected:

public:

};


#endif //PICROSS_GRILLE_H
