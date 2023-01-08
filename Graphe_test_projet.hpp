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


class Graphe{
    protected:
        int n;     // nombre de sommets
	vector<std::pair<int,int>> arretes;
	vector<int> sommets;
    
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

Graphe(int nb): n(nb){
	arretes;
	sommets;
}
	





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
	protected:
	unsigned int N; //nombre de couleurs differentes du graphe
	std::vector<int> couleurs;
	std::vector<int> numerotation_init;
	
	public:
	Graphe_couleur(std::vector<int> som, std::vector< std::pair<int,int> > arr, int nb_couleurs) : Graphe(som,arr),N(nb_couleurs){		
			for(int i=0;i<n;i++){
				couleurs.push_back(-1);
			}
			} // constructeur par defaut, peut etre initialiser le map couleurs
			
	Graphe_couleur(int nb,int coul) : Graphe(nb),N(coul){}
	
	std::vector<int> operator[](int i){
	std::vector<int> res(0);
	std::vector<int> aux=sommets;
	std::vector<int> aux2(couleurs);
	// lambda fonction pour la méthode for_each
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

void coloration_init(std::vector< int > couleurs_sommets){
		for(int i=0;i<=n;i++){
				if(couleurs_sommets[i]>-1){couleurs[i]=couleurs_sommets[i];}
			}
		}

	void backtracking(){
		//std::vector<int> tab1=tab_voisin();
		//tab2=tab_color_disp();
		// sommet = ...
		// couleur = ...
		std::vector<int> liste_vide;
		for(int i=0;i<n;i++){
			if(couleurs[i]==-1){liste_vide.push_back(i);};}
		bool boo=recursive(0,0,liste_vide);


		std::cout << "l'algo renvoie" << boo << std::endl;
		;}



	bool recursive(int cont, int sommet,std::vector<int> liste_vide){ // Attention choisir avec arguments ou sans arguments (essayer sans)
	cont+=1;
std::cout << "SOMMET NUMERO :" << liste_vide[sommet] << std::endl;
if(liste_vide[sommet]>=n){std::cout << "dernier sommet" << std::endl;return true;}
//if(couleurs[sommet]>-1){std::cout << "sommet deja colorié" << std::endl;return true;}



//if(sommet>-1){std::cout << "attribution couleur" << std::endl;couleurs[sommet]=couleur;}
/*		std::vector<int> v(n,N+1);

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

*/
		  std::vector<int>::iterator git;
		  git = find(couleurs.begin(), couleurs.end(), -1);
		if( git == couleurs.end() ){std::cout << "PLUS DE SOMMET A COLORIER" << std::endl;return true;}
		// cas egalite
/*		int sommet_courant=std::distance(v.begin(),it);
		
		if(myints.size() > 1) {
			std::vector<int> cas_eg;
			for(int i=0;i<myints.size();i++){
				cas_eg.push_back(tab1[myints[i]]);}
			
			std::vector<int>::iterator eit=max_element(cas_eg.begin(),cas_eg.end());
			sommet_courant=myints[std::distance(cas_eg.begin(),eit)];
			//while(eit!=tab1.begin()+n-1){
			//eit=max_element(it+1,tab1.end());
			//myints.push_back(it);
		} */
		//sommet_courant=std::distance(tab1.begin(),eit);
		// if pour ce noeud pas de couleur disp return false

		if(nb_color_disp(liste_vide[sommet])==0){ return false;} ;		
		// ETAPE 4  (choix prochain sommet)

int col_test=0;
bool b=false;
//std::cout << "BOUCLE TEST COULEURS sur i :" << nb_color_disp(sommet_courant) << std::endl;
		for(int i=0;i<nb_color_disp(liste_vide[sommet]);i++){
		
        col_test=color_disp(liste_vide[sommet])[i];
        int som_non_col=0;
        couleurs[liste_vide[sommet]]=col_test; som_non_col=1;        /*
        int coloried=0;
        while(couleurs[sommet+coloried]>-1 && sommet+coloried < n){coloried+=1;
			        std::cout << "SOMMET NUMERO :" << sommet+coloried << "DEJA COLORIE" << std::endl;

}; */
        /*for(int j=0;j<n;j++){
			if(sommet+j>=n){break;}
			if (couleurs[sommet+j]==-1){b=recursive(cont,sommet+j,col_test);break;}
			} */
		//int i_=0;
		//while(couleurs[sommet+i_]>-1 && sommet+i_<80){ i_+=1;std::cout << "valeur i_" << i_ << std::endl;}
		b=recursive(cont,sommet+1,liste_vide);
		//b=recursive(cont,sommet+coloried,col_test);
		if(b){return true;break;}
        couleurs[liste_vide[sommet]]=-1
        ;}

        /*int col_test=0;
        int k=0;
        std::cout << "boucle de test" << std::endl;
        while(not(recursive(cont,sommet_courant,col_test)) && k<color_disp(sommet_courant).size() ){
			std::cout << "k =" << k << std::endl;
            couleurs[sommet_courant]=-1;
            col_test=color_disp(sommet_courant)[k];
            if(recursive(cont,sommet_courant,col_test)){std::cout << "UNE COULEUR MARCHE" << std::endl;return true;}
            k+=1;
        } */
        return false;}
        
bool recursive2(int cont, int sommet){ // Attention choisir avec arguments ou sans arguments (essayer sans)

coloration_init(numerotation_init);
cont+=1;
std::cout << "SOMMET NUMERO :" << sommet << std::endl;
if(sommet>=n){std::cout << "dernier sommet" << std::endl;return true;}
//if(couleurs[sommet]>-1){std::cout << "sommet deja colorié" << std::endl;return true;}



//if(sommet>-1){std::cout << "attribution couleur" << std::endl;couleurs[sommet]=couleur;}
/*		std::vector<int> v(n,N+1);

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

*/
		  std::vector<int>::iterator git;
		  git = find(couleurs.begin(), couleurs.end(), -1);
		if( git == couleurs.end() ){std::cout << "PLUS DE SOMMET A COLORIER" << std::endl;return true;}
		// cas egalite
/*		int sommet_courant=std::distance(v.begin(),it);
		
		if(myints.size() > 1) {
			std::vector<int> cas_eg;
			for(int i=0;i<myints.size();i++){
				cas_eg.push_back(tab1[myints[i]]);}
			
			std::vector<int>::iterator eit=max_element(cas_eg.begin(),cas_eg.end());
			sommet_courant=myints[std::distance(cas_eg.begin(),eit)];
			//while(eit!=tab1.begin()+n-1){
			//eit=max_element(it+1,tab1.end());
			//myints.push_back(it);
		} */
		//sommet_courant=std::distance(tab1.begin(),eit);
		// if pour ce noeud pas de couleur disp return false

		if(nb_color_disp(sommet)==0){ return false;} ;		
		// ETAPE 4  (choix prochain sommet)

int col_test=0;
bool b=false;
//std::cout << "BOUCLE TEST COULEURS sur i :" << nb_color_disp(sommet_courant) << std::endl;
		for(int i=0;i<nb_color_disp(sommet);i++){
		
        col_test=color_disp(sommet)[i];
        couleurs[sommet]=col_test;  /*
        int coloried=0;
        while(couleurs[sommet+coloried]>-1 && sommet+coloried < n){coloried+=1;
			        std::cout << "SOMMET NUMERO :" << sommet+coloried << "DEJA COLORIE" << std::endl;

}; */
        /*for(int j=0;j<n;j++){
			if(sommet+j>=n){break;}
			if (couleurs[sommet+j]==-1){b=recursive(cont,sommet+j,col_test);break;}
			} */
		//int i_=0;
		//while(couleurs[sommet+i_]>-1 && sommet+i_<80){ i_+=1;std::cout << "valeur i_" << i_ << std::endl;}
		b=recursive2(cont,sommet+1);
		//b=recursive(cont,sommet+coloried,col_test);
		if(b){return true;break;}
        couleurs[sommet]=-1
        ;}

        /*int col_test=0;
        int k=0;
        std::cout << "boucle de test" << std::endl;
        while(not(recursive(cont,sommet_courant,col_test)) && k<color_disp(sommet_courant).size() ){
			std::cout << "k =" << k << std::endl;
            couleurs[sommet_courant]=-1;
            col_test=color_disp(sommet_courant)[k];
            if(recursive(cont,sommet_courant,col_test)){std::cout << "UNE COULEUR MARCHE" << std::endl;return true;}
            k+=1;
        } */
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
		
		class Mini_sudoku : public Graphe_couleur{
		private:
		int taille;
		
		public:
		// CONVENTION : les numeros sont croissants de gauche a droite et ligne par ligne de bas en haut
		Mini_sudoku(int cote, std::vector<int> num_cases):Graphe_couleur(cote*cote,9){
		numerotation_init=num_cases;
		taille=cote;
		int nb_cases=cote*cote;
		std::vector<int> cases;
		std::vector< std::vector<int> > carres;
		std::vector< std::vector<int> > lignes;
		std::vector< std::vector<int> > colonnes;
		//std::vector<int> aux;

		for(int i=0;i<nb_cases;i++){
				cases.push_back(i);
		}
					std::vector<int> aux2({0,3,6,27,30,33,54,57,60});
		for(int i=0;i<cote;i++){
			std::vector<int> aux;
			int a=aux2[i];
			aux.push_back(a);
			aux.push_back(a+1);
			aux.push_back(a+2);
			aux.push_back(a+9);
						aux.push_back(a+10);
									aux.push_back(a+11);
												aux.push_back(a+18);
			aux.push_back(a+19);
			aux.push_back(a+20);
			carres.push_back(aux);
			}
		
		for(int i=0;i<cote;i++){
			std::vector<int> aux;
			aux.push_back(i*9);
			aux.push_back(9*i+1);
			aux.push_back(9*i+2);
			aux.push_back(9*i+3);
			aux.push_back(9*i+4);
			aux.push_back(9*i+5);
			aux.push_back(9*i+6);
			aux.push_back(9*i+7);
			aux.push_back(9*i+8);
			lignes.push_back(aux);
			}
		for(int i=0;i<cote;i++){
			std::vector<int> aux;
			aux.push_back(i);
			aux.push_back(i+9);
			aux.push_back(i+18);
			aux.push_back(i+27);
			aux.push_back(i+36);
			aux.push_back(i+45);
			aux.push_back(i+54);
			aux.push_back(i+63);
			aux.push_back(i+72);
			colonnes.push_back(aux);
			}
	
		
		
			
		std::vector< std::pair<int,int> > arr;
		int numero_ligne=-1;
		int numero_colonne=-1;
		for(int i=0;i<nb_cases;i++){
			if((i+9)%9==0){numero_ligne+=1;}
			if((i+9)%9==0){numero_colonne=0;}
			if((i+9)%9==2){numero_colonne=2;}
			if((i+9)%9==1){numero_colonne=1;}
			if((i+9)%9==3){numero_colonne=3;}
			if((i+9)%9==4){numero_colonne=4;}
			if((i+9)%9==5){numero_colonne=5;}
			if((i+9)%9==6){numero_colonne=6;}
			if((i+9)%9==7){numero_colonne=7;}
			if((i+9)%9==8){numero_colonne=8;}
			
			//std::cout << "SOMMET NUMERO :" << i << std::endl;
			//			std::cout << "COLONNE NUMERO :" << numero_colonne << std::endl;

			
		
			//trouver le carre de cette case
			std::vector<int>::iterator git;
			int k=0;
			git = find(carres[k].begin(), carres[k].end(), i);
			while(git == carres[k].end()){
				k+=1;
			    git = find(carres[k].begin(), carres[k].end(), i);}		    
		    //arretes de la case
		    for(int j=0;j<9;j++){
				if(existe_arrete(i,(carres[k])[j])==false){
									if(existe_arrete((carres[k])[j],i)==false){
				std::pair <int,int> arr_aux(i,(carres[k])[j]);
				arretes.push_back(arr_aux);}
			}
			}
			
			//arretes de ligne et colonne
			for(int j=0;j<9;j++){
				
				if(existe_arrete(i,i+j)==false && i+j<81 && i+j >-1 ){
					if(find(lignes[numero_ligne].begin(), lignes[numero_ligne].end(), i+j)!=lignes[numero_ligne].end()){
				std::pair <int,int> arr_aux(i,i+j);
				arretes.push_back(arr_aux);
			    }
			    }
			    if(existe_arrete(i,i-j)==false && i-j<81 && i-j >-1){
					if(find(lignes[numero_ligne].begin(), lignes[numero_ligne].end(), i-j)!=lignes[numero_ligne].end()){
				std::pair <int,int> arr_aux(i,i-j);
				arretes.push_back(arr_aux);
			    }
			    }
				if(existe_arrete(i,i+j*9)==false && i+j*9<81 && i+j*9 >-1){
					if(find(colonnes[numero_colonne].begin(), colonnes[numero_colonne].end(), i+j*9)!=colonnes[numero_colonne].end()){
				std::pair <int,int> arr_aux(i,i+j*9);
				arretes.push_back(arr_aux);
			}
		    }
				if(existe_arrete(i,i-j*9)==false && i-j*9<81 && i-j*9 >-1){
					if(find(colonnes[numero_colonne].begin(), colonnes[numero_colonne].end(), i-j*9)!=colonnes[numero_colonne].end()){
				std::pair <int,int> arr_aux(i,i-j*9);
				arretes.push_back(arr_aux);
			}
		    }
			}
			// fin creation arrete
			}
			
		//Graphe_couleur(cases,arr,4);
		
		//arretes=arr;
		sommets=cases;
		for(int i=0;i<nb_cases;i++){
				couleurs.push_back(num_cases[i]);
			}
		
		
			
		}
			
			
	
		bool existe_arrete(int i,int j){
			if(i==j){return true;}
			    int res=0;
	auto function=[i,j,&res](std::pair<int,int> k){
	if(k.first==i && k.second==j){res=res+1;}
		if(k.first==j && k.second==i){res=res+1;}
		;} ;

	/*auto function=[i,j,&res](std::pair<int,int> k){
	if(k.first==i){
		if(k.second==j){res+=1;} ;}
	if(k.second==i){
		if(k.first==j){res+=1;} ;}   ;} ; */
	std::for_each(arretes.begin(),arretes.end(), function);
	if(res>0){return true;}
	return false;}
	
		    void affichage_sudoku(){
			std::vector<int> aux({0,9,18,27,36,45,54,63,72});
			for(int j=0;j<9;j++){
				int i=aux[j];
			std::cout << couleurs[i] +1 << "|" << couleurs[i+1]+1 << "|" << couleurs[i+2]+1 << "|" << couleurs[i+3]+1 << 
			"|" << couleurs[i+4]+1 << "|" << couleurs[i+5]+1 << "|" << couleurs[i+6]+1 << "|" << couleurs[i+7]+1 << "|" << couleurs[i+8]+1 << std::endl;}
		}
		
				    void affichage_couleurs(){ // a modifier
					std::vector<int> aux=couleurs;
				for(int j=0;j<aux.size();j++){
								std::cout << "couleurs dispo :" << couleurs[j] << std::endl;}
		}
	
		};
		
    
		
		// void operator << (std::iostream &){}
		





#endif
