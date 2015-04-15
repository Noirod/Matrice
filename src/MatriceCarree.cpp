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

int MatriceCarree::determinant () {

}

MatriceCarree & MatriceCarree::inverse () {

}

std::ostream & operator<< ( std::ostream & flux, const MatriceCarree & mat ) {
	flux << (Matrice &)mat;
	return flux;
}
