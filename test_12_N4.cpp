#include "Graphe_general_12_N2.hpp"
#include <iostream>

int main(){

std::vector< std::pair<int,int> > arr(0);
std::pair <int,int> arr1(0,1);
std::pair <int,int> arr2(1,2);
std::pair <int,int> arr3(2,3);
std::pair <int,int> arr4(3,0);
arr.push_back(arr1);
arr.push_back(arr2);
arr.push_back(arr3);
arr.push_back(arr4);

std::vector<int> v({0,1,2,3});

Graphe_couleur G(v,arr,5) ;
G[0];
G[3];

G.backtracking();


G[0];
G[1];
G[2];
G[3];

/*std::cout << G.color_disp(0).size() << std::endl;
std::cout << G.color_disp(1).size() << std::endl;
std::cout << G.nb_color_disp(1) << std::endl;
std::cout << G.nb_color_disp(0) << std::endl;*/

return 0; }
