#include "MatriceCarree.hpp"

MatriceCarree::MatriceCarree () {
	_n = 0; 
	_m = 0;
}

MatriceCarree::MatriceCarree ( unsigned int n ) {
	this->creer ( n, n );
}

MatriceCarree::~MatriceCarree () {

}

MatriceCarree::MatriceCarree ( const char * pathname ) {
	std::ifstream file ( pathname );
	if ( file ) {
		unsigned int n, m;
		file >> n >> m;
		if ( n == m ) {
			this->creer ( n, n );
			for ( unsigned int i = 0; i < n; i++ ) {
				for ( unsigned int j = 0; j < n; j++ ) {
					file >> _mat [i][j];
				} 
			} 
		}
	}
}

int MatriceCarree::determinant () {
	int det = 1;
	MatriceCarree tmp;
	if ( _n > 0 ) { //la matrice existe
		tmp.creer ( _n, _n );
		tmp = *this;
		for ( unsigned int i = 1; i < _n; i++ ) {
			for ( unsigned int k = 0; k < i; k++ ) {
				float coef = tmp._mat[i][k] / tmp._mat[k][k];
				for ( unsigned int j = 0; j < _n; j++ ) { //OELC
					tmp._mat[i][j] = tmp._mat[i][j] -  coef * tmp._mat[k][j];
				}
				std::cout << tmp << std::endl;
			}
		}
		for ( unsigned int i = 0; i < _n; i++ ) {
			det *= tmp._mat[i][i];
		} 
	}

	return det;
}

MatriceCarree & MatriceCarree::inverse () {

}

std::ostream & operator<< ( std::ostream & flux, const MatriceCarree & mat ) {
	flux << (Matrice &)mat;
	return flux;
}
