#pragma once

class Etudiant
{

private:
	const int matricule;
	char* nom;
	int nbrNotes;
	float* tabNotes;
	static int cpt;

public:
	
	Etudiant();
	Etudiant(int mat , char* nm , int nbrN );
	Etudiant(const Etudiant& p); //constructeur de recopie 

	void saisie();
	void affichage()const;
	float moyenne()const;
	bool admis()const;
	bool comparer(const Etudiant &etu )const;
    ~Etudiant();
	bool operator == (const Etudiant & E)const;
	Etudiant operator = (const Etudiant & E);
};