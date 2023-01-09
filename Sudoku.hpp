#pragma once

#include "Graphe.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

class Sudoku:public Graphe_couleur{
    private:
        // Argument taille du Sudoku :  
        int taille;
    public:
        // Constructeur : permet d'initialiser/construire la grille du Sudoku
		// CONVENTION : les numeros sont croissants de gauche a droite et ligne par ligne de bas en haut
        Sudoku(int cote, vector<int> num_cases);// Fin du constructeur 
        
        // Vérifie si l'arrête existe
        bool existe_arrete(int i,int j);

        // Méthode : permet d'afficher la Grille remplie ou pas du Sudoku
        void affichage_sudoku();
        void affichage_couleurs();
};