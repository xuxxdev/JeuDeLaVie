#include "PopulationVivante.h"
#include <exception>
#include <iostream>
#include <iomanip>
#include <cstdlib>

#define check(i,j) if(i >= this->N || j >= this->N){std::cout << "Erreur" << std::endl;std::terminate();}

//Constructeur
PopulationVivante::PopulationVivante(size_t n) : alive(0), N(n) {
	if(N*N > NMAX){
		std::cout << "Population trop grande" << std::endl;
		std::terminate();
	}
}

PopulationVivante::PopulationVivante(size_t n,float pro) : alive(0), N(n), Proba(pro){PopulationVivante::reset();}

//Nb cells d'une couleur
size_t PopulationVivante::nbCellules(Cellule::color couleur) const {
	size_t tmp = 0;
	if(couleur == Cellule::noir){
		return N - this->alive;
	}
	else{
		for(size_t i = 0;i < this->alive;i++){
			if(T[i].getColor() == couleur){tmp++;}
		}
		return tmp;
	}
}

//Accés à une cell
const Cellule* PopulationVivante::at(size_t i, size_t j) const{
	for(size_t v = 0;v < this->alive;v++){
		if(T[v].getX() == i && T[v].getY() == j){
			return &T[v];
		}
	}

	return NULL;
}

Cellule* PopulationVivante::at(size_t i, size_t j) {
	for(size_t v = 0;v < this->alive;v++){
		if(T[v].getX() == i && T[v].getY() == j){
			return &T[v];
		}
	}

	return NULL;
}

size_t PopulationVivante::nbVoisinsVivants(size_t ci, size_t cj) const {
	size_t tmp = 0;
	size_t imin, imax, jmin, jmax;

	imin = ci == 0 ? ci : ci-1;
	imax = ci == (N-1) ? ci : ci+1;
	jmin = cj == 0 ? cj : cj-1;
	jmax = cj == (N-1) ? cj : cj+1;

	for(size_t i = imin;i <= imax;i++){
		for(size_t j = jmin;j <= jmax;j++){
			if(PopulationVivante::at(i,j) != NULL){
				tmp++;
			}
		}
	}
	return tmp - (at(ci,cj) != NULL ? 1 : 0);
}

//Mise à jour des couleurs
void PopulationVivante::updateColor() {
	size_t tmp;
	for(size_t i = 0;i < this->alive;i++){
		tmp = nbVoisinsVivants(T[i].getX(),T[i].getY());
		if(tmp != 2 && tmp != 3){
			T[i].vaMourrir();
		}
	}
}

//Population de k cells vivantes
void PopulationVivante::init(size_t k){
	srand(time(NULL));
	if(this->alive == 0){
		size_t i, j, n = 0;
		while(n != k){
			i = rand()% this->N;
			j = rand()% this->N;
			if(PopulationVivante::at(i,j) == NULL){
				this->T[n] = Cellule(true,i,j);
				n++;
				this->alive++;
			}
		}
	}
	PopulationVivante::updateColor();
}

//Accesseurs lecture
size_t PopulationVivante::numCellVivante() const {return this->alive;}
size_t PopulationVivante::numCellMorte() const {return this->N - this->alive;}
size_t PopulationVivante::numCellNaitre() const {return PopulationVivante::nbCellules(Cellule::bleu);}
size_t PopulationVivante::numCellVaMourir() const {return PopulationVivante::nbCellules(Cellule::jaune) + PopulationVivante::nbCellules(Cellule::rouge);}
size_t PopulationVivante::getDim() const {return N;}
float PopulationVivante::getProb() const {return Proba;}

//Accesseur en lecture d'une cellule
Cellule PopulationVivante::copyCell(size_t i, size_t j) const {
	check(i,j);
	const Cellule* ptr = at(i,j);
	if(ptr != NULL){
		return *ptr;
	}
	else {
		return Cellule(false,i,j);
	}
}

//Accesseurs en ecriture
void PopulationVivante::tuer(size_t i, size_t j) {
	check(i,j);
	Cellule* ptr = at(i,j);
	size_t tmp;

	if(ptr != NULL){
		ptr->setVivante(false);
		tmp = ptr - T;
		this->alive--;
		for(size_t k = tmp;k < this->alive;k++){
			this->T[k] = T[k+1];
		}
	}
}

void PopulationVivante::naitre(size_t i, size_t j) {
	check(i,j);
	Cellule* ptr = at(i,j);
	if(this->alive + 1 <= NMAX){
		if(ptr == NULL){
			T[alive] = Cellule(true,i,j);
			this->alive++;			
		}
		else {
			ptr->setVivante(true);
		}
	}
	else {
		std::cerr << "Population Vivante trop grande" << std::endl;
		std::terminate();
	}
	
}

void PopulationVivante::setDim(size_t n){
	N = n;
	PopulationVivante::reset();
}
void PopulationVivante::setProb(float p){
	Proba = p;
	PopulationVivante::reset();
}

//Print
void PopulationVivante::print() const {
	std::cout << "N : " << N << '\t' << "Probability : " << Proba << std::endl;
	for(size_t i = 0;i < N;i++){
		for(size_t j = 0;j < N;j++){
			std::cout << std::left << std::setw(6) << couleur2string(copyCell(i,j).getColor()) << " ";
		}
		std::cout << std::endl;
	}
}

PopulationVivante PopulationVivante::next() const {
	PopulationVivante POP(*this);
	size_t voisins;

	for(size_t i = 0;i < N;i++){
		for(size_t j = 0; j < N;j++){
			voisins = nbVoisinsVivants(i,j);
			if((at(i,j) != NULL) && ((voisins == 3) || (voisins == 2))){
				POP.naitre(i,j);
			}
			else if((at(i,j) == NULL) && (voisins == 3)) {
				POP.naitre(i,j);
			}
			else {
				POP.tuer(i,j);
			}
		}
	}
	POP.updateColor();
	return POP;
}

void PopulationVivante::reset(){
	srand(time(NULL));
	this->alive = 0;
	float x;
	for(size_t i = 0;i < N;i++){
		for(size_t j = 0;j < N;j++){
			x = rand() % 100;
			if(x <= Proba*100){
				PopulationVivante::naitre(i,j);
			}
			else{
				PopulationVivante::tuer(i,j);
			}
		}
	}
	updateColor();
}
