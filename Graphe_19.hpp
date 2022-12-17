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

    std::vector<int> liste_voisins(int i){
    std::vector<int> res;
	std::vector<int> aux=sommets;
	auto function=[i,aux,&res](std::pair<int,int> k){
	if(k.first==aux[i]){
		res.push_back(k.second);}
	else if (k.second==aux[i]){
		res.push_back(k.first);}
	};
	std::for_each(arretes.begin(),arretes.end(), function);
    return res;
    }
		
	// choisir soit constr ou method coloration, avancer sur algo backtracking (15-20 lignes) pour sem pro
	
/// VERSION AVEC ARGUMENTS



	void backtracking(){
		//std::vector<int> tab1=tab_voisin();
		//tab2=tab_color_disp();
		// sommet = ...
		// couleur = ...
		bool boo=recursive(0,-1,-1);


		std::cout << "l'algo renvoie" << boo << std::endl;
		;}
		
	bool recursive(int cont, int sommet, int couleur){ // Attention choisir avec arguments ou sans arguments (essayer sans)
  std::cout << "iteration :" << cont << std::endl;
	cont+=1;
std::cout << "DEBUT RECURS" << std::endl;
std::cout << "              " << std::endl;
std::cout << "              " << std::endl;

if(sommet>-1){couleurs[sommet]=couleur;}
		std::vector<int> v(n,N+1);

		std::vector<int> tab1=tab_voisin();

		for(int i=0;i<n;i++){
			if(couleurs[i]==-1){
			    v[i]=nb_color_disp(i); }
			;}



		std::vector<int>::iterator it=min_element(v.begin(),v.end());
    int val_debut = *it;
		std::vector<int> myints;
		myints.push_back(std::distance(v.begin(),it));		
		while(it!=v.begin()+n-1 && *it==val_debut){
		it=min_element(it+1,v.end());
    if(*it!=val_debut){break;}
		myints.push_back(std::distance(v.begin(),it));
		}
		// if pas de noeud non coloré return true


		  std::vector<int>::iterator git;
		  git = find(couleurs.begin(), couleurs.end(), -1);
		if( git == couleurs.end() ){std::cout << "PLUS DE SOMMET A COLORIER" << std::endl;return true;}
		// cas egalite
		int sommet_courant=std::distance(v.begin(),it);
		
		if(myints.size() > 1) {
			std::vector<int> cas_eg;
			for(int i=0;i<myints.size();i++){
				cas_eg.push_back(tab1[myints[i]]);}
			
			std::vector<int>::iterator eit=max_element(cas_eg.begin(),cas_eg.end());
			sommet_courant=myints[std::distance(cas_eg.begin(),eit)];
			//while(eit!=tab1.begin()+n-1){
			//eit=max_element(it+1,tab1.end());
			//myints.push_back(it);
		}
		//sommet_courant=std::distance(tab1.begin(),eit);
		// if pour ce noeud pas de couleur disp return false

		if(nb_color_disp(sommet_courant)==0){ std::cout << "PAS DE COULEURS DISP" << std::endl; return false;} ;		
		// ETAPE 4  (choix prochain sommet)

/*
		for(int i=0;i<nb_color_disp(sommet_courant);i++){
        int col_test=color_disp(sommet_courant)[i];
		bool b=recursive(cont,sommet_courant,col_test);
		if(b){return true;}
        if(not b){couleurs[sommet_courant]==-1;}
        ;}
		return false;} */

        int col_test=0;
        int k=0;
        bool b=false;
        while(b==false){
            couleurs[sommet_courant]==-1;
            col_test=color_disp(sommet_courant)[k];
            b=recursive(cont,sommet_courant,col_test);
            if(b==true){std::cout << "UNE COULEUR MARCHE" << std::endl;return true;}
            k+=1;
        }
        if(k==color_disp(sommet_courant).size()-1){std::cout << "TOUTES COULEURS TESTEES AUCUNE NE MARCHE" << std::endl;return false;}

    }
		
		
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