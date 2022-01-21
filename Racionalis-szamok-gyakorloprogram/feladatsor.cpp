#include "feladatsor.h"
#include "racionalis.h"

bool feladatsor::vanEFeladat()
{
	return eddigfeladott < feladatszam;
}

int feladatsor::random1()
{
	return rand() % 5 + 1;
}

int feladatsor::random2()
{
	return rand() % 10 + 1;;
}

int feladatsor::random3()
{
	return rand() % 30 + 1;;
}

int feladatsor::random_muv_nehez()
{
	return rand() % 20 + 1;
}
int feladatsor::random_muv_halado() 
{
	return rand() % 10 + 1;
}

void konnyufeladatsor::szintleiras() 
{
	cout << "Konnyu szint :\n\n	- 10 feladat kovetkezik\n	- Muveletek: szorzas\n	- Egyszerusites: nem kotelezo\n\nNyomj Enter-t ha keszen allsz!\n" << endl;
}
string konnyufeladatsor::szint()
{
	return "konnyu";
}

string konnyufeladatsor::ajanloSzoveg()
{
	return "";
}

void haladofeladatsor::szintleiras()
{
	cout << "Halado szint :\n\n	- 10 feladat kovetkezik\n	- Muveletek: szorzas es osztas\n	- Egyszerusites: nem kotelezo\n\nNyomj Enter-t ha keszen allsz!\n" << endl;
}
string haladofeladatsor::szint()
{
	return "halado";
}
string haladofeladatsor::ajanloSzoveg()
{
	return "Lepj tovabb a kovetkezo szintre, hogy tesztelhesd tudasod osztasnal es szorzasnal egyarant!";
}
void nehezfeladatsor::szintleiras()
{
	cout << "Nehez szint :\n\n	- 15 feladat kovetkezik\n	- Muveletek: osszeadas, kivonas, szorzas es osztas\n	- Egyszerusites: nem kotelezo\n\nNyomj Enter-t ha keszen allsz!\n" << endl;
}
string nehezfeladatsor::szint()
{
	return "nehez";
}
string nehezfeladatsor::ajanloSzoveg()
{
	return "Lepj tovabb a kovetkezo szintre, hogy tesztelhesd tudasod osszeadasnal, kivonasnal, osztasnal, szorzasnal egyarant!";
}
void brutalisfeladatsor::szintleiras()
{
	cout << "Brutalis szint :\n\n	- 15 feladat kovetkezik komplex szamokkal\n	- Muveletek: osszeadas, kivonas, szorzas es osztas\n	- Egyszerusites: kotelezo, redukalt alakra (!!!)\n\nNyomj Enter-t ha keszen allsz!\n" << endl;
}

string brutalisfeladatsor::szint()
{
	return "brutalis";
}

string brutalisfeladatsor::ajanloSzoveg()
{
	return "Lepj tovabb a kovetkezo szintre, hogy tesztelhesd tudasod osszeadasnal, kivonasnal, osztasnal es szorzasnal egyarant komplexebb szamokkal tobb feladat formalyaban!";
}


feladatsor* foprogram::kovetkezoFeladatsor(statisztika s1)
{
	// ha nem volt még kitöltött dolgozat --> könnyû
	if (s1.getOsszes() == 0) {
		szint = 1;
	}
	// ha tökéletes volt az elõzõ dolgozata, akkor továbbléphet.
	else {
		if (s1.getJokSzama() == s1.getOsszes()) {
			szint++;
		}
	}

	switch (szint) {
	case 1: return new konnyufeladatsor();
	case 2: return new haladofeladatsor();
	case 3: return new nehezfeladatsor();
	case 4: return new brutalisfeladatsor();
	default: return nullptr;
	}

}




