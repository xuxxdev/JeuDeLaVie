#ifndef __POPUlATION_H
#define __POPUlATION_H

#include "Cellule.h"
#define N 4

class Population{
	private :
		Cellule T[N][N];	
	
		//Calcul nombre de cellule de cette couleur
		size_t nb_cellule(Cellule::color color) const;

		//Calcul nombre de cellules vivantes voisines
		size_t nbCellVivanteVoisine(size_t i, size_t j) const;

		//Gérer les cellules qui vont mourir
		void colorUpdate() ;

	public :
		//Population morte
		Population();
		
		//Ajout aleatoire de k cells vivante si population morte
		void initialisation(size_t k);
	
		//Accès lecture d'une cellule
		Cellule copyCell(size_t i, size_t j) const;

		//Retour cellule lecture seule sans copie
		const Cellule& lecCell(size_t i, size_t j) const;

		//Access lecture
		size_t numCellVivante() const;
		size_t numCellMorte() const;
		size_t numCellNaitre() const;
		size_t numCellVaMourir() const;

		//Population suivante
		Population next() const;
};

#endif

