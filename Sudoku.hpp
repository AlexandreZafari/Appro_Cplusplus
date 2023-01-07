#pragma once

#include "Graphe_colore.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <string>

using namespace std;



class Sudoku : public Graphe_colore{
    private:
        // Argument Grill du Sudoku : vecteur contenant des vecteurs d'entiers = matrice 
        vector<vector<int> > Grille;
    public:
        // Constructeur : permet d'initialiser/construire la grille du Sudoku
        Sudoku(vector<vector<int> >);
        
        // Méthode : permet d'afficher la Grille remplie ou pas du Sudoku
        void Affichage_Grille();
};
