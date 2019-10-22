#ifndef __JEUDELAVIE_H__
#define __JEUDELAVIE_H__

#include <fstream>
#include <string>
#include "PopulationVivante.h"

class Jeudelavie {
	private :
		PopulationVivante POP;
		std::string nettoie(std::string s) const;
		bool findCleVal(std::string s, std::string& cle, std::string& val);

		//Modif de la population en fonction d'une clé/val
		void traiteOptions(const std::string& cle, const std::string& val);

	public :
		Jeudelavie();
		Jeudelavie(size_t n);

		//Recup cle/val fichier de config
		void configFile(std::string file);

		//Lancement JDV nombre étape specifique
		void launch(size_t n);
};

#endif
