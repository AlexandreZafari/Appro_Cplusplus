#include "Sudoku.hpp"

bool Sudoku::existe_arrete(int i,int j){
    if(i==j)
    {
        return true;
    }
    
    int res=0;
    
    auto function=[i,j,&res](std::pair<int,int> k){
        if(k.first==i && k.second==j)
        {
            res=res+1;
            }
        if(k.first==j && k.second==i)
        {
            res=res+1;
        }
    ;}

    for_each(arretes.begin(),arretes.end(), function);
    
    if(res>0)
    {
        return true;
    }
    
    return false;
}	

void Sudoku::affichage_sudoku(){
	vector<int> aux({0,9,18,27,36,45,54,63,72});
	for(int j=0;j<9;j++)
    {
		int i=aux[j];
		cout << couleurs[i] +1 << "|" << couleurs[i+1]+1 << "|" << couleurs[i+2]+1 << "|" << couleurs[i+3]+1 << "|" << couleurs[i+4]+1 << "|" << couleurs[i+5]+1 << "|" << couleurs[i+6]+1 << "|" << couleurs[i+7]+1 << "|" << couleurs[i+8]+1 << endl;
    }
}


void Sudoku::affichage_couleurs(){
    vector<int> aux=couleurs;
    for(int j=0;j<aux.size();j++)
    {
        cout << "couleurs dispo :" << couleurs[j] << endl;
    }
}