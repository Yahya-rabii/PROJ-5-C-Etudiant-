#include "Header.h"
#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

int Etudiant::cpt = 0;

Etudiant::Etudiant():matricule(++cpt)
{
	//this->matricule = 0;
	this->nom = new char[10];
	strcpy(this->nom, "NULL");
	this->nbrNotes = 0;
	this->tabNotes = new float[0];
	

}

Etudiant::Etudiant(int mat, char* nm, int nbrN) :matricule(++cpt)
{

	//this->matricule = mat;
	this->nom = new char[strlen (nm)+1];
	strcpy_s( this->nom , strlen(nm) + 1 , nm );
	this->nbrNotes = nbrN;
	this->tabNotes = new float[nbrN];
	this->saisie();



}

Etudiant::Etudiant(const Etudiant& c):matricule(++cpt)
{

	//this->matricule = c.matricule;

	this->nom = new char[strlen(c.nom) + 1];
	
	strcpy_s(this->nom, strlen(c.nom) + 1, c.nom);

    this->nbrNotes = c.nbrNotes;

	this->tabNotes = new float[this->nbrNotes];
	
	for (int i = 0; i < this->nbrNotes; i++)
	{
		this->tabNotes[i] = c.tabNotes[i];
	}

}

Etudiant::~Etudiant()
{

	delete [] this->nom;
	delete [] this->tabNotes;

	this->nom = nullptr;
	this->tabNotes = 0;

	cout << "the object was deleted" << endl;

}

bool Etudiant::operator==(const Etudiant& c)const
{

	return (this->moyenne() == c.moyenne());
	

}

Etudiant Etudiant::operator=(const Etudiant& c)
{

	if (this != &c) {
		
		delete[] this->nom ;
		this->nom = nullptr;


		//this->matricule = c.matricule; imposible d'initialiser le matricule  

		this->nom = new char[strlen(c.nom) + 1];

		strcpy_s(this->nom, strlen(c.nom) + 1, c.nom);

		this->nbrNotes = c.nbrNotes;

		////////////////////////////////////////////////////////////

		delete[] this->tabNotes;
		this->tabNotes = nullptr;

		this->tabNotes = new float[this->nbrNotes];

		for (int i = 0; i < this->nbrNotes; i++)
		{
			this->tabNotes[i] = c.tabNotes[i];
		}

	}
	return *this;
}

void Etudiant::saisie()
{
	int i = 0;

	for (i = 0; i < this->nbrNotes; i++) {

		cout << "note" << i+1 << " : " ;
		cin >> this->tabNotes [i] ;
		cout << endl;

	}


}

void Etudiant::affichage() const
{
	int i=0;
	
	cout << "le matricule : ";
	cout << this->matricule << endl;

	cout << "le nom : ";
	cout << this->nom << endl;

	cout << "le nombre de note : ";
	cout << this->nbrNotes << endl;

	cout << "les notes : "<< endl;
	cout << endl;

	for (i = 0; i < this->nbrNotes; i++) {

		cout << "note" << i + 1 << " : ";
		cout << this->tabNotes[i] << endl;


	}

	float mo = this->moyenne();
    cout << "la moyenne  : ";
	cout << mo ;
	cout << endl;

	if (this->admis()) {

		cout << "l'etudiant admis" << endl;

	}

	else {

		cout << "l'etudiant non admis" << endl;


	}

}

float Etudiant::moyenne() const 
{

	//assert(this->nbrNotes > 0);//MODE DEBUG

	float somme=0;

	int i=0;
	
	float moy=0;

	if (this->nbrNotes != 0) {

		for (i = 0; i < this->nbrNotes; i++) {

			somme = somme + this->tabNotes[i];

		}

		moy = somme / (this->nbrNotes);

		return moy;
	}

	else {

		return 0;

	}
}

bool Etudiant::admis() const 
{
	
	if (this->moyenne() >= 10) {

		return true;
	}
	 
	else {

		return false;
	}

}

bool Etudiant::comparer(const Etudiant  &e) const
{
	if (this->moyenne() == e.moyenne() ) {

		return true;
	}

	else {

		return false;
	}

}


