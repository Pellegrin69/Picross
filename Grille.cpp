//
// Created by pellegrin.pierre on 11/05/2020.
//

#include "Grille.h"
#include "Logique.h"

Grille::Grille(int caseParCote, int tailleCoteCase) : m_caseParCote(caseParCote), m_tailleCoteCase(tailleCoteCase) {
    int i = 0;
    int j = 0;
    int compteur = 0;
    std::vector<int> ligneTmp;
    while (compteur < 100) {
        ligneTmp.push_back(0);
        i++;
        if (i > 9) {
            m_grilleCaseClique.push_back(ligneTmp);
            ligneTmp.clear();
            j++;
            i = 0;
        }
        compteur++;
    }
    m_grilleSolution = m_logique.recupGrilleSolution();
}

void Grille::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    std::vector<std::vector<int>> grilleSolution = m_grilleSolution;
    bool cliqueGauche = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    bool cliqueDroit = sf::Mouse::isButtonPressed(sf::Mouse::Right);
    for (int j = 0; j < m_caseParCote; j++)
        for (int i = 0; i < m_caseParCote; i++) {
            int caseClique = m_grilleCaseClique[j][i];
            int contenu = grilleSolution[j][i];
            auto pixelEnGrille = convertirGrilleEnPixels(i, j);
            float coordCaseCliqueX = pixelEnGrille.x + 3;
            float coordCaseCliqueY = pixelEnGrille.y + 3;

            if (caseClique == 1) {
                if (contenu == 1) {
                    if (cliqueDroit) {
                        std::cout << "FAUX !" << std::endl;
                    }
                    sf::RectangleShape casePleine(sf::Vector2f(m_tailleCoteCase, m_tailleCoteCase));
                    casePleine.setFillColor(sf::Color(50, 50, 50));
                    casePleine.setOutlineThickness(3);
                    casePleine.setOutlineColor(sf::Color(75, 75, 75));
                    casePleine.setPosition(coordCaseCliqueX, coordCaseCliqueY);
                    target.draw(casePleine);

                } else {
                    if (cliqueGauche) {
                        std::cout << "FAUX !" << std::endl;
                    }
                    sf::RectangleShape croix(sf::Vector2f(m_tailleCoteCase, m_tailleCoteCase));
                    croix.setFillColor(sf::Color(175, 175, 175));
                    croix.setOutlineThickness(3);
                    croix.setOutlineColor(sf::Color(75, 75, 75));
                    croix.setPosition(coordCaseCliqueX, coordCaseCliqueY);
                    target.draw(croix);
                }
            } else {
                sf::RectangleShape cases(sf::Vector2f(m_tailleCoteCase, m_tailleCoteCase));
                cases.setOutlineThickness(3);
                cases.setOutlineColor(sf::Color(75, 75, 75));
                cases.setFillColor(sf::Color::White);
                cases.setPosition(i * (m_tailleCoteCase + 3) + 3, j * (m_tailleCoteCase + 3) + 3);
                target.draw(cases);
            }

        }
}

int Grille::getCaseParCote() const {
    int nbCaseParCote = m_caseParCote;
    return nbCaseParCote;
}

int Grille::getTailleCoteCase() const {
    int tailleCase = m_tailleCoteCase;
    return tailleCase;
}

sf::Vector2i Grille::convertirGrilleEnPixels(int caseX, int caseY) const {
    sf::Vector2i coordonnees(caseX * (m_tailleCoteCase + 3), caseY * (m_tailleCoteCase + 3));
    return coordonnees;
}

sf::Vector2i Grille::convertirPixelsEnGrille(int coordoneesX, int coordoneesY) const {
    int caseX = coordoneesX / (m_tailleCoteCase + 3);
    int caseY = coordoneesY / (m_tailleCoteCase + 3);
    sf::Vector2i coordonnees(caseX, caseY);
    return coordonnees;
}

void Grille::caseDejaClique(std::vector<std::vector<int>> &grille, sf::Vector2i coordonnees) const {
    grille[coordonnees.y][coordonnees.x] = 1;
}

void Grille::ajoutCaseClique(sf::Vector2i coordonnees) {
    caseDejaClique(m_grilleCaseClique, coordonnees);
}
