#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Jeudelavie.h"

//Constructeur
Jeudelavie::Jeudelavie() : POP(8,0.25) {}
Jeudelavie::Jeudelavie(size_t n) : POP(n){}

//Gestion clé : val
std::string Jeudelavie::nettoie(std::string s) const{
	size_t diez = s.find_first_of("#");
	if(diez != std::string::npos){
		s = s.substr(0,diez);
	}
	return s;
}

bool Jeudelavie::findCleVal(std::string s, std::string& cle, std::string& val){
	s = nettoie(s);
	size_t mil = s.find_first_of(':');

	if(mil != std::string::npos){
		size_t debut = 0,i = 0;
		std::string s1 = s.substr(0,mil);
		std::string s2 = s.substr(mil+1);
		
		//Espace du DEBUT 
		while(i < s1.size() && s1[i] == ' '){debut++;i++;}
		s1 = s1.substr(debut);
		i = s1.size()-1;debut = s1.size();
		//Espace de FIN
		while(i >= 0 && s1[i] == ' '){debut--;i--;}
		cle = s1.substr(0,debut);

		debut = 0;i = 0;
		while(s2[i] == ' ' && i < s2.size()){debut++;i++;}
		s2 = s2.substr(debut);
		debut = s2.size();i = s2.size()-1;
		while(i < s2.size() && s2[i] == ' '){debut--;i--;}
		val = s2.substr(0,debut);
		
		return true;
	}
	else{
		return false;
	}
}

//Modif de la population en fonction d'une clé/val
void Jeudelavie::traiteOptions(const std::string& cle, const std::string& val){
	if(cle == "Dimension"){
		POP.setDim(atoi(val.c_str()));
	}
	else if(cle == "Probability"){
		POP.setProb(atof(val.c_str()));
	}
	else if(cle == "Cell"){
		std::string pos1, pos2;
		size_t space, virg, x;
		size_t i, debut;
		space = val.find_first_of(' ');
		virg = val.find_first_of(',');
		x = val.find_first_of('x');

		if(space != std::string::npos){
			pos1 = val.substr(0,space);
			pos2 = val.substr(space);

			i = pos1.size()-1;debut = pos1.size();
			while(i >= 0 and pos1[i] == ' '){debut--;i--;}
			pos1 = pos1.substr(0,debut);

			i = 0;debut = 0;
			while(i < pos2.size() && pos2[i] == ' '){debut++;i++;}
			pos2 = pos2.substr(debut);
		}
		else if(virg != std::string::npos){
			pos1 = val.substr(0,virg);
			pos2 = val.substr(virg);
		}
		else if(x != std::string::npos){
			pos1 = val.substr(0,x);
			pos2 = val.substr(x);

		}
		POP.naitre(atoi(pos1.c_str()),atoi(pos2.c_str()));
	}
}

//Recup cle-val fichier confif
void Jeudelavie::configFile(std::string file){
	std::ifstream fichier;
	fichier.open(file.c_str());
	std::string s, cle, valeur;
	if(fichier.is_open()){
		while(!fichier.eof()){
			getline(fichier,s);
			if(!fichier.eof() && findCleVal(s,cle,valeur)){
				traiteOptions(cle,valeur);
			}
		}
	}
	else {
		std::cerr << "Le fichier config n'est pas ouvert" << std::endl;
		std::terminate();
	}
}

//Lancement JDV nombre étape specifique
void Jeudelavie::launch(size_t n){
	POP.print();
	for(size_t i = 0;i<n;i++){
		std::cout << "\n\n";
		POP = POP.next();
		POP.print();
	}
}
