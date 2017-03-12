#include "point.h"

int Round = 0; //Variable pour tester les fonctions new et delete


point::~point()
{
}

point point::operator+(point n) const 
// BUT : Surcharger l'opérateur +
// ENTREE : nouveau point auquel aditionner les coordonnées du point de base
// SORTIE : renvoie d'un point dont les coordonnées sont la somme des autres points
{
	point p;
	p.a = a + n.a;
	p.b = b + n.b;
	return p;
}

point point::operator-(point n) const
// BUT : Surcharger l'opérateur -
// ENTREE : nouveau point n que l'on soustrait au point de base
// SORTIE : renvoie un point qui est la soutraction entre les coordonnées du premier point et celle du deuxieme
{
	point m;
	m.a = a - n.a;
	m.b = b - n.b;
	return m;
}

void point::operator+=(point const &n)
// BUT : Surcharger l'operateur +=
// ENTREE : l'adresse d'un point n
// SORTIE : ajoute les coordonnées du point n à celles du point appelant
{
	a += n.a;
	b += n.b;
}

void point::operator-=(point const &n)
// BUT : Surcharger l'operateur -=
// ENTREE : l'adresse d'un point n
// SORTIE : soustrait les coordonnées du point n à celles du point appelant
{
	a -= n.a;
	b -= n.b;
}

void point::operator*=(point const &n)
// BUT : Surcharger l'operateur *=
// ENTREE : l'adresse d'un point n
// SORTIE : multiplie les coordonnées du point n et celles du point appelant
{
	a *= n.a;
	b *= n.b;
}

void point::operator/=(point const &n)
// BUT : Surcharger l'operateur /=
// ENTREE : l'adresse d'un point n
// SORTIE : divise les coordonnées du point appelant par celles du point n
{
	a /= n.a;
	b /= n.b;
}

bool point::operator==(point const &n)
// BUT : Surcharger l'operateur ==
// ENTREE : l'adresse d'un point n
// SORTIE : booléen -> true si les coordonnées du point appelant sont les mêmes que celles du point n
{
	
	if ((a == n.a)  && (b == n.b))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool point::operator!=(point const &n)
// BUT : Surcharger l'opérateur !=
// ENTREE : l'adresse d'un point n
// SORTIE : booléen -> true si les coordonnées du point appelant sont différentes de celles du point n
{
	if ((a != n.a) || (b != n.b))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void * point::operator new(size_t taille)
// BUT : Surcharger l'opérateur new
// ENTREE : une taille
// SORTIE : un pointeur avec allocation mémoire
{
	void *ptr = malloc(taille);
	Round += 1;

	return ptr;
}

void point::operator delete(void* f)
// BUT : Surcharger l'opérateur delete
// ENTREE : un pointeur f
// SORTIE : libération de la mémoire allouée au pointeur f
{
	free(f);
	Round -= 1;
}

int point::operator[](int index)
// BUT : Surcharger l'opérateur d'indexation []
// ENTREE : un entier qui sert d'index
// SORTIE : retourne une donnée membre en fonction de l'index renseigné
{
	switch (index)
	{
	case 0:
		return a;
		break;
	case 1:
		return b;
		break;
	default:
		return 0;
		break;
	}
}

int point::getRound() const
// BUT : donner la valeur de Round influencée dans operator new et operator delete
// ENTREE :  
// SORTIE : retourne la valeur de l'entier Round
{
	return Round;
}

ostream & operator<<(ostream & os, const point & mp)
// BUT : Surcharge de l'operateur cout
// ENTREE :  un flux de sortie os, et un point mp à afficher 
// SORTIE : renvoie un flux de sortie os qui contient les coordonnées du point concerné
{
	return os << "Coordonnees : " << mp.a << " " << mp.b << endl;
}

istream & operator >> (istream & is, point & mp)
// BUT : Surcharge de l'operateur cin
// ENTREE : un flux d'entrée, un point mp à modifier par l'utilisateur
// SORTIE : 2 coordonnées saisies par l'utilisateur et stockées dans un point
{
	int x, y;

	cout << "Rentrez la valeur de la premiere coordonnee : " << endl;
	is >> x;
	mp.a = x;

	cout << "Rentrez la valeur de la deuxieme coordonnee : " << endl;
	is >> y;
	mp.b = y;
		
	return is;
}
