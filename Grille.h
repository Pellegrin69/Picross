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
    Grille(int caseParCote, int tailleCoteCase);

    sf::Vector2i convertirGrilleEnPixels(int caseX, int caseY) const;

    sf::Vector2i convertirPixelsEnGrille(int coordoneesX, int coordoneesY) const;

    //case_x = int(x // taille_cote_case)
    //case_y_tmp = int(y // taille_cote_case)
    //case_y = nb_cases_verticales - case_y_tmp - 1
    //return case_x, case_y


private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    int m_caseParCote;

    int m_tailleCoteCase;


};


#endif //PICROSS_GRILLE_H
