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
	// Constructeurs

	Graphe(vector<int> som, vector<pair<int,int>> arr) : n(som.size()), sommets(som), arretes(arr){}

	Graphe(vector< vector<int> > pair_sommet){
		int nb_arretes=pair_sommet.size();

		vector<pair<int,int>> arretes(0);
		set<int> myset;

		for(int i=0;i<nb_arretes;i++)
		{
			myset.insert(pair_sommet[i][1]);
			myset.insert(pair_sommet[i][0]);
				pair <int,int> a(pair_sommet[i][0],pair_sommet[i][1]);
			arretes.push_back(a);
		}

		vector<int> sommets(0);

		for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		{
			sommets.push_back(42);
		}
	} 

	Graphe(int nb): n(nb){
		arretes;
		sommets;
	}

	virtual vector<int> operator[](int i){
		vector<int> aux=sommets;
		
		auto function=[i,aux](pair<int,int> k){
			if(k.first==aux[i])
			{
				cout << k.first << "--" << k.second << endl;
			}
			else if (k.second==aux[i])
			{
				cout << k.second << "--" << k.first << endl;
			}
    	};

		for_each(arretes.begin(),arretes.end(), function);
		
		return aux;
	}

	vector<int> liste_sommets() const {return sommets;}
		
	vector<pair<int,int>> liste_arretes() const {return arretes;}
};

class Graphe_couleur : public Graphe{
	protected:
		unsigned int N; //nombre de couleurs differentes du graphe
		vector<int> couleurs;
		vector<int> numerotation_init;
	
	public:
		Graphe_couleur(vector<int> som, vector< pair<int,int> > arr, int nb_couleurs) : Graphe(som,arr),N(nb_couleurs){		
			for(int i=0;i<n;i++){
				couleurs.push_back(-1);
			}
		} // constructeur par defaut, peut etre initialiser le map couleurs
			
		Graphe_couleur(int nb,int coul) : Graphe(nb),N(coul){}
	
		vector<int> Graphe_couleur::operator[](int i);
	
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
