//
// Created by pellegrin.pierre on 25/05/2020.
//

#include "Logique.h"
#include "Grille.h"
#include <fstream>


Logique::Logique() {
    //calcul_bombes = 0
    //while calcul_bombes < nb_bombes:
    //x = int(random.randint(0, nb_cases_horizontales - 1))
    //y = int(random.randint(0, nb_cases_verticales - 1))
    //if m_grille[y][x] == 0:
    //m_grille[y][x] = 9
    //calcul_bombes += 1
    //comptage_bombes(m_grille)

}

void Logique::recupGrilleSolution() {
    std::string const cheminFichier("C:/Users/pellegrin.pierre/CLionProjects/Picross/solutionCarre.txt");
    std::ifstream monFlux(cheminFichier.c_str());
    int grille[10][10];
    if (monFlux) {
        char carac;
        int i, j = 0;
        while (monFlux.get(carac)) {
            if (carac == '0') {
                std::cout << "zero" << std::endl;
                grille[j][i] = 0;

            } else if (carac == '1') {
                std::cout << "un" << std::endl;
                grille[j][i] = 1;

            } else if (carac == '2') {
                std::cout << "deux" << std::endl;
                grille[j][i] = 2;

            }
            i++;
            if (i > 9){
                j++;
                i = 0;
            }
        }


    } else {
        std::cout << "Une erreur s'est produite : impossible d'ouvrir le fichier" << std::endl;
    }
    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 10; ++i) {
            std::cout << grille[j][i] << std::endl;
        }
    }
}