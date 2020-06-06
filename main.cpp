#include <iostream>
#include <SFML/Graphics.hpp>
#include "Fenetre.h"
#include "Grille.h"
#include "Logique.h"

int main() {
    Logique oui;
    oui.recupGrilleSolution();
    Fenetre fenetre(800, 800);
    fenetre.run();

    return 0;
}
