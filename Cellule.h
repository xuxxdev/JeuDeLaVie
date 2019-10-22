#ifndef __CELLULE_
#define __CELLULE_

#include <string>

class Cellule {	
	public : 
		enum color{noir,bleu,vert,rouge,jaune};
		
	private : 
		bool etat;
		unsigned int x,y;
		color colorCell;
		unsigned int age;

	public :
		//Constructeur
		Cellule();
		Cellule(bool etat,unsigned int x,unsigned int y);

		//Cellule voisine
		bool estVoisine(const Cellule& cell2) const;

		//Lecture
		bool getVivante() const;
		unsigned int getX() const;
		unsigned int getY() const;
		color getColor() const;
		
		//Ecriture
		void setVivante(bool etat);
		void setX(unsigned int x);
		void setY(unsigned int y);

		//Color Cell
		bool isCellColor(const Cellule & cell2,color couleur) const;

		//Mort d'une cell
		void vaMourrir();

		//Affichage cell
		void printCell() const;
};

//signature
std::string couleur2string(Cellule::color couleur); 

#endif

