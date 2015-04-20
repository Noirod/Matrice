#ifndef MATRICECARREE_HPP
#define MATRICECARREE_HPP

#include <iostream>
#include <fstream>
#include "Matrice.hpp"

class MatriceCarree : public Matrice {
	public:
		MatriceCarree ();
		MatriceCarree ( unsigned int n );
		MatriceCarree ( const char * pathname );
		~MatriceCarree ();
		
		int determinant ();
		MatriceCarree & inverse ();

		friend std::ostream & operator<< ( std::ostream & flux, const MatriceCarree & mat );
};

#endif
