#include "Header.h"
#include <string.h>
#include <iostream>

using namespace  std;

int main()
{
	     int mat=0;
 cout << "entrer le mat d'etudiant : ";
		cin >> mat;
		cout << endl;


		char nm[20];
cout << "entrer le nom d'etudiant : ";
        cin >> nm;
		cout << endl;
	
		
	    int nbrn=0;
cout << "entrer le nombre de notes d'etudiant : ";
		cin >> nbrn;
		cout << endl;
		
	Etudiant E1(mat,nm,nbrn);

	  		
	E1.affichage();
	
	cout << endl;
	cout << endl;
	
	cout << "entrer le mat d'etudiant : ";
	cin >> mat;
	cout << endl;


	cout << "entrer le nom d'etudiant : ";
	cin >> nm;
	cout << endl;


	cout << "entrer le nombre de notes d'etudiant : ";
	cin >> nbrn;
	cout << endl;
	

	Etudiant E2(mat, nm, nbrn);


	E2.affichage();
		
	
	if (E1.comparer(E2) ){

		cout << "LES DEUX MOYENNES SONT IDENTIQUE" << endl;

	}

	else {

		cout << "LES DEUX MOYENNES SONT DIFFERENT " << endl;

	}
	

}