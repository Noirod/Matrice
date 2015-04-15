#include "Vecteur.hpp"

Vecteur::Vecteur () {
	_n = 0;
	_m = 0;
}

Vecteur::Vecteur ( unsigned int n ) {
	this->creer ( n, 1 ); 
}

float Vecteur::prodScal ( const Vecteur & vect ) {
	float res = 0;
	if ( _n > 0 ) { //le vecteur existe
		if ( _n == vect._n ) { //les deux vecteurs ont la meme taille
			for ( unsigned int i = 0; i < _n; i++ ) {
				res += _mat[i][0] * vect._mat[i][0];
			}
		}
	}
	return res;
}

float Vecteur::norme () {
	float res = 0;
	if ( _n > 0 ) {
		for ( unsigned int i = 0; i < _n; i++ ) {
			res += _mat[i][0] * _mat[i][0];
		}
	}
	return sqrt ( res );
}

std::ostream & operator<< ( std::ostream & flux, const Vecteur & vect ) {
	flux << (Matrice &)(vect);	
	return flux;
}
