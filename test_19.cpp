#include "Graphe_general_12_N4(autre).hpp"
#include <iostream>

int main(){


/*
std::vector< std::pair<int,int> > arr(0);
std::pair <int,int> arr1(0,1);
std::pair <int,int> arr2(1,2);
std::pair <int,int> arr3(2,3);
std::pair <int,int> arr4(3,0);
std::pair <int,int> arr5(1,3);
std::pair <int,int> arr6(0,2);
arr.push_back(arr1);
arr.push_back(arr2);
arr.push_back(arr3);
arr.push_back(arr4);
arr.push_back(arr5);
arr.push_back(arr6);


std::vector<int> v({0,1,2,3});

Graphe_couleur G(v,arr,4) ;

//std::vector<int> vect({-1,-1,1,-1});
//G.coloration(vect);
G.backtracking();




G[0];
G[1];
G[2];
G[3];
   */


/*
for(int k=0;k<G.color_disp(0).size();k++){std::cout << G.color_disp(0)[k] << std::endl;}
std::cout << "nb couleur" << G.nb_color_disp(0) << std::endl; */


std::vector< std::pair<int,int> > arr(0);
std::pair <int,int> arr1(0,2);
std::pair <int,int> arr2(0,3);
std::pair <int,int> arr3(0,5);
std::pair <int,int> arr4(1,3);
std::pair <int,int> arr5(1,4);
std::pair <int,int> arr6(1,6);
std::pair <int,int> arr7(2,4);
std::pair <int,int> arr8(2,7);
std::pair <int,int> arr9(3,8);
std::pair <int,int> arr10(4,9);
std::pair <int,int> arr11(5,6);
std::pair <int,int> arr12(5,9);
std::pair <int,int> arr13(6,7);
std::pair <int,int> arr14(7,8);
std::pair <int,int> arr15(8,9);
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

std::vector<int> v({0,1,2,3,4,5,6,7,8,9});

Graphe_couleur Petersen(v,arr,3) ;

Petersen[3] ; Petersen[9] ;

Petersen.backtracking();

std::cout << "VERIFICATION" << std::endl;

Petersen[0] ; Petersen[1] ; Petersen[2] ;Petersen[3] ;Petersen[4] ; 

/*
std::vector< std::pair<int,int> > arr(0);
std::pair <int,int> arr1(0,1);
std::pair <int,int> arr2(1,2);
std::pair <int,int> arr3(2,0);

std::pair <int,int> arr4(0,3);
std::pair <int,int> arr5(1,5);
std::pair <int,int> arr6(2,7);



std::pair <int,int> arr7(3,4);
std::pair <int,int> arr8(4,5);
std::pair <int,int> arr9(5,6);
std::pair <int,int> arr10(6,7);
std::pair <int,int> arr11(7,8);
std::pair <int,int> arr12(8,3);


std::pair <int,int> arr13(9,3);
std::pair <int,int> arr14(9,4);
std::pair <int,int> arr15(9,5);
std::pair <int,int> arr16(9,6);
std::pair <int,int> arr17(9,7);
std::pair <int,int> arr18(9,8);

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
std::vector<int> v({0,1,2,3,4,5,6,7,8,9});

Graphe_couleur Golomb(v,arr,4) ;

Golomb[9];

Golomb[3];

Golomb[0];
Golomb[4];




//Golomb.backtracking();
std::cout << "VERIFICATION" << std::endl; */


/*
std::vector< std::pair<int,int> > arr(0);
std::pair <int,int> arr1(2,1);
std::pair <int,int> arr2(1,3);
std::pair <int,int> arr3(3,4);
std::pair <int,int> arr4(4,2);
std::pair <int,int> arr5(2,3);
std::pair <int,int> arr6(1,4);



std::pair <int,int> arr7(2,0);
std::pair <int,int> arr8(0,1);
std::pair <int,int> arr9(1,5);
std::pair <int,int> arr10(5,6);
std::pair <int,int> arr11(6,2);


std::pair <int,int> arr12(6,4);
std::pair <int,int> arr13(4,5);
std::pair <int,int> arr14(5,3);

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
std::vector<int> v({0,1,2,3,4,5,6});

Graphe_couleur test_3(v,arr,5);
test_3.backtracking(); */


return 0;}