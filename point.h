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

	


	//Afficher les coordonn�es des points
	void affichepoints() const
	// BUT : Afficher les donn�es membres de la classe point
	// ENTREE : 
	// SORTIE : affichage des donn�es membres
	{
		cout << a << "  " << b << endl;
	}


	//surd�finition op�rateurs op�randes et comparaisons avec fonction membre
	point operator+ (point) const; //Surcharge de l'op�rateur +
	point operator- (point) const; //Surcharge de l'op�rateur -
	void operator+= (point const&); //Surcharge de l'op�rateur += (addition simplifi�e)
	void operator-= (point const&); //Surcharge de l'op�rateur -= (soustraction simplifi�e)
	void operator*= (point const&); //Surcharge de l'op�rateur *= (multiplication simplifi�e)
	void operator/= (point const&); //Surcharge de l'op�rateur /= (division simplifi�e)
	bool operator== (point const&); //Surcharge de l'op�rateur ==
	bool operator!= (point const&); //Surcharge de l'op�rateur !=


	//surd�finition op�rateur cin et cout avec fonction amie
	friend ostream& operator<<(ostream& os, const point& mp); //surcharge cout
	friend istream& operator >> (istream& is, point& mp); //surcharge cin

	//Surd�finition op�rateurs new et delete avec fonction membre
	void* operator new(size_t taille);
	void operator delete(void* f);

	//Surd�finition op�rateur indexation avec fonction membre
	int operator[] (int index);



	int getRound() const;


};

