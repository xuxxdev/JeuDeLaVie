#include "Population.h"
#include <stdlib.h>
#include <iostream>
#include <exception>

#define verif(i,j) if(i >= N || j >= N){std::cout << "Les position sont hors du tableau" << std::endl;std::terminate();}

//Nombre cellules vivantes voisines
size_t Population::nbCellVivanteVoisine(size_t i, size_t j) const {
	size_t x = 0;
	for(size_t k = 0;k < N;k++){
		for(size_t l = 0;l < N;l++){
			if(i != k || j != l){
				if(this->T[i][j].estVoisine(T[k][l]) && this->T[k][l].getVivante()){
					x++;
				}
			}
		}
	}
	return x;
}

//Gérer les cellules qui vont mourir
void Population::colorUpdate() {
	for(size_t i = 0;i < N;i++){
		for(size_t j = 0;j < N;j++){
			if((this->nbCellVivanteVoisine(i,j) < 2 || this->nbCellVivanteVoisine(i,j) > 3) && this->T[i][j].getVivante()){
				this->T[i][j].vaMourrir();
			}
		}
	}
}

//Constructeur
Population::Population(){
	for(size_t i = 0;i < N;i++){
		for(size_t j = 0;j < N;j++){
			this->T[N][N].setX(i);
			this->T[N][N].setX(j);
		}
	}
}

//Initialisation k cells vivante random
void Population::initialisation(size_t k){
	size_t x = 0;
	size_t i,j;
	while(x != k){
		i = rand() % N;
		j = rand() % N;
		if(!this->T[i][j].getVivante()){
			this->T[i][j].setVivante(true);
			x++;
		}
	}
}

//Accés lecture copie cell
Cellule Population::copyCell(size_t i, size_t j) const {
	verif(i,j);
	return T[i][j];
}

//Retour cellule lecture seule sans copie
const Cellule& Population::lecCell(size_t i, size_t j) const {
	verif(i,j);
	return T[j][j];
}

//Access lecture
size_t Population::numCellVivante() const {
	size_t x = 0;
	for(size_t i = 0;i < N;i++){
		for(size_t j = 0;j < N;j++){
			if(this->T[i][j].getVivante()){x++;}
		}
	}
	return x;
}

size_t Population::numCellMorte() const {
	size_t x = N - Population::numCellVivante();
	return x;
}

size_t Population::numCellNaitre() const {
	size_t x = 0;
	for(size_t i = 0;i < N;i++){
		for(size_t j = 0;j < N;j++){
			if(this->T[i][j].getColor() == Cellule::bleu){x++;}
		}
	}
	return x;
}

size_t Population::numCellVaMourir() const {
	size_t x = 0;
	for(size_t i = 0;i < N;i++){
		for(size_t j = 0;j < N;j++){
			if(this->T[i][j].getColor() == Cellule::rouge|| this->T[i][j].getColor() == Cellule::jaune){x++;}
		}
	}
	return x;
}

//Population suivante
Population Population::next() const {
	Population Pop(*this);
	
	for(size_t i = 0;i < N;i++){
		for(size_t j = 0;j < N;j++){
			Pop.T[i][j].setVivante(nbCellVivanteVoisine(i,j) == 3 || (nbCellVivanteVoisine(i,j) == 2 && this->T[i][j].getVivante()));
		}
	}
	Pop.colorUpdate();
	return Pop;
}

