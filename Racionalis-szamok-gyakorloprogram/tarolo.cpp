#include "tarolo.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include "racionalis.h"
using namespace std;



void tarolo::menu()
{
	cout << "Valaszd ki a szamodra megfelelo szintet:" << endl << endl;

	cout << "	1. Konnyu" << endl;
	cout << "	2. Halado" << endl;
	cout << "	3. Nehez" << endl;
	cout << "	4. Brutalis" << endl << endl;
}

void tarolo::lehetosegek()
{
	racionalis r;
	int lehetoseg = 0;
	cout << ">";
	cin >> lehetoseg;
	system("cls");

	switch (lehetoseg) {
	case 1:
		r.konnyu();
		break;
	case 2:
		r.halado();
		break;
		case 3:
		r.nehez();
		break;
	case 4:
		r.brutalis();
		break;
	default:
		cout << "Hibas bevitel. Probald ujra!" << endl;
		string l;
		cin.clear();
		getline(cin, l);
		//lehetosegek();
		break;
	}
}

void tarolo::szamologep()
{
	menu();
	lehetosegek();
}
