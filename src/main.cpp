#include <iostream>
#include "Matrice.hpp"

using namespace std;

int main ( int argc, char ** argv ) {
	Matrice m1 ( 6, 5 );
	Matrice m2 ( 6, 5 );
	Matrice m3;

	cout << "M1 :" << endl << m1 << endl;
	cout << "M2 :" << endl << m2 << endl;
		
	m3 = m1.add ( m2 );

	cout << "M3 :" << endl << m3 << endl;	

	return 0; 
}
