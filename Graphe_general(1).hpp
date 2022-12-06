#include <math.h>
#include <cassert>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

#ifndef GRAPHE
#define GRAPHE


class Graphe
{
protected:
    int n;     // nombre de sommets
    std::vector<std::pair<int,int>> arretes;
    std::vector<int> sommets;
    
public:


Graphe(std::vector<int> som, std::vector<std::pair<int,int>> arr) : n(som.size()), sommets(som), arretes(arr){}

Graphe(std::vector< std::vector<int> > pair_sommet){
	int nb_arretes=pair_sommet.size();
	std::vector<std::pair<int,int>> arretes(0);
	std::set<int> myset;
	for(int i=0;i<nb_arretes;i++){
		myset.insert(pair_sommet[i][1]);
		myset.insert(pair_sommet[i][0]);
				std::pair <int,int> a(pair_sommet[i][0],pair_sommet[i][1]);
		arretes.push_back(a);
	}
	std::vector<int> sommets(0);
for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it){
    sommets.push_back(42);}
} // a debug





	virtual void operator[](int i){
	std::vector<int> aux=sommets;
	auto function=[i,aux](std::pair<int,int> k){
	if(k.first==aux[i]){
		std::cout << k.first << "--" << k.second << std::endl;}
	else if (k.second==aux[i]){
		std::cout << k.second << "--" << k.first << std::endl;}
	};
	std::for_each(arretes.begin(),arretes.end(), function);}
	
	
		
	std::vector<int> liste_sommets() const {
		return sommets;}
		
	std::vector<std::pair<int,int>> liste_arretes() const {
		return arretes;}
    

};

class Graphe_couleur : public Graphe{
	private:
	unsigned int N; //nombre de couleurs differentes du graphe
	std::map<int,int> couleurs;
	
	public:
	Graphe_couleur(std::vector<int> som, std::vector< std::pair<int,int> > arr, int N) : Graphe(som,arr){		
			for(int i=0;i<=n;i++){
				couleurs[i]=-1;
			}
			} // constructeur par defaut, peut etre initialiser le map couleurs
	
	void operator[](int i){
	std::vector<int> aux=sommets;
	std::map<int,int> aux2(couleurs);
	auto function=[i,aux, &aux2](std::pair<int,int> k){
	if(k.first==aux[i]){
		std::cout << k.first << "--" << k.second << "[" << aux2[k.second] << "]" << std::endl;}
	else if (k.second==aux[i]){
		std::cout << k.second << "--" << k.first << "[" << aux2[k.first] << "]"<< std::endl;}
	};
	std::for_each(arretes.begin(),arretes.end(), function);
	int res=couleurs[i];
	std::cout << "color :" << res << std::endl;
	}
	
	int nb_voisins(int i){
		res=0;
		std::vector<int> aux=sommets;
		auto function=[i,aux](std::pair<int,int> k){
	if(k.first==aux[i]){
		res+=1;}
	else if (k.second==aux[i]){
        res+=1;}
	};
	std::for_each(arretes.begin(),arretes.end(), function);
	return res;}
	
	int nb_color_disp(int i){
		res=N;
		std::vector<int> aux2;
		std::vector<int> aux=sommets;
		auto function=[i,aux](std::pair<int,int> k){
	if(k.first==aux[i]){
		if(std::find(aux2.begin(),aux2.end(),k.second)!=aux2.end()){
			res+=-1;
		}
			;}
	else if (k.second==aux[i]){
        if(std::find(aux2.begin(),aux2.end(),k.first)!=aux2.end()){
			res+=-1;
		}
		;}
      ;}
	std::for_each(arretes.begin(),arretes.end(), function);
	return res;}
	
	std::vector<int> color_disp(int i){
		res=N;
		std::vector<int> aux2(N);
		std::iota ( std::begin(aux2),std::end(aux2),0 );
		std::vector<int> aux=sommets;
		auto function=[i,aux](std::pair<int,int> k){
	if(k.first==aux[i]){
		if(std::find(aux2.begin(),aux2.end(),k.second)!=aux2.end()){
			res+=-1;
		}
			;}
	else if (k.second==aux[i]){
        if(std::find(aux2.begin(),aux2.end(),k.first)!=aux2.end()){
			res+=-1;
		}
		;}
      ;}
	std::for_each(arretes.begin(),arretes.end(), function);
	return res;}
	
	
	
		
	
	
	void coloration(std::vector< std::pair<int,int> > couleurs_sommets, int nb_couleurs){
		N=nb_couleurs;
		for(int i=0;i<=n;i++){
				couleurs[i]=couleurs_sommets[i].second;
			}
		}
		
		
	
	
	
	
	// choisir soit constr ou method coloration, avancer sur algo backtracking (15-20 lignes) pour sem pro
	
	
};





#endif
