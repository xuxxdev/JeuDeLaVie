#ifndef __OPTION_H__
#define __OPTION_H__
#include <string>

class Option {
	public :
		enum Type {aucun,booleen,entier,reel,car,chaine};

	private :
		int id;
		std::string nom, raccourci, description;
		Type type;

	public :
		//Constructeur
		Option();
		Option(int i,std::string n,std::string r,std::string d,Option::Type t);

		//Accesseurs en lecture
		int getId() const;
		std::string getNom() const;
		std::string getRaccourci() const;
		std::string getDescription() const;
		Option::Type getType() const;

		//Accesseurs en écriture
		void setId(int n);
		void setNom(const std::string n);
		void setRaccourci(const std::string r);
		void setDescription(const std::string d);
		void setType(Option::Type t);

		//Affichage
		void print() const;
};

std::string TypeToString(Option::Type type);

#endif
