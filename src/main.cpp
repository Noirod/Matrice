#include <iostream>
#include "Vecteur.hpp"
#include "Matrice.hpp"
#include "MatriceCarree.hpp"

using namespace std;

int main ( int argc, char ** argv ) {
	MatriceCarree m ( "matrice2.txt" );
	cout << m << endl;	
	cout << "Determinant: " << m.determinant () << endl;
	return 0;
 }
