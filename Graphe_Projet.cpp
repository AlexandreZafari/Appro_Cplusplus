#include <iostream>

#include "Graphe.hpp"
#include "Sudoku.hpp"

#include <vector>
#include <string>

using namespace std;

int main(){

vector< pair<int,int> > arr(0);
pair <int,int> arr1(0,2);
pair <int,int> arr2(0,3);
pair <int,int> arr3(0,5);
pair <int,int> arr4(1,3);
pair <int,int> arr5(1,4);
pair <int,int> arr6(1,6);
pair <int,int> arr7(2,4);
pair <int,int> arr8(2,7);
pair <int,int> arr9(3,8);
pair <int,int> arr10(4,9);
pair <int,int> arr11(5,6);
pair <int,int> arr12(5,9);
pair <int,int> arr13(6,7);
pair <int,int> arr14(7,8);
pair <int,int> arr15(8,9);
arr.push_back(arr1);
arr.push_back(arr2);
arr.push_back(arr3);
arr.push_back(arr4);
arr.push_back(arr5);
arr.push_back(arr6);
arr.push_back(arr7);
arr.push_back(arr8);
arr.push_back(arr9);
arr.push_back(arr10);
arr.push_back(arr11);
arr.push_back(arr12);
arr.push_back(arr13);
arr.push_back(arr14);
arr.push_back(arr15);

vector<int> v({0,1,2,3,4,5,6,7,8,9});

Graphe_couleur Petersen(v,arr,3) ;

Petersen[3] ; Petersen[9] ;

//avec coloration
//vector<int> vect({0,-1,-1,-1,-1,-1,-1,-1,-1});
//Petersen.coloration(vect);


Petersen.backtracking();

cout << "VERIFICATION" << endl;

Petersen[0] ; Petersen[1] ; Petersen[2] ;Petersen[3] ;Petersen[4] ; 



/*
vector< pair<int,int> > arr(0);
pair <int,int> arr1(0,1);
pair <int,int> arr2(1,2);
pair <int,int> arr3(2,0);
pair <int,int> arr4(0,3);
pair <int,int> arr5(1,5);
pair <int,int> arr6(2,7);
pair <int,int> arr7(3,4);
pair <int,int> arr8(4,5);
pair <int,int> arr9(5,6);
pair <int,int> arr10(6,7);
pair <int,int> arr11(7,8);
pair <int,int> arr12(8,3);
pair <int,int> arr13(9,3);
pair <int,int> arr14(9,4);
pair <int,int> arr15(9,5);
pair <int,int> arr16(9,6);
pair <int,int> arr17(9,7);
pair <int,int> arr18(9,8);
arr.push_back(arr1);
arr.push_back(arr2);
arr.push_back(arr3);
arr.push_back(arr4);
arr.push_back(arr5);
arr.push_back(arr6);
arr.push_back(arr7);
arr.push_back(arr8);
arr.push_back(arr9);
arr.push_back(arr10);
arr.push_back(arr11);
arr.push_back(arr12);
arr.push_back(arr13);
arr.push_back(arr14);
arr.push_back(arr15);
arr.push_back(arr16);
arr.push_back(arr17);
arr.push_back(arr18);
vector<int> v({0,1,2,3,4,5,6,7,8,9});
Graphe_couleur Golomb(v,arr,4) ;
Golomb[9];
Golomb[3];
Golomb[0];
Golomb[4];
Golomb.backtracking();
cout << "VERIFICATION" << endl; 
*/

/*
vector< pair<int,int> > arr(0);
pair <int,int> arr1(2,1);
pair <int,int> arr2(1,3);
pair <int,int> arr3(3,4);
pair <int,int> arr4(4,2);
pair <int,int> arr5(2,3);
pair <int,int> arr6(1,4);
pair <int,int> arr7(2,0);
pair <int,int> arr8(0,1);
pair <int,int> arr9(1,5);
pair <int,int> arr10(5,6);
pair <int,int> arr11(6,2);
pair <int,int> arr12(6,4);
pair <int,int> arr13(4,5);
pair <int,int> arr14(5,3);
arr.push_back(arr1);
arr.push_back(arr2);
arr.push_back(arr3);
arr.push_back(arr4);
arr.push_back(arr5);
arr.push_back(arr6);
arr.push_back(arr7);
arr.push_back(arr8);
arr.push_back(arr9);
arr.push_back(arr10);
arr.push_back(arr11);
arr.push_back(arr12);
arr.push_back(arr13);
arr.push_back(arr14);
vector<int> v({0,1,2,3,4,5,6});
Graphe_couleur test_3(v,arr,5);
test_3.backtracking(); 

for(int k=0;k<7;k++){test_3[k];} */


// TEST SUDOKU

/*
vector<int> numerotation({-1,-1,-1,0,2,-1,3,-1,-1,2,-1,-1,1,-1,-1,-1});
Sudoku sudoku(4,numerotation);

int siz=(sudoku.liste_arretes()).size();
for(int k=0;k<siz;k++){cout << (sudoku.liste_arretes())[k].first <<" - " << (sudoku.liste_arretes())[k].second << endl;
cout << "arrete numero " << k << endl;}


sudoku.backtracking();
// Appel de la méthode, qui modifie l'objet sudoku

cout << "AFFICHAGE DES SOMMETS" << endl;

sudoku.affichage_sudoku(); */


/*
vector<int> numerotation(81,-1);
numerotation[1]=6;
numerotation[2]=1;
numerotation[5]=3;
numerotation[6]=8;
numerotation[9]=2; 
numerotation[11]=3;
numerotation[13]=7;
numerotation[14]=8;
numerotation[15]=0;
numerotation[18]=7;
numerotation[19]=0;
numerotation[20]=8;
numerotation[23]=5;
numerotation[24]=1;
numerotation[25]=4;
numerotation[26]=3;
numerotation[27]=6;
numerotation[29]=0;
numerotation[34]=8;
numerotation[35]=4;
numerotation[36]=8;
numerotation[41]=1;
numerotation[43]=6;
numerotation[48]=7;
numerotation[50]=6;
numerotation[52]=0;
numerotation[53]=1;
numerotation[54]=3;
numerotation[56]=4;
numerotation[59]=0;
numerotation[60]=5;
numerotation[61]=1;
numerotation[63]=1;
numerotation[64]=2;
numerotation[65]=6;
numerotation[69]=4; 
numerotation[71]=0;
numerotation[76]=1;
numerotation[77]=4;
numerotation[78]=6;  
Sudoku sudoku(9,numerotation);

cout << "taille de numerotation" << numerotation.size() << endl;

sudoku.affichage_sudoku();

 sudoku.backtracking();
// Appel de la méthode, qui modifie l'objet sudoku

cout << "AFFICHAGE DES SOMMETS" << endl;

sudoku.affichage_sudoku(); 

// sudoku.affichage_couleurs();  */

// DEUXIEME ESSAI


/*
vector<int> numerotation(81,-1);
numerotation[2]=6;
numerotation[5]=1;
numerotation[6]=7;
numerotation[8]=0;
numerotation[9]=3; 
numerotation[11]=7;
numerotation[13]=0;
numerotation[14]=6;
numerotation[16]=8;
numerotation[21]=3;
numerotation[22]=4;
numerotation[23]=7;
numerotation[24]=5;
numerotation[26]=2;
numerotation[28]=6;
numerotation[29]=0;
numerotation[35]=8;
 
numerotation[45]=1;
numerotation[51]=0;
numerotation[52]=5;

numerotation[54]=6;
numerotation[56]=1;
numerotation[57]=7;
numerotation[58]=2;
numerotation[59]=0;
 
numerotation[64]=0;
numerotation[66]=4;
numerotation[67]=1;
numerotation[69]=6;
numerotation[71]=7;
 
numerotation[72]=7;
numerotation[74]=2;
numerotation[75]=5;
numerotation[78]=8; 
Sudoku sudoku(9,numerotation);

cout << "taille de numerotation" << numerotation.size() << endl;

sudoku.affichage_sudoku();

 sudoku.backtracking();
// Appel de la méthode, qui modifie l'objet sudoku

cout << "AFFICHAGE DES SOMMETS" << std::endl;

sudoku.affichage_sudoku(); 

// sudoku.affichage_couleurs();   */


return 0;
}
