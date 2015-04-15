#include <iostream>
#include "Matrice.hpp"

using namespace std;

int main ( int argc, char ** argv ) {
	Matrice m1 ( 6, 5 );
	Matrice m2 ( 6, 5 );
	Matrice m3;
	Matrice m4 ( "matrice.txt" );

	cout << "M4 :" << endl << m4 << endl;
	m4 = m4.transpose ();
	cout << "tM4 :" << endl << m4 << endl;

	m4.save ( "t_matrice.txt" );

	m1.setElement ( 5, 0, 0 );
	m1.setElement ( 9, 5, 4 );

	m2.setElement ( 5, 0, 0 );
	m2.setElement ( 9, 5, 4 );

	cout << "M1 :" << endl << m1 << endl;
	cout << "M2 :" << endl << m2 << endl;
		
	m3 = m1.add ( 8 );
	m3 = m3.prod ( 5 );
	cout << "M3 :" << endl << m3 << endl;	
	
	m3 = m1.add ( m2 );
	m3.setElement ( 1, 1, 0 );
	m3.setElement ( 2, 0, 4 );

	cout << "M3 :" << endl << m3 <<endl;

	m3 = m3.transpose ();
	cout << "tM3 :" << endl << m3 << endl;

	return 0; 
}
