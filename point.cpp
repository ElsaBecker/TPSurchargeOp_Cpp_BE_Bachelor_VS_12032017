#include "point.h"

int Round = 0; //Variable pour tester les fonctions new et delete


point::~point()
{
}

point point::operator+(point n) const 
// BUT : Surcharger l'op�rateur +
// ENTREE : nouveau point auquel aditionner les coordonn�es du point de base
// SORTIE : renvoie d'un point dont les coordonn�es sont la somme des autres points
{
	point p;
	p.a = a + n.a;
	p.b = b + n.b;
	return p;
}

point point::operator-(point n) const
// BUT : Surcharger l'op�rateur -
// ENTREE : nouveau point n que l'on soustrait au point de base
// SORTIE : renvoie un point qui est la soutraction entre les coordonn�es du premier point et celle du deuxieme
{
	point m;
	m.a = a - n.a;
	m.b = b - n.b;
	return m;
}

void point::operator+=(point const &n)
// BUT : Surcharger l'operateur +=
// ENTREE : l'adresse d'un point n
// SORTIE : ajoute les coordonn�es du point n � celles du point appelant
{
	a += n.a;
	b += n.b;
}

void point::operator-=(point const &n)
// BUT : Surcharger l'operateur -=
// ENTREE : l'adresse d'un point n
// SORTIE : soustrait les coordonn�es du point n � celles du point appelant
{
	a -= n.a;
	b -= n.b;
}

void point::operator*=(point const &n)
// BUT : Surcharger l'operateur *=
// ENTREE : l'adresse d'un point n
// SORTIE : multiplie les coordonn�es du point n et celles du point appelant
{
	a *= n.a;
	b *= n.b;
}

void point::operator/=(point const &n)
// BUT : Surcharger l'operateur /=
// ENTREE : l'adresse d'un point n
// SORTIE : divise les coordonn�es du point appelant par celles du point n
{
	a /= n.a;
	b /= n.b;
}

bool point::operator==(point const &n)
// BUT : Surcharger l'operateur ==
// ENTREE : l'adresse d'un point n
// SORTIE : bool�en -> true si les coordonn�es du point appelant sont les m�mes que celles du point n
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
// BUT : Surcharger l'op�rateur !=
// ENTREE : l'adresse d'un point n
// SORTIE : bool�en -> true si les coordonn�es du point appelant sont diff�rentes de celles du point n
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
// BUT : Surcharger l'op�rateur new
// ENTREE : une taille
// SORTIE : un pointeur avec allocation m�moire
{
	void *ptr = malloc(taille);
	Round += 1;

	return ptr;
}

void point::operator delete(void* f)
// BUT : Surcharger l'op�rateur delete
// ENTREE : un pointeur f
// SORTIE : lib�ration de la m�moire allou�e au pointeur f
{
	free(f);
	Round -= 1;
}

int point::operator[](int index)
// BUT : Surcharger l'op�rateur d'indexation []
// ENTREE : un entier qui sert d'index
// SORTIE : retourne une donn�e membre en fonction de l'index renseign�
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
// BUT : donner la valeur de Round influenc�e dans operator new et operator delete
// ENTREE :  
// SORTIE : retourne la valeur de l'entier Round
{
	return Round;
}

ostream & operator<<(ostream & os, const point & mp)
// BUT : Surcharge de l'operateur cout
// ENTREE :  un flux de sortie os, et un point mp � afficher 
// SORTIE : renvoie un flux de sortie os qui contient les coordonn�es du point concern�
{
	return os << "Coordonnees : " << mp.a << " " << mp.b << endl;
}

istream & operator >> (istream & is, point & mp)
// BUT : Surcharge de l'operateur cin
// ENTREE : un flux d'entr�e, un point mp � modifier par l'utilisateur
// SORTIE : 2 coordonn�es saisies par l'utilisateur et stock�es dans un point
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
