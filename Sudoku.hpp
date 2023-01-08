#pragma once

#include "Graphe_couleur.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

class Sudoku : public Graphe_couleur{
    private:
        // Argument taille du Sudoku :  
        int taille;
    public:
        // Constructeur : permet d'initialiser/construire la grille du Sudoku
        Sudoku(int cote, vector<int> num_cases): ;
        
        // Méthode : permet d'afficher la Grille remplie ou pas du Sudoku
        void affichage_sudoku();
        void affichage_couleurs();
};
