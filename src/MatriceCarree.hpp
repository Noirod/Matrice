#ifndef MATRICECARREE_HPP
#define MATRICECARREE_HPP

#include <iostream>
#include "Matrice.hpp"

class MatriceCarree : public Matrice {
	public:
		MatriceCarree ();
		MatriceCarree ( unsigned int n );
		~MatriceCarree ();
		
		int determinant ();
		MatriceCarree & inverse ();

		friend std::ostream & operator<< ( std::ostream & flux, const MatriceCarree & mat );
};

#endif
