#include "Sudoku.hpp"

class Sudoku: public Graphe_couleur{
		private:
            int taille;
		
		public:
		// CONVENTION : les numeros sont croissants de gauche a droite et ligne par ligne de bas en haut
		    Sudoku(int cote, std::vector<int> num_cases):Graphe_couleur(cote*cote,9){
		        numerotation_init=num_cases;
		        taille=cote;
		        int nb_cases=cote*cote;
		        vector<int> cases;
		        vector< vector<int> > bloc;
		        vector< vector<int> > lignes;
		        vector< vector<int> > colonnes;

		        for(int i=0;i<nb_cases;i++){
				    cases.push_back(i);
		        }
					
                vector<int> aux2({0,3,6,27,30,33,54,57,60});
		            for(int i=0;i<cote;i++){
			            vector<int> aux;
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
                        bloc.push_back(aux);
                    }
		
                    for(int i=0;i<cote;i++){
                        vector<int> aux;
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
                        vector<int> aux;
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
	
		
		
			
                vector< std::pair<int,int> > arr;
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
                vector<int>::iterator git;
                int k=0;
                git = find(bloc[k].begin(), bloc[k].end(), i);
                
                while(git == bloc[k].end()){
                    k+=1;
                    git = find(bloc[k].begin(), bloc[k].end(), i);
                }	

                //arretes de la case
                for(int j=0;j<9;j++){
                    
                    if(existe_arrete(i,(bloc[k])[j])==false){
                                        if(existe_arrete((bloc[k])[j],i)==false){
                    std::pair <int,int> arr_aux(i,(bloc[k])[j]);
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
                ;}
                std::for_each(arretes.begin(),arretes.end(), function);
                if(res>0){return true;}
                return false;
            }	
};

void Sudoku::affichage_sudoku(){
	vector<int> aux({0,9,18,27,36,45,54,63,72});
	for(int j=0;j<9;j++){
		int i=aux[j];
		cout << couleurs[i] +1 << "|" << couleurs[i+1]+1 << "|" << couleurs[i+2]+1 << "|" << couleurs[i+3]+1 << "|" << couleurs[i+4]+1 << "|" << couleurs[i+5]+1 << "|" << couleurs[i+6]+1 << "|" << couleurs[i+7]+1 << "|" << couleurs[i+8]+1 << endl;
    }
}


void Sudoku::affichage_couleurs(){
    vector<int> aux=couleurs;
    for(int j=0;j<aux.size();j++){
        cout << "couleurs dispo :" << couleurs[j] << endl;
    }
}