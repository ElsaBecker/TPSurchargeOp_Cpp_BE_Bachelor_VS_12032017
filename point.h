#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class point
{

	int a, b;

public:
	
	

	point(int abs = 0, int ord = 0)  //constructeur
	{
		a = abs; b = ord;
	}
	~point();


	//constructeur par recopie
	point(point& cop)  
	{
		a = cop.a; b = cop.b;
	}

	


	//Afficher les coordonnées des points
	void affichepoints() const
	// BUT : Afficher les données membres de la classe point
	// ENTREE : 
	// SORTIE : affichage des données membres
	{
		cout << a << "  " << b << endl;
	}


	//surdéfinition opérateurs opérandes et comparaisons avec fonction membre
	point operator+ (point) const; //Surcharge de l'opérateur +
	point operator- (point) const; //Surcharge de l'opérateur -
	void operator+= (point const&); //Surcharge de l'opérateur += (addition simplifiée)
	void operator-= (point const&); //Surcharge de l'opérateur -= (soustraction simplifiée)
	void operator*= (point const&); //Surcharge de l'opérateur *= (multiplication simplifiée)
	void operator/= (point const&); //Surcharge de l'opérateur /= (division simplifiée)
	bool operator== (point const&); //Surcharge de l'opérateur ==
	bool operator!= (point const&); //Surcharge de l'opérateur !=


	//surdéfinition opérateur cin et cout avec fonction amie
	friend ostream& operator<<(ostream& os, const point& mp); //surcharge cout
	friend istream& operator >> (istream& is, point& mp); //surcharge cin

	//Surdéfinition opérateurs new et delete avec fonction membre
	void* operator new(size_t taille);
	void operator delete(void* f);

	//Surdéfinition opérateur indexation avec fonction membre
	int operator[] (int index);



	int getRound() const;


};

