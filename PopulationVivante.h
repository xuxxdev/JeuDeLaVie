#ifndef __POPULATIONVIVANTE_H
#define __POPULATIONVIVANTE_H

#include "Cellule.h"

#define NMAX 100 

class PopulationVivante {
	private :
		Cellule T[NMAX];
		size_t alive;
		size_t N;
		float Proba;
		// Nombre de cells vivante à la cellule 
		size_t nbVoisinsVivants(size_t i, size_t j) const;
		
		//Accés à la cellule et renvoie NULL si morte
		const Cellule* at(size_t i, size_t j) const;
		Cellule* at(size_t i, size_t j);
		
		//Nombre de cells d'une couleur
		size_t nbCellules(Cellule::color couleur) const;

		//Mise à jour des couleurs
		void updateColor();

	public :
		//Constructeur n-pop vide
		PopulationVivante(size_t n);
		PopulationVivante(size_t n,float pro);
		
		//Population de k cells vivantes
		void init(size_t k);

		//Accesseurs lecture
		size_t numCellVivante() const;
		size_t numCellMorte() const;
		size_t numCellNaitre() const;
		size_t numCellVaMourir() const;
		size_t getDim() const;
		float getProb() const;

		//Accesseur en lecture d'une cellule
		Cellule copyCell(size_t i, size_t j) const;
		
		//Accesseurs en ecriture
		void tuer(size_t i, size_t j);
		void naitre(size_t i, size_t j);
		void setDim(size_t n);
		void setProb(float p);

		//Print
		void print() const;

		//Prochain tableau
		PopulationVivante next() const;
		
		//Regeneration de la POP
		void reset();
};

#endif
