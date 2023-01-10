#include <math.h>
#include <cassert>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <numeric>

#ifndef GRAPHE
#define GRAPHE

using namespace std;

class Graphe{
	protected:
		int n;     // nombre de sommets
		vector<pair<int,int>> arretes;
		vector<int> sommets;
    
	public:
	// constructeurs

		Graphe(int nb): n(nb){}

		Graphe(vector<int> som, vector<pair<int,int>> arr) : n(som.size()), arretes(arr),sommets(som){}

		Graphe(vector< vector<int> > pair_sommet);

		// méthodes 
		virtual vector<int> operator[](int i);

		vector<int> liste_sommets() const {return sommets;}
			
		vector<pair<int,int>> liste_arretes() const {return arretes;}
};

class Graphe_couleur : public Graphe{
	protected:
		unsigned int N; //nombre de couleurs differentes du graphe
		vector<int> couleurs;
		vector<int> numerotation_init;
	
	public:
		// constructeurs
		Graphe_couleur(vector<int> som, vector< pair<int,int> > arr, int nb_couleurs) : Graphe(som,arr),N(nb_couleurs){		
			for(int i=0;i<n;i++){
				couleurs.push_back(-1);
			}
		} // constructeur par defaut, peut etre initialiser le map couleurs
			
		Graphe_couleur(int nb,int coul) : Graphe(nb),N(coul){}
	
		// méthodes
		vector<int> operator[](int i);
	
		int nb_voisins(int i);
	
		int nb_color_disp(int i);

		vector<int> color_disp(int i);
	
		vector<int> tab_voisin();
	
		map< int, int > tab_color_disp();
	
		void coloration(vector< int > couleurs_sommets);
		
		vector<int> liste_voisins(int i);

		void coloration_init(vector< int > couleurs_sommets);

		void backtracking();

		bool recursive(int cont, int sommet,vector<int> liste_vide);

		bool recursive2(int cont, int sommet);
};
#endif
