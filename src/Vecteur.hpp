#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <math.h>
#include <iostream>
#include "Matrice.hpp"

class Vecteur : public Matrice {
	public:
		Vecteur ();
		Vecteur ( unsigned int n );
		
		float prodScal ( const Vecteur & vect );
		float norme ();

		friend std::ostream & operator<< ( std::ostream & flux, const Vecteur & vect );
};

#endif
