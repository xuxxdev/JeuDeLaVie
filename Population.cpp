#include "Population.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <exception>

#define verif(i,j) if(i >= N || j >= N){std::cout << "Les position sont hors du tableau" << std::endl;std::terminate();}

//Nombre cellules vivantes voisines
size_t Population::nbCellVivanteVoisine(size_t ci, size_t cj) const {
	size_t tmp = 0;
	size_t imin, imax, jmin, jmax;

	imin = ci == 0 ? ci : ci-1;
	imax = ci == (N-1) ? ci : ci+1;
	jmin = cj == 0 ? cj : cj-1;
	jmax = cj == (N-1) ? cj : cj+1;

	for(size_t i = imin;i <= imax;i++){
		for(size_t j = jmin;j <= jmax;j++){
			if(T[i][j].getVivante()){
				tmp++;
			}
		}
	}
	return tmp - (T[ci][cj].getVivante() ? 1 : 0);
}

//Gérer les cellules qui vont mourir
void Population::colorUpdate() {
	size_t voisins;

	for(size_t i = 0;i < N;i++){
		for(size_t j = 0;j < N;j++){
			voisins = nbCellVivanteVoisine(i,j);
			if((voisins < 2 || voisins > 3) && this->T[i][j].getVivante()){
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
	srand(time(NULL));
	while(x != k){
		i = rand() % N;
		j = rand() % N;
		if(!this->T[i][j].getVivante()){
			this->T[i][j].setVivante(true);
			x++;
		}
	}
	Population::colorUpdate();
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
//Accesseur en ecriture
void Population::tuer(size_t i, size_t j) {
	verif(i,j);
	T[i][j].setVivante(false);
}

void Population::naitre(size_t i, size_t j) {
	verif(i,j);
	T[i][j].setVivante(true);
}

//Affichage population
void Population::print() const{
	for(size_t i = 0;i < N;i++){
		for(size_t j = 0;j < N;j++){
			std::cout << std::left << std::setw(6) << couleur2string(T[i][j].getColor());
		}
		std::cout << std::endl;
	}
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

