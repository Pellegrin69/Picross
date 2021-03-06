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

std::vector<std::vector<int>> Logique::recupGrilleSolution() {
    std::string const cheminFichier("C:/Users/pellegrin.pierre/CLionProjects/Picross/solutionCarre.txt");
    std::ifstream monFlux(cheminFichier.c_str());
    std::vector<std::vector<int>> grilleSolution;
    if (monFlux) {
        char carac;
        int i = 0;
        int j = 0;
        int valeurCase;
        std::vector<int> ligneSolution;
        while (monFlux.get(carac)) {
            if (carac == '0') { valeurCase = 0; }
            else if (carac == '1') { valeurCase = 1; }
            else { continue; }
            ligneSolution.push_back(valeurCase);
            i++;
            if (i > 9) {
                grilleSolution.push_back(ligneSolution);
                ligneSolution.clear();
                j++;
                i = 0;
            }
        }

    } else { std::cout << "Une erreur s'est produite : impossible d'ouvrir le fichier" << std::endl; }

    return grilleSolution;
}