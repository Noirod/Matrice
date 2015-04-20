#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <iostream>
#include <fstream>

class Matrice {

public:
	Matrice ();
	Matrice ( const char * pathname );
	Matrice ( unsigned int n, unsigned int m );

	~Matrice ();

	void creer ( unsigned int n, unsigned int m );
	void detruire ();

	unsigned int getNbLigne () const;
	unsigned int getNbColonne () const;
	float getElement ( unsigned int i, unsigned int j ) const;

	void setElement ( float k, unsigned int i, unsigned int j );

	Matrice add ( Matrice & mat );
	Matrice add ( float k );
	Matrice prod ( Matrice & mat );
	Matrice prod ( float k );
	Matrice transpose ();

	bool save ( const char * pathname );

	friend std::ostream & operator<< ( std::ostream & flux, const Matrice & mat );
	void operator= ( const Matrice & mat );

protected:
	unsigned int _n, _m;
	float ** _mat;
};

#endif
