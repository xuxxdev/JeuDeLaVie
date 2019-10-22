#include <iostream>
#include <string>
#include "Cellule.h"
#include "tabOptions.h"
#include "PopulationVivante.h"
#include "JeudelavieDeux.h"

#define HELP_ID          1
#define VERSION_ID       2
#define DIMENSION_ID    10
#define PROBABILITY_ID  11
#define CONFIG_ID       20

int main(int argc, char** argv){
	
	Jeudelavie J;
	J.parseOptions(argc,argv);
	J.launch(3);

	/*tabOptions maTable;
	
	//Les options du Jeu De La Vie
	Option help(HELP_ID, "--help", "-h",
			"Affiche l'aide du programme", Option::aucun);
	Option version(VERSION_ID, "--version", "-v",
			"Affiche la version du programme", Option::aucun);
	Option dimension(DIMENSION_ID, "--dimension", "-N",
			"Initialise une matrice carrée de la dimension spécifiée",Option::entier);
	Option probability(PROBABILITY_ID, "--probability", "-p",
			"Probabilité d'une cellule d'être en vie au démarrage",Option::reel);
	Option config(CONFIG_ID, "--config", "-f",
			"Charge la configuration initiale du jeu à partir du fichier passé en paramètre",Option::car);
	
	//Ajout des Options Jeu De La Vie
	maTable.ajoutOption(help);maTable.ajoutOption(version);maTable.ajoutOption(dimension);maTable.ajoutOption(probability);maTable.ajoutOption(config);
	
	//Affichage des options entrées
	for(int i = 1;i < argc;i++){
		if(maTable.envoieId(argv[i]) != -1){
			std::cout << "L'option : " << argv[i] << std::endl;
			if(maTable.argumentOption(argv[i])){
				std::cout << "Argument : " << TypeToString(maTable.typeOption(argv[i])) << std::endl;
			}
			std::cout << '\n' << "---------------------------" << '\n' <<std::endl;
		}
		else{
			std::cout << "Usage : " << argv[0] << " [Options]" << std::endl;
			maTable.print();
			return 1;
		}
	}*/
	
	
	return 0;
}
