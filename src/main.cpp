#include <iostream>
#include "Vecteur.hpp"
#include "Matrice.hpp"
#include "MatriceCarree.hpp"

using namespace std;

int main ( int argc, char ** argv ) {
	/*Matrice m1 ( 6, 5 );
	Matrice m2 ( 6, 5 );
	Matrice m3;
	Matrice m4 ( "matrice.txt" );

	cout << "M4 :" << endl << m4 << endl;
	m3 = m4.transpose ();
	cout << "tM4 :" << endl << m3 << endl;

	Matrice m5;
	m5 = m4.prod ( m3 );
	cout << "M5 :" << endl << m5 << endl;

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
	*/
/*
	Vecteur v1 ( 5 );
	Vecteur v2 ( 5 );

	v1.setElement ( 1, 0, 0 );
	v1.setElement ( 41, 1, 0 );
	v1.setElement ( 69, 2, 0 );

	v2.setElement ( 9, 0, 0 );
	v2.setElement ( 6, 1, 0 );
	v2.setElement ( 65, 2, 0 );

	cout << "V1 :" << endl << v1 << endl;
	cout << "V2 :" << endl << v2 << endl;

	cout << "V1.V2: " << v1.prodScal ( v2 ) << endl;
	cout << "||V1||: " << v1.norme () << endl; 	
*/

	MatriceCarree mc1 ( 10 );

	cout << mc1 << endl;

	return 0; 
}
