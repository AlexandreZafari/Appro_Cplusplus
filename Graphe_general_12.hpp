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
	std::vector<int> couleurs;
	
	public:
	Graphe_couleur(std::vector<int> som, std::vector< std::pair<int,int> > arr, int N) : Graphe(som,arr){		
			for(int i=0;i<=n;i++){
				couleurs.push_back(-1);
			}
			} // constructeur par defaut, peut etre initialiser le map couleurs
	
	void operator[](int i){
	std::vector<int> aux=sommets;
	std::vector<int> aux2(couleurs);
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
		int res=0;
		std::vector<int> aux=sommets;
		auto function=[i,aux,&res](std::pair<int,int> k){
	if(k.first==aux[i]){
		res+=1;}
	else if (k.second==aux[i]){
        res+=1;}
	};
	std::for_each(arretes.begin(),arretes.end(), function);
	return res;}
	
	int nb_color_disp(int i){ // a modifier
		int res=N;
		std::vector<int> aux2=couleurs;
		std::vector<int> aux=sommets;
		auto function=[i,aux, aux2, &res](std::pair<int,int> k){
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
      ;};
	std::for_each(arretes.begin(),arretes.end(), function);
	return res;}
	
	std::vector<int> color_disp(int i){
		std::vector<int> aux2(N);
		std::iota ( std::begin(aux2),std::end(aux2),0 );
		std::vector<int> aux=sommets;
		std::vector<int> aux3=couleurs;
		auto function=[i,aux,&aux2,aux3](std::pair<int,int> k){
	if(k.first==aux[i]){
		if(std::find(aux2.begin(),aux2.end(),aux3[k.second])!=aux2.end()){
			std::remove(aux2.begin(),aux2.end(),aux3[k.second]);
		}
			;}
	else if (k.second==aux[i]){
        if(std::find(aux2.begin(),aux2.end(),aux3[k.first])!=aux2.end()){
			std::remove(aux2.begin(),aux2.end(),aux3[k.first]);
		}
		;}
      ;};
	std::for_each(arretes.begin(),arretes.end(), function);
	return aux2;}
	
	std::vector<int> tab_voisin(){
		std::vector<int> res(n);
		for(int i=0;i<n;i++){
			res[i]=nb_voisins(i);
		}
	return res;}
	
	std::map< int, int > tab_color_disp(){
		std::map< int, int > res;
		for(int i=0;i<n;i++){
			res[i]=nb_color_disp(i);
		}
	return res;}
	
	
	void coloration(std::vector< std::pair<int,int> > couleurs_sommets, int nb_couleurs){
		N=nb_couleurs;
		for(int i=0;i<=n;i++){
				couleurs[i]=couleurs_sommets[i].second;
			}
		}
		
	// choisir soit constr ou method coloration, avancer sur algo backtracking (15-20 lignes) pour sem pro
	
	void backtracking(){
		//std::vector<int> tab1=tab_voisin();
		//tab2=tab_color_disp();
		// sommet = ...
		// couleur = ...
		bool boo=recursive();
		std::cout << "l'algo renvoie" << boo << std::endl;
		;}
		
	bool recursive( ){ // Attention choisir avec arguments ou sans arguments (essayer sans)
				std::cout<< "debut" << std::endl;

		std::vector<int> v(0);
				std::cout<< "tab voisin" << std::endl;

		std::vector<int> tab1=tab_voisin();
		std::cout<< "boucle for" << std::endl;

		for(int i=0;i<n;i++){
			if(couleurs[i]==-1){
			    v.push_back(nb_color_disp(i));}
		}
		
				std::cout<< "iterator" << std::endl;

		std::vector<int>::iterator it=min_element(v.begin(),v.end());
		std::vector<std::vector<int>::iterator> myints(0);
				std::cout<< "etape 4" << std::endl;
		while(it!=v.end()){
			it=min_element(it,v.end());
			myints.push_back(it);
		}
		
		// if pas de noeud non coloré return true
		
		if( std::find(couleurs.begin(), couleurs.end(),-1) != couleurs.end() ){ return true;}
		
		// cas egalite
		
		std::cout<< "cas egalite" << std::endl;

		
		if(myints.size() > 1) {
			it=max_element(it,tab1.end());
			while(it!=tab1.end()){
			it=max_element(it,tab1.end());
			myints.push_back(it);
		}
		}
		
		int sommet_courant=std::distance(tab1.begin(),it);
		// if pour ce noeud pas de couleur disp return false
		
		if(nb_color_disp(sommet_courant)==0){ return false;} ;
		std::cout<< "avant etape 4" << std::endl;
		
		std::cout<< "etape 4" << std::endl;
		
		// ETAPE 4  (choix prochain sommet)
		std::cout << "boucle" << std::endl;
		//for(int i=0;i<nb_color_disp(sommet_courant);i++){}
			
				std::cout << "boucle" << std::endl;

			
		// bool b=recursive();
		//bool b=true;
		//if(b){return true;}
		//int couleur=color_disp(sommet_courant)[0];
		//couleurs[sommet_courant]=couleur;
		return false;}
		
		
		// manipuler les couleurs a certain moment
		/*bool b=recursive();
		if(b){ return true;}
		else{ // On teste avec les autres couleurs disponibles
			for (int i=0;i<nb_color_disp(sommet_courant);i++){
				b=recursive();
				if(b){ return true;}
			}
			return false;} */
			
		// ETAPE 5 voir si premier appel de recursive est false ou true  
		};
		





#endif
