#include <iostream>
#include "Cellule.h"

using namespace std;

void test_cell(const Cellule & cell){
	if(cell.getVivante()){
		cout << "{Vivante, (" << cell.getX() << "," << cell.getY() << ")" << "}" << endl;
	}
	else {
		cout << "{Morte, (" << cell.getX() << "," << cell.getY() << ")" << "}" << endl;
	}
}

void PrintCell(const Cellule & cell){
	cout << "La cellule est à l'adresse : " << &cell << std::endl;
	cout << "La cellule à l'adresse mémoire (" << &cell << ") :  ";test_cell(cell); 
}

void PrintVoisines(const Cellule & cell1, const Cellule & cell2){
	if(cell1.estVoisine(cell2)) {
		cout << "La cellule1 est voisine de la cellule2" << endl;
	}
	else{
		cout << "La cellule1 n'est pas voisine de la cullule2" << endl;
	}
}

void editEtat(){
	Cellule N[3][3]=
		{{Cellule(false,0,0),Cellule(true ,0,1),Cellule(false,0,2)},
		{Cellule(true, 1,0),Cellule(false,1,1),Cellule(true, 1,2)},
		{Cellule(false,2,0),Cellule(true, 2,1),Cellule(false,2,2)}};

	size_t x,y,state;

	cout << "Quel cellule voulez vous modifier ? (format i , j) :" << endl;
	cin >> x >> y;
	cout << "Son etat : 0 pour morte et 1 pour vivante" << endl;
	cin >> state;
	if(state != N[x][y].getVivante()){N[x][y].setVivante(state);}

}

int main(int argc, char** argv){
	
		return 0;
}
