#include "option.h"
#include <iostream>

//Constructeurs
Option::Option() : id(0), nom(""), raccourci(""), description(""), type(Option::aucun) {}
Option::Option(int i,std::string n,std::string r,std::string d,Option::Type t) : id(i), nom(n), raccourci(r), description(d), type(t) {}

//Accesseurs en lecture
int Option::getId() const {return id;}
std::string Option::getNom() const {return nom;}
std::string Option::getRaccourci() const {return raccourci;}
std::string Option::getDescription() const {return description;}
Option::Type Option::getType() const {return type;}

//Accesseurs en écriture
void Option::setId(int n){id = n;}
void Option::setNom(const std::string n){nom = n;}
void Option::setRaccourci(const std::string r){raccourci = r;}
void Option::setDescription(const std::string d){description = d;}
void Option::setType(Option::Type t){type = t;}

//Affichage
void Option::print() const{
	std::cout << "ID : " << id << std::endl;
	std::cout << "NOM : " << nom << std::endl;
	std::cout << "RACCOURCI : " << raccourci << std::endl;
	std::cout << "DESCRIPTION : " << description << std::endl;
	std::cout << "TYPE : " << TypeToString(type) << std::endl;
}

//Converion type en string
std::string TypeToString(Option::Type type){
	std::string s;
	switch (type){
		case Option::aucun :
			s = "AUCUN";
			break;
		case Option::booleen :
			s = "BOOL";
			break;
		case Option::entier :
			s = "ENTIER";
			break;
		case Option::reel :
			s = "REEL";
			break;
		case Option::car :
			s = "CHAR";
			break;
		case Option::chaine :
			s = "STRING";
			break;
	}
	return s;
}
