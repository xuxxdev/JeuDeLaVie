#include "tabOptions.h"
#include <iostream>
#include <exception>

//Constructeur
tabOptions::tabOptions() : nbOptions(0){}

//Avoir l'index d'une option dans le tableau
int tabOptions::optionIndex(const Option& monO) const {
	size_t i = 0;
	bool stop = false;

	while(i<nbOptions && !stop){
		if(monO.getId() == T[i].getId()){
			stop = true;		
		}
		else {
			i++;
		}
	}
	return stop ? i : -1;
}

//Avoir l'index d'une option en fonction d'une string
int tabOptions::optionIdexSTR(const std::string& myString) const {
	size_t i = 0;
	bool stop = false;

	while(i<nbOptions && !stop){
		if(myString == T[i].getNom() || myString == T[i].getRaccourci()){
			stop = true;
		}
		else {
			i++;
		}
	}
	return stop ? i : -1;
}

//Ajoute option
void tabOptions::ajoutOption(const Option& monO){
	if(nbOptions == MAX){
		std::cerr << "Maxium d'options déjà atteint." << std::endl;
		std::terminate();
	}
	else {
		if(tabOptions::optionIndex(monO) != -1){
			std::cerr  << "L'identifiant " << monO.getId() << " existe déjà." << std::endl;
		}
		else {
			T[nbOptions] = monO;
			nbOptions++;
		}
	}
}

//Retour id en fonction d'une chaine
int tabOptions::envoieId(const std::string& myString) const {
	int i = optionIdexSTR(myString);
	return i == -1 ? i : T[i].getId();
}

//Retour si il y'a une option ou pas + son type si elle existe
bool tabOptions::argumentOption(const std::string& myString) const {
	int i = optionIdexSTR(myString);
	if(i != -1){
		return T[i].getType() != Option::aucun;
	}
	else {
		std::cerr << "L'option n'existe pas." << std::endl;
		std::terminate();
	}
}
Option::Type tabOptions::typeOption(const std::string& myString) const {
	int i = optionIdexSTR(myString);
	if(i != -1){
		return T[i].getType();
	}
	else {
		std::cerr << "L'option n'existe pas." << std::endl;
		std::terminate();
	}
}

//Affichage du tableau
void tabOptions::print() const {
	for(size_t i = 0;i < nbOptions;i++){
		T[i].print();
		std::cout << '\n' << "--------------------------------" << '\n' << std::endl;
	}
}

