#include "Graphe_general_12.hpp"
#include <iostream>

int main(){

std::vector< std::pair<int,int> > arr(0);
std::pair <int,int> arr1(1,2);
arr.push_back(arr1);

std::vector<int> v({1,2});

Graphe_couleur G(v,arr,5) ;
G[0];
G[1];

G.backtracking();
G[0];
G[1];




return 0;}
