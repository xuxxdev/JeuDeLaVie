#ifndef __JEUDELAVIEDEUX_H__
#define __JEUDELAVIEDEUX_H__

#include <fstream>
#include <string>
#include "PopulationVivante.h"
#include "tabOptions.h"

class Jeudelavie {
	private :
		PopulationVivante POP;
		tabOptions T;	

		std::string nettoie(std::string s) const;
		bool findCleVal(std::string s, std::string& cle, std::string& val);

		//Modif de la population en fonction d'une clé/val
		void traiteOptions(const std::string& cle, const std::string& val);

	public :
		Jeudelavie();

		//Recup cle/val fichier de config
		void configFile(std::string file);

		//Lancement JDV nombre étape specifique
		void launch(size_t n);

		//Recup cle/val depuis ligne de commande
		void parseOptions(int argc,char** argv);
};

#endif
