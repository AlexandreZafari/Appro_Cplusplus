#include "Graphe.hpp"

//constructeur par vector
Graphe::Graphe(vector< vector<int> > pair_sommet){
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

//opérateur pour accéder
vector<int> Graphe::operator[](int i){
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

// Méthodes de la classe Graphe_couleur

vector<int> Graphe_couleur::operator[](int i){
    vector<int> res(0);
    vector<int> aux=sommets;
    vector<int> aux2(couleurs);

    // lambda fonction pour la méthode for_each
    auto function=[i,aux, &aux2,&res](pair<int,int> k){
        if(k.first==aux[i])
        {
            cout << k.first << "--" << k.second << "[" << aux2[k.second] << "]" << endl;
            res.push_back(k.second);
        }
        else if (k.second==aux[i])
        {
            cout << k.second << "--" << k.first << "[" << aux2[k.first] << "]"<< endl;
            res.push_back(k.first);
        }
    };
    
    for_each(arretes.begin(),arretes.end(), function);
    int col=couleurs[i];
    cout << "color :" << col << endl;
    return res;
}

int Graphe_couleur::nb_voisins(int i){
    int res=0;
    vector<int> aux=sommets;
    auto function=[i,aux,&res](pair<int,int> k){
        if(k.first==aux[i])
        {
            res+=1;
            }
        else if (k.second==aux[i])
        {
            res+=1;}
    };
    for_each(arretes.begin(),arretes.end(), function);
    return res;
}

int Graphe_couleur::nb_color_disp(int i){
    vector<int> aux=color_disp(i);
    int res=aux.size();
    return res;
}

vector<int> Graphe_couleur::color_disp(int i){
    vector<int> res(0);
    vector<int> aux=sommets;
    vector<int> aux2(couleurs);

    auto function=[i,aux, &aux2,&res](pair<int,int> k){
        if(k.first==aux[i]){
            res.push_back(k.second);}
        else if (k.second==aux[i]){
            res.push_back(k.first);}
    };

    for_each(arretes.begin(),arretes.end(), function);

    vector<int> aux4(N);
        iota(aux4.begin(), aux4.end(), 0);
        vector<int> aux3=couleurs;
        int M=res.size();

        for(int k=0;k<M;k++){
            if(couleurs[res[k]]!=-1)
            {
                aux4.erase(remove(aux4.begin(), aux4.end(), couleurs[res[k]]), aux4.end());
            }
        }
    return aux4;
}

vector<int> Graphe_couleur::tab_voisin(){
    vector<int> res(n);
    for(int i=0;i<n;i++)
    {
        res[i]=nb_voisins(i);
    }
    return res;
}

map< int, int > Graphe_couleur::tab_color_disp(){
    map< int, int > res;
    for(int i=0;i<n;i++)
    {
        res[i]=nb_color_disp(i);
    }
    return res;
}

void Graphe_couleur::coloration(vector< int > couleurs_sommets){
    for(int i=0;i<=n;i++){
            couleurs[i]=couleurs_sommets[i];
    }
}

vector<int> Graphe_couleur::liste_voisins(int i){
    vector<int> res;
    vector<int> aux=sommets;
    auto function=[i,aux,&res](pair<int,int> k){
        if(k.first==aux[i])
        {
            res.push_back(k.second);
        }
        else if (k.second==aux[i])
        {
            res.push_back(k.first);
        }
    };
    for_each(arretes.begin(),arretes.end(), function);
    return res;
}

void Graphe_couleur::coloration_init(vector< int > couleurs_sommets){
    for(int i=0;i<=n;i++)
    {
        if(couleurs_sommets[i]>-1)
        {
            couleurs[i]=couleurs_sommets[i];
        }
    }
}

void Graphe_couleur::backtracking(){
    vector<int> liste_vide;
    for(int i=0;i<n;i++)
    {
        if(couleurs[i]==-1)
        {
            liste_vide.push_back(i);
        }
    }
    bool boo=recursive(0,0,liste_vide);

    cout << "l'algo renvoie" << boo << endl;   
}



bool Graphe_couleur::recursive(int cont, int sommet,vector<int> liste_vide){ // Attention choisir avec arguments ou sans arguments (essayer sans)
    cont+=1;
    
    cout << "SOMMET NUMERO :" << liste_vide[sommet] << endl;
    
    if(liste_vide[sommet]>=n)
    {
        cout << "dernier sommet" << endl;return true;
    }

    vector<int>::iterator git;
    
    git = find(couleurs.begin(), couleurs.end(), -1);
    
    if( git == couleurs.end() )
    {
        cout << "PLUS DE SOMMET A COLORIER" << endl;return true;
    }
    
    // cas egalite
    if(nb_color_disp(liste_vide[sommet])==0)
    { 
        return false;
    }	
    
    // ETAPE 4  (choix prochain sommet)

    int col_test=0;
    bool b=false;

    for(int i=0;i<nb_color_disp(liste_vide[sommet]);i++)
    {
    
        col_test=color_disp(liste_vide[sommet])[i];
        int som_non_col=0;
        couleurs[liste_vide[sommet]]=col_test; som_non_col=1;        
        b=recursive(cont,sommet+1,liste_vide);
        
        if(b)
        {
            return true;break;
        }
        
        couleurs[liste_vide[sommet]]=-1;
        
    }
    return false;
}

    
bool Graphe_couleur::recursive2(int cont, int sommet){

    coloration_init(numerotation_init);
    cont+=1;
    cout << "SOMMET NUMERO :" << sommet << endl;
    if(sommet>=n)
    {
        cout << "dernier sommet" << endl;return true;
    }

    vector<int>::iterator git;
    git = find(couleurs.begin(), couleurs.end(), -1);
    if( git == couleurs.end() )
    {
        cout << "PLUS DE SOMMET A COLORIER" << endl;return true;
    }
    // cas egalite

    if(nb_color_disp(sommet)==0)
    {
        return false;
    } 
    // ETAPE 4  (choix prochain sommet)

    int col_test=0;
    bool b=false;

    for(int i=0;i<nb_color_disp(sommet);i++)
    {
        col_test=color_disp(sommet)[i];
        couleurs[sommet]=col_test;  
    
        b=recursive2(cont,sommet+1);
        if(b)
        {
            return true;
            break;
        }
        couleurs[sommet]=-1;
    }

    return false;
}