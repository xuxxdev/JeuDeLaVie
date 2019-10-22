#include <iostream>
#include "Cellule.h"

//Constructeur

Cellule::Cellule() : etat(false), x(0), y(0), colorCell(noir), age(0) {}
Cellule::Cellule(bool etat,unsigned int x,unsigned int y) : etat(etat), x(x), y(y), colorCell(etat ? bleu : noir), age(etat ? 1 : 0) {}

//Cellule voisine

bool Cellule::estVoisine(const Cellule& cell2) const{
	return cell2.etat && (this->getX() - cell2.getX())*(this->getX() - cell2.getX()) + (this->getY() - cell2.getY())*(this->getY() - cell2.getY()) <= 2;
}

//Lecture
bool Cellule::getVivante() const {return this->etat;}
unsigned int Cellule::getX() const {return this->x;}
unsigned int Cellule::getY() const {return this->y;}
Cellule::color Cellule::getColor() const {return this->colorCell;}

//Ecriture
void Cellule::setVivante(bool etat){
	if(etat){
		this->etat = etat;
		this->colorCell = (this->age++ ? vert : bleu);
	}
	else{
		this->age = 0;
		this->etat = etat;
		this->colorCell = noir;
	}
}

void Cellule::setX(unsigned int x) {this->x = x;}
void Cellule::setY(unsigned int y) {this->y = y;}

//Color Cell
bool Cellule::isCellColor(const Cellule & cell2,color couleur) const {
	return cell2.getColor() == couleur;
}

//Mort d'une cell
void Cellule::vaMourrir(){
	if(this->etat){
		this->colorCell == bleu ? this->colorCell = jaune: this->colorCell = rouge;
	}
}

//Retour string de la couleur
std::string couleur2string(Cellule::color couleur) {
	std::string str;
	switch(couleur){
		case Cellule::noir : 
			str = "noir";
			break;
		case Cellule::bleu :
			str = "bleu";
			break;
		case Cellule::vert :
			str = "vert";
			break;
		case Cellule::rouge :
			str = "rouge";
			break;
		case Cellule::jaune :
			str = "jaune";
			break;
		default : 
			str = "erreur";
	}
	return str;
}

//Affichage cell
void Cellule::printCell() const {
	if(this->etat) {std::cout << "La cellule est : Vivante" << std::endl;}
	else {std::cout << "La cellule est : Morte" << std::endl;}
	std::cout << "Sa position est : (" << this->x << " , " << this->y << ")" << std::endl;
       	std::cout << "Sa couleur est : " << couleur2string(this->colorCell) << std::endl;	
}
