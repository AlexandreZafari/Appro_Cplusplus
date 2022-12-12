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





	virtual std::vector<int> operator[](int i){
	std::vector<int> aux=sommets;
	auto function=[i,aux](std::pair<int,int> k){
	if(k.first==aux[i]){
		std::cout << k.first << "--" << k.second << std::endl;}
	else if (k.second==aux[i]){
		std::cout << k.second << "--" << k.first << std::endl;}
	};
	std::for_each(arretes.begin(),arretes.end(), function);
	return aux;}
	
	
		
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
	Graphe_couleur(std::vector<int> som, std::vector< std::pair<int,int> > arr, int nb_couleurs) : Graphe(som,arr),N(nb_couleurs){		
			for(int i=0;i<n;i++){
				couleurs.push_back(-1);
			}
			} // constructeur par defaut, peut etre initialiser le map couleurs
	
	std::vector<int> operator[](int i){
	std::vector<int> res(0);
	std::vector<int> aux=sommets;
	std::vector<int> aux2(couleurs);
	auto function=[i,aux, &aux2,&res](std::pair<int,int> k){
	if(k.first==aux[i]){
		std::cout << k.first << "--" << k.second << "[" << aux2[k.second] << "]" << std::endl;
		res.push_back(k.second);}
	else if (k.second==aux[i]){
		std::cout << k.second << "--" << k.first << "[" << aux2[k.first] << "]"<< std::endl;
		res.push_back(k.first);}
	};
	std::for_each(arretes.begin(),arretes.end(), function);
	int col=couleurs[i];
	std::cout << "color :" << col << std::endl;
	return res;
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
	
    int nb_color_disp(int i){
		std::vector<int> aux=color_disp(i);
		int res=aux.size();
		return res;}

	/*int nb_color_disp(int i){ // a modifier
		int res=N;
		std::cout << "colordisp" << std::endl;
		std::vector<int> aux2=color_disp(i);
		std::vector<int> aux=sommets;
		auto function=[i,aux, aux2, &res](std::pair<int,int> k){
	if(k.first==aux[i]){
		if(std::find(aux2.begin(),aux2.end(),aux2[k.second])!=aux2.end()){
			res+=-1;
		}
			;}
	else if (k.second==aux[i]){
        if(std::find(aux2.begin(),aux2.end(),aux2[k.first])!=aux2.end()){
			res+=-1;
		}
		;}
      ;};
	std::for_each(arretes.begin(),arretes.end(), function);
	return res;} */
	
	std::vector<int> color_disp(int i){
	std::vector<int> res(0);
	std::vector<int> aux=sommets;
	std::vector<int> aux2(couleurs);
	auto function=[i,aux, &aux2,&res](std::pair<int,int> k){
	if(k.first==aux[i]){
		res.push_back(k.second);}
	else if (k.second==aux[i]){
		res.push_back(k.first);}
	};
	std::for_each(arretes.begin(),arretes.end(), function);

	std::vector<int> aux4(N);
		std::iota(aux4.begin(), aux4.end(), 0);
		std::vector<int> aux3=couleurs;
		int M=res.size();

		for(int k=0;k<M;k++){
			if(couleurs[res[k]]!=-1){
				aux4.erase(std::remove(aux4.begin(), aux4.end(), couleurs[res[k]]), aux4.end());

		;}
		;}

		/*
		auto function=[i,&aux2,aux3](std::pair<int,int> k){
	if(k.first==i){
		if(std::find(aux2.begin(),aux2.end(),aux3[k.second])!=aux2.end()){
			std::remove(aux2.begin(),aux2.end(),aux3[k.second]);
		}
			;}
	else if (k.second==i){
        if(std::find(aux2.begin(),aux2.end(),aux3[k.first])!=aux2.end()){
			std::remove(aux2.begin(),aux2.end(),aux3[k.first]);
		}
		;}
        std::cout << "couleurs disp etape k" << aux2.size() << std::endl; } ;
	std::for_each(arretes.begin(),arretes.end(), function); */

    // probleme sur color_disp, fait une erreur segmentation et n'affiche pas les bonnes valeurs de couleur, ni de nb couleurs dispos

	return aux4;}
	
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
	
	
	void coloration(std::vector< int > couleurs_sommets){
		for(int i=0;i<=n;i++){
				couleurs[i]=couleurs_sommets[i];
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

std::cout << "DEBUT RECURS" << std::endl;
std::cout << "              " << std::endl;
std::cout << "              " << std::endl;
		std::vector<int> v;

		std::vector<int> tab1=tab_voisin();

		for(int i=0;i<n;i++){
			    v.push_back(nb_color_disp(i));
			std::cout << v[i] << std::endl; }



		std::vector<int>::iterator it=min_element(v.begin(),v.end());
		std::vector<std::vector<int>::iterator> myints(0);
		//while(it!=v.end()){
		//	it=min_element(it,v.end());
		//	myints.push_back(it);
		//}
		
		// if pas de noeud non coloré return true


		  std::vector<int>::iterator git;
		  git = find(couleurs.begin(), couleurs.end(), -1);
		if( git != couleurs.end() ){ std::cout << *git << " (-1) dans les couleurs" << std::distance(couleurs.begin(),git) << std::endl;
		 std::cout << couleurs[2] << std::endl;}
		else{return true;}
		// cas egalite
		int sommet_courant=std::distance(v.begin(),it);
		
		if(myints.size() > 1) {
			std::cout<< "cas egalite" << std::endl;
			it=max_element(it,tab1.end());
			while(it!=tab1.end()){
			it=max_element(it,tab1.end());
			myints.push_back(it);
		}
		int sommet_courant=std::distance(tab1.begin(),it);
		}
		// if pour ce noeud pas de couleur disp return false

		if(nb_color_disp(sommet_courant)==0){ return false;} ;		
		// ETAPE 4  (choix prochain sommet)

		int couleur=color_disp(sommet_courant)[0];
		couleurs[sommet_courant]=couleur;

		std::cout<< "numero sommet " << sommet_courant << std::endl;

		std::cout<< "COULEURS DES DEUX " << couleurs[0] << couleurs[1] << std::endl;




		for(int i=1;i<nb_color_disp(sommet_courant);i++){
		bool b=recursive();
		if(b){return true;}
		int couleur=color_disp(sommet_courant)[i];
		couleurs[sommet_courant]=couleur;}
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
