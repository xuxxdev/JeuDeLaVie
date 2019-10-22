#ifndef __TABOPTIONS_H__
#define __TABOPTIONS_H__
#include "option.h"

#define MAX 20

class tabOptions {
	private :
		Option T[MAX];
		size_t nbOptions;
		int optionIndex(const Option& monO) const;
		//Trouver une options en fonction d'une str
		int optionIdexSTR(const std::string& myString) const;
	public :
		//Constructeur
		tabOptions();
		
		//Ajout d'une option
		void ajoutOption(const Option& monO);

		//Retour id en fonction d'une chaine
		int envoieId(const std::string& myString) const;

		//Retour si il y'a une option ou pas + son type si elle existe
		bool argumentOption(const std::string& myString) const;
		Option::Type typeOption(const std::string& myString) const;
		
		//Affichage du tableau
		void print() const;
};

#endif
