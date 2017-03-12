#include "point.h"



int main()
{
	point p1(3, 5), p2(1, 2), p3(4, 7), p4(12, 30), res1, res2, copie, putil;
	int i = 0;


	/****** = ******/
	res1 = p1 + p2; // 3  5  +  1  2
	cout << res1 << endl; //affiche   4 7 ;  Opérateur cout surchargé pour afficher directement res1 ( utilisé dans tout le programme)


	/****** - ******/
	res2 = p1 - p2; // 3  5  -  1  2
	cout << res2 << endl;//affiche   2 3


	/****** += ******/
	res2 += res1;   // 2  3  +=  4  7
	cout << res2 << endl; //affiche 6 10


	/****** -= ******/
	res2 -= p3;     // 6  10 -= 4  7
	cout << res2 << endl; // affiche 2 3


	/****** *= ******/
	res2 *= p2;     // 2  3 *= 1  2
	cout << res2 << endl; // affiche 2  6


	/****** /= ******/
	res2 /= p2;      // 2  6 /= 1  2
	cout << res2 << endl;  // affiche 2  3


	/****** == ******/       
	if (res1 == res2) //résultats différents      res 1 = (4,7) ; res2 = (2,3)
	{
		cout << "\n\n Les resultats sont egaux" << endl;
		cout << "A : " << res1 << "B : " << res2 << endl;
	}
	else
	{
		cout << "\n\n Les resultats sont differents" << endl;
		cout << "A : " << res1 << "B : " << res2 << endl;
	}


	if (res1 == p3) //Résultats égaux          res 1 = (4,7) ; p3 = (4,7)
	{
		cout << "\n\n Les resultats sont egaux" << endl;
		cout << "A : " << res1 << "B : " << p3 << endl;
	}
	else
	{
		cout << "\n\n Les resultats sont differents" << endl;
		cout << "A : " << res1 << "B : " << p3 << endl;
	}


	/****** != ******/
	if (res1 != res2) //résultats différents    res 1 = (4,7) ; res2 = (2,3)
	{
		cout << "\n\n Les resultats sont differents" << endl;
		cout << "A : " << res1 << "B : " << res2 << endl;
	}
	else
	{
		cout << "\n\n Les resultats sont egaux" << endl;
		cout << "A : " << res1 << "B : " << res2 << endl;
	}


	if (res1 != p3) //Résultats égaux           res 1 = (4,7) ; p3 = (4,7)
	{
		cout << "\n\n Les resultats sont differents" << endl;
		cout << "A : " << res1 << "B : " << p3 << endl;
	}
	else
	{
		cout << "\n\n Les resultats sont egaux" << endl;;
		cout << "A : " << res1 << "B : " << p3 << endl;
	}


	/****** = ******/
	copie = p4;
	cout << copie << endl; //affiche 12  30


	/****** cin ******/
	cin >> putil;
	cout << putil << endl;


	/****** new et delete  ******/
	point * p = new point(30);
	cout << "Valeur de Round : " << p1.getRound() << endl;
	delete p;
	cout << "Valeur de Round après libération de la mémoire allouée : " << p1.getRound() << endl;


	/****** indexation ******/
	cout << p4[0] << endl; //affiche 12


	system("pause");

	return 0;





}