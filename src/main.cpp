#include <iostream>
#include "Vecteur.hpp"
#include "Matrice.hpp"
#include "MatriceCarree.hpp"

using namespace std;

int main ( int argc, char ** argv ) {
	Matrice m3;
	Matrice m4 ( "matrice.txt" );

	cout << m4 << endl;

	m3 = m4.add ( 98 );
	m3 = m4.prod ( 5 );	
	m3 = m3.add ( m4 );
	m3 = m3.transpose ();
	cout << m3 << endl;
	m3 = m3.prod ( m4 );	
	cout << m3 << endl;

	return 0;
 }