void foprogram::gyakoroltatas()
{
	statisztika s1;
	feladatsor* f1 = kovetkezoFeladatsor(s1);
	char megegy = '-';
	do {
		
		
		f1->szintleiras();
		system("pause");
		system("cls");
		s1 = f1->folyamat();
		delete f1;
		if (s1.getJokSzama() < s1.getOsszes() * 0.5) { // < s1.getOsszes() * 0.5
			cout << "Sajnos az eredmeny nem valami fenyes. " << s1.getJokSzama() << " feladat helyes a "<< s1.getOsszes()<<"-bol.\nProbald meg megegyszer!" << endl;
		}
		else if (s1.getJokSzama() < s1.getOsszes() * 0.8 && s1.getJokSzama() >= s1.getOsszes() * 0.5) {
			cout << "Egesz jol sikerult! " << s1.getJokSzama() << " feladat helyes a " << s1.getOsszes() << "-bol.\nProbald meg meg jobb eredmenyt elerni!" << endl;
		}
		else if (s1.getJokSzama() < s1.getOsszes() && s1.getJokSzama() >= s1.getOsszes() * 0.8) {
			cout << "Szep munka! " << s1.getJokSzama() << " feladat helyes a " << s1.getOsszes() << "-bol.\nHa hibatlan lesz, akkor tovabblephetsz a kovetkezo szintre!" << endl;
		}
		else {
			f1 = kovetkezoFeladatsor(s1);
			cout << "Gratulalok! " << s1.getJokSzama() << " feladat helyes a " << s1.getOsszes() << "-bol.\nHibatlan! " << endl;
			if (f1 != nullptr) {
				cout << f1->ajanloSzoveg() << endl;
				cout << "\n\nSzeretned kiprobalni magad " << f1->szint() << " szinten? (y / n)" << endl << endl;
				
				cin >> megegy;
				switch (megegy) {
				case 'y':
					system("cls");
					break;
				case 'n':
					break;
				default:
					cout << "\nValaszd az 'y' betut ha szeretned tovabbfolytani vagy az 'n' betut ha befejezni szeretne a program hasznalatat!" << endl;
					break;
				}
			}
		}
	} while (f1 != nullptr && megegy == 'y' || s1.getJokSzama() != s1.getOsszes());

}

statisztika feladatsor::folyamat()
{
	statisztika s;
	while (this->vanEFeladat()) {
		feladat *f = this->kovetkezoFeladat();
		f->kiir();
		int szaml_er;
		cout << "Mi lesz a szamlalo?\n>";
		cin >> szaml_er;
		cout << "\n";
		int nev_er;
		cout << "Mi lesz a nevezo?\n>";
		cin >> nev_er;
		racionalis beadott(szaml_er, nev_er);
		//egyenloe / pontosanegyenloe()
		if (f->ellenorzes(beadott)) //A TOBBI BEADOTT.EGYENLOE NEVU FUGGVENNYEL MEGY KOVETKEZO ORA
		{
			cout << "\nJo megoldas!\n" << endl;
			s.jo();
		}
		else {
			cout << "\nNem jo megoldas!\n" << endl;
			s.rossz();
		}
		if (this->vanEFeladat()) {
			cout << "Johet a kovetkezo feladat?\nNyomj Enter-t a folytatashoz!\n" << endl;
			system("pause");
			system("cls");
		}
		delete f;
	}
	cout << "Vege a feladatsornak. Nezd meg az eredmenyt!\nNyomj Enter-t a folytatashoz!\n" << endl;

	system("pause");
	system("cls");
	return s;
}

feladat* konnyufeladatsor::kovetkezoFeladat()
{
	eddigfeladott++;
	racionalis a(random1(), random1());
	racionalis b(random1(), random1());
	feladat *f = new feladat(a, '*', b);
	
	return f;
	
	// egy db feladat elõállítása és visszaadása
}

feladat* haladofeladatsor::kovetkezoFeladat()
{
	racionalis elvart;
	racionalis a(random2(), random1());
	racionalis b(random2(), random1());
	char muvjel = (rand() % 2 == 0) ? '*' : '/';
	feladat *f = new feladat(a, muvjel, b);

	return f;
}



feladat* nehezfeladatsor::kovetkezoFeladat()
{
	racionalis elvart;
	racionalis a(random2(), random2());
	racionalis b(random2(), random2());
	char muvjel = '-';
	switch (rand() % 4) {
	case 0: muvjel = '*'; break;
	case 1: muvjel = '/'; break;
	case 2: muvjel = '+'; break;
	case 3: muvjel = '-'; break;
	default: muvjel = '-'; break; // kamuág
	}
	feladat *f = new feladat(a, muvjel, b);

	return f;
	
}

feladat* brutalisfeladatsor::kovetkezoFeladat()
{
	racionalis elvart;
	racionalis a(random3(), random2());
	racionalis b(random3(), random2());
	char muvjel = '-';
	switch (rand() % 4) {
	case 0: muvjel = '*'; break;
	case 1: muvjel = '/'; break;
	case 2: muvjel = '+'; break;
	case 3: muvjel = '-'; break;
	default: muvjel = '-'; break; // kamuág
	}
	brutalisfeladat *f = new brutalisfeladat(a, muvjel, b);

	return f;
	
}

