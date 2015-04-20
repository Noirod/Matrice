#include "Matrice.hpp"


Matrice::Matrice () {
	_n = 0;
	_m = 0;
}

Matrice::Matrice ( const char * pathname ) {
	std::ifstream file ( pathname );
	_n = 0;
	_m = 0;
	if ( file ) { //fichier trouve
		unsigned int n, m;
		file >> n >> m;
		this->creer ( n, m );
		for ( unsigned int i = 0; i < n; i++ ) {
			for ( unsigned int j = 0; j < m; j++ ) {
				file >> _mat [i][j];
			}
		}
	}
}

Matrice::Matrice ( unsigned int n, unsigned int m ) {
	_n = 0;
	_m = 0;
	this->creer ( n, m );
}

Matrice::~Matrice () {
	this->detruire ();
}

Matrice Matrice::add ( const Matrice & mat ) {
	Matrice res;
	if ( ( _n > 0 ) && ( _m > 0 ) ) { //la matrice existe
		if ( ( _n == mat._n ) && ( _m == mat._m ) ) { //les matrices ont la meme taille
			res.creer ( _n, _m );
			for ( unsigned int i = 0; i < _n; i++ ) {
				for ( unsigned int j = 0; j < _m; j++ ) {
					res._mat[i][j] = _mat[i][j] + mat._mat[i][j];
				}
			}
		}
	}
		
	return res;
}

Matrice Matrice::add ( float k ) {
	Matrice res;
	if ( ( _n > 0 ) && ( _m > 0 ) ) { //la matrice existe
		res.creer ( _n, _m );
		for ( unsigned int i = 0; i < _n; i++ ) {
			for ( unsigned int j = 0; j < _m; j++ ) {
				res._mat[i][j] = _mat[i][j] + k;
			}
		}

	}
	return res;
}

Matrice Matrice::prod ( const Matrice & mat ) {
	Matrice res;
	if ( ( _n > 0 ) && ( _m > 0 ) ) {
		if ( ( mat._n > 0) && ( mat._m > 0 ) ) { //les matrices existent
			if ( _m == mat._n ) { //le produit est possible
				res.creer ( _n, mat._m );
				for ( unsigned int i = 0; i < _n; i++ ) {
					for ( unsigned int j = 0; j < mat._m; j++ ) {
						for ( unsigned int k = 0; k < _m; k++ ) {
							res._mat[i][j] += _mat[i][k] * mat._mat[k][j];
						}
					}
				}
			}
		}
	}
	return res;
}

Matrice Matrice::prod ( float k ) {
	Matrice res;
	if ( ( _n > 0 ) && ( _m > 0 ) ) { //la matrice existe
		res.creer ( _n, _m );
		for ( unsigned int i = 0; i < _n; i++ ) {
			for ( unsigned int j = 0; j < _m; j++ ) {
				res._mat[i][j] = _mat[i][j] * k;
			}
		}
	}
	return res;
}

Matrice Matrice::transpose () {
	Matrice res;
	if ( ( _n > 0 ) && ( _m > 0 ) ) { //la matrice existe
		res.creer ( _m, _n ); // matrice ou on inverse les dimensions
		for ( unsigned int i = 0; i < _m; i++ ) {
			for ( unsigned int j = 0; j < _n; j++ ) {
				res._mat[i][j] = _mat[j][i];
			}
		}
	}

	return res;
}

bool Matrice::save ( const char * pathname ) {
	std::ofstream file ( pathname );
	if ( file ) {
		file << _n << " " << _m;
		file << std::endl;
		for ( unsigned int i = 0; i < _n; i++ ) {
			for ( unsigned int j = 0; j < _m; j++ ) {
				file << _mat[i][j] << " ";
			}
			file << std::endl;
		}
	}
}

void Matrice::creer ( unsigned int n, unsigned int m ) {
	if ( ( _n > 0 ) && ( _m > 0 ) ) {
		this->detruire ();
	} 
	
	_n = n;
	_m = m;
	_mat = new float * [n];
	for ( unsigned int i = 0; i < n; i++ ) {
		_mat [i] = new float [m];
		for ( unsigned int j = 0; j < m; j++ ) {
			_mat[i][j] = 0;
		}
	}
}

void Matrice::detruire () {
	if ( ( _n > 0 ) && ( _m > 0 ) ) {
		for ( unsigned int i = 0; i < _n; i++ ) {
			delete [] _mat [i];
		}
		delete [] _mat;
		_m = 0;
		_n = 0;
	}
}

unsigned int Matrice::getNbLigne () const {
	return _n;
}

unsigned int Matrice::getNbColonne () const {
	return _m;
}

float Matrice::getElement ( unsigned int i, unsigned int j ) const {
	if ( ( _m > 0 ) && ( _n > 0 ) ) { //si la matrice existe
		if ( ( i < _n ) && ( j < _m ) ) { //si l element existe
			return _mat [i][j];
		}
	}
}

void Matrice::setElement ( float k, unsigned int i, unsigned int j ) {
	if ( ( _m > 0 ) && ( _n > 0 ) ) { //si la matrice existe
		if ( ( i < _n ) && ( j < _m ) ) { //si l element existe
			_mat [i][j] = k;
		}
	}
}

std::ostream & operator<< ( std::ostream & flux, const Matrice & mat ) {
	if ( ( mat._n  > 0 ) && ( mat._m > 0 ) ) {
		for ( unsigned int i = 0; i < mat._n; i++ ) {
			for ( unsigned int j = 0; j < mat._m; j++ ) {
				flux << mat._mat[i][j] << " ";
			}
			flux << std::endl;
		}

	} else {
		flux << "Empty" << std::endl;
	}

	return flux;
}

void Matrice::operator= ( const Matrice & mat ) {
	if ( ( mat._n > 0 ) && ( mat._m > 0 ) ) {
        	this->creer ( mat._n, mat._m );
        	for ( unsigned int i = 0; i < _n; i++ ) {
            		for ( unsigned int j = 0; j < _m; j++ ) {
                		_mat[i][j] = mat._mat[i][j];
            		}
        	}
	}

}

Matrice Matrice::operator+ ( const Matrice & mat ) {
	return this->add ( mat );
}

Matrice Matrice::operator+ ( float k ) {
	return this->add ( k );
}

Matrice Matrice::operator* ( const Matrice & mat ) {
	return this->prod ( mat );
}

Matrice Matrice::operator* ( float k ) {
	return this->prod ( k ); 
}
