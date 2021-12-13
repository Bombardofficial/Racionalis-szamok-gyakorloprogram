#include "racionalis.h"
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

void racionalis::kiiras()
{
	cout << szamlalo << '/' << nevezo << " ";
}

int racionalis::random1()
{
	return rand() % 5 + 1;
}

int racionalis::random2()
{
	return rand() % 10 + 1;;
}

int racionalis::random3()
{
	return rand() % 30 + 1;;
}

bool racionalis::egyenloe(racionalis b) {
	racionalis thisegysz = this->egyszerusites();
	racionalis begysz = b.egyszerusites();
	return thisegysz.szamlalo == begysz.szamlalo && thisegysz.nevezo == begysz.nevezo;
}
bool racionalis::pontosanegyenloe(racionalis b) {
	return this->szamlalo == b.szamlalo && this->nevezo == b.nevezo;
}
racionalis racionalis::reciprok()
{
	return racionalis(nevezo, szamlalo);
}
racionalis racionalis::osztas(racionalis b)
{
	return this->szorzas(b.reciprok());
	//return racionalis(this->szamlalo * b.nevezo, this->nevezo * b.szamlalo);
}

racionalis racionalis::osszeadas(racionalis b)
{
	return racionalis((this->szamlalo*b.nevezo) + (b.szamlalo*this->nevezo), this->nevezo * b.nevezo).egyszerusites();
}

racionalis racionalis::kivonas(racionalis b)
{
	return racionalis((this->szamlalo * b.nevezo) - (b.szamlalo * this->nevezo), this->nevezo * b.nevezo).egyszerusites();
}

racionalis racionalis::egyszerusites()
{
	if (nevezo == 0) {
		cout << szamlalo << "/" << nevezo << " -> ";
		cout << "A nevezo nem lehet negativ, ezaltal nem is egyszerusitheto." << endl << endl;
	}
	else {

		int negativ = 0;
		int egyszerusitett_szamlalo = szamlalo;
		int egyszerusitett_nevezo = nevezo;
		if (szamlalo < 0 || nevezo < 0) {
			egyszerusitett_szamlalo = abs(szamlalo);
			egyszerusitett_nevezo = abs(nevezo);
			negativ++;
		}

		for (int i = egyszerusitett_nevezo * egyszerusitett_szamlalo; i > 1; i--) {

			if ((egyszerusitett_nevezo % i == 0) && (egyszerusitett_szamlalo % i == 0)) {

				egyszerusitett_nevezo /= i;
				egyszerusitett_szamlalo /= i;



			}

		}
		if (negativ > 0) {
			egyszerusitett_szamlalo *= -1;
		}
		//cout << "Egyszerusitve: " << egyszerusitett_szamlalo << "/" << egyszerusitett_nevezo << endl << endl;
		return racionalis(egyszerusitett_szamlalo, egyszerusitett_nevezo);
	}
}

racionalis racionalis::szorzas(racionalis b)
{
	return racionalis(this->szamlalo * b.szamlalo, this->nevezo * b.nevezo).egyszerusites();
}

void racionalis::konnyu() 
{

	cout << "Konnyu szint :\n\n	- 10 feladat kovetkezik\n	- Muveletek: szorzas\n	- Egyszerusites: nem kotelezo\n\nNyomj Enter-t ha keszen allsz!\n" << endl;
	system("pause");
	system("cls");
	muvelet = '*';

	for (int i = 0; i < 10; i++) {
		cout << feladatszam << "/10 feladat\n";
		cout << "______________" << endl<<endl;
		konnyu_feladat();
		feladatszam++;
	}

	if (jomegoldas < 5) {
		cout << "Sajnos az eredmeny nem valami fenyes. "<<jomegoldas << " feladat helyes a tizbol.\nProbald meg megegyszer!" << endl;
	}
	else if (jomegoldas < 8 && jomegoldas >= 5) {
		cout << "Egesz jol sikerult! " << jomegoldas << " feladat helyes a tizbol.\nProbald meg meg jobb eredmenyt elerni!" << endl;
	}
	else if (jomegoldas < 10 && jomegoldas >= 8) {
		cout << "Szep munka! " << jomegoldas << " feladat helyes a tizbol.\nHa hibatlan lesz, akkor tovabblephetsz a kovetkezo szintre!" << endl;
	}
	else {
		cout << "Gratulalok! " << jomegoldas << " feladat helyes a tizbol.\nHibatlan! Lepj tovabb a kovetkezo szintre, hogy tesztelhesd tudasod osztasnal es szorzasnal egyarant!" << endl;
	}

	if (jomegoldas == 10) {
		cout << "\n\nSzeretned kiprobalni magad halado szinten? (y/n)" << endl << endl;
		char megegy;
		cin >> megegy;
		switch (megegy) {
		case 'y':
			system("cls");
			szamlalo = 0;
			nevezo = 0;
			halado();
			break;
		case 'n':
			exit(0);
			break;
		default:
			cout << "\nValaszd az 'y' betut ha szeretned tovabbfolytani vagy az 'n' betut ha befejezni szeretne a program hasznalatat!" << endl;
			break;
		}
	}
	feladatszam = 0;
	jomegoldas = 0;
}

void racionalis::halado() 
{

	cout << "Halado szint :\n\n	- 10 feladat kovetkezik\n	- Muveletek: szorzas es osztas\n	- Egyszerusites: nem kotelezo\n\nNyomj Enter-t ha keszen allsz!\n" << endl;
	system("pause");
	system("cls");

	for (int i = 0; i < 10; i++) {
		cout << feladatszam << "/10 feladat\n";
		cout << "______________" << endl << endl;
		halado_feladat();
		feladatszam++;
	}

	if (jomegoldas < 5) {
		cout << "Sajnos az eredmeny nem valami fenyes. " << jomegoldas << " feladat helyes a tizbol.\nProbald meg megegyszer!" << endl;
	}
	else if (jomegoldas < 8 && jomegoldas >= 5) {
		cout << "Egesz jol sikerult! " << jomegoldas << " feladat helyes a tizbol.\nProbald meg meg jobb eredmenyt elerni!" << endl;
	}
	else if (jomegoldas < 10 && jomegoldas >= 8) {
		cout << "Szep munka! " << jomegoldas << " feladat helyes a tizbol.\nHa hibatlan lesz, akkor tovabblephetsz a kovetkezo szintre!" << endl;
	}
	else {
		cout << "Gratulalok! " << jomegoldas << " feladat helyes a tizbol.\nHibatlan! Lepj tovabb a kovetkezo szintre, hogy tesztelhesd tudasod osszeadasnal, kivonasnal, osztasnal, szorzasnal egyarant!" << endl;
	}

	if (jomegoldas == 10) {
		cout << "\n\nSzeretned kiprobalni magad nehez szinten? (y/n)" << endl << endl;
		char megegy;
		cin >> megegy;
		switch (megegy) {
		case 'y':
			system("cls");
			szamlalo = 0;
			nevezo = 0;
			nehez();
			break;
		case 'n':
			exit(0);
			break;
		default:
			cout << "\nValaszd az 'y' betut ha szeretned tovabbfolytani vagy az 'n' betut ha befejezni szeretne a program hasznalatat!" << endl;
			break;
		}
	}
	feladatszam = 0;
	jomegoldas = 0;
}

void racionalis::nehez() 
{

	cout << "Nehez szint :\n\n	- 15 feladat kovetkezik\n	- Muveletek: osszeadas, kivonas, szorzas es osztas\n	- Egyszerusites: nem kotelezo\n\nNyomj Enter-t ha keszen allsz!\n" << endl;
	system("pause");
	system("cls");

	for (int i = 0; i < 10; i++) {
		cout << feladatszam << "/15 feladat\n";
		cout << "______________" << endl << endl;
		nehez_feladat();
		feladatszam++;
	}

	if (jomegoldas < 8) {
		cout << "Sajnos az eredmeny nem valami fenyes. " << jomegoldas << " feladat helyes a tizenotbol.\nProbald meg megegyszer!" << endl;
	}
	else if (jomegoldas < 13 && jomegoldas >= 8) {
		cout << "Egesz jol sikerult! " << jomegoldas << " feladat helyes a tizenotbol.\nProbald meg meg jobb eredmenyt elerni!" << endl;
	}
	else if (jomegoldas < 15 && jomegoldas >= 13) {
		cout << "Szep munka! " << jomegoldas << " feladat helyes a tizenotbol.\nHa hibatlan lesz, akkor tovabblephetsz a kovetkezo szintre!" << endl;
	}
	else {
		cout << "Gratulalok! " << jomegoldas << " feladat helyes a tizenotbol.\nHibatlan! Lepj tovabb a kovetkezo szintre, hogy tesztelhesd tudasod osszeadasnal, kivonasnal, osztasnal es szorzasnal egyarant komplexebb szamokkal tobb feladat formalyaban!\n" << endl;
	}
	
	if (jomegoldas == 15) {
		cout << "\n\nSzeretned kiprobalni magad brutalis szinten? \nCsak akkor probald ki, ha ugy gondolod maximalisan elsajatitottad a tananyagot! (y/n)" << endl << endl;
		char megegy;
		cin >> megegy;
		switch (megegy) {
		case 'y':
			system("cls");
			szamlalo = 0;
			nevezo = 0;
			brutalis();
			break;
		case 'n':
			exit(0);
			break;
		default:
			cout << "\nValaszd az 'y' betut ha szeretned tovabbfolytani vagy az 'n' betut ha befejezni szeretne a program hasznalatat!" << endl;
			break;
		}
	}
	feladatszam = 0;
	jomegoldas = 0;
}
void racionalis::brutalis() 
{

	cout << "Brutalis szint :\n\n	- 15 feladat kovetkezik komplex szamokkal\n	- Muveletek: osszeadas, kivonas, szorzas es osztas\n	- Egyszerusites: kotelezo, redukalt alakra (!!!)\n\nNyomj Enter-t ha keszen allsz!\n" << endl;
	system("pause");
	system("cls");

	for (int i = 0; i < 10; i++) {
		cout << feladatszam << "/15 feladat\n";
		cout << "______________" << endl << endl;
		brutalis_feladat();
		feladatszam++;
	}

	if (jomegoldas < 8) {
		cout << "Sajnos az eredmeny nem valami fenyes. " << jomegoldas << " feladat helyes a tizenotbol.\nProbald meg megegyszer!" << endl;
	}
	else if (jomegoldas < 13 && jomegoldas >= 8) {
		cout << "Egesz jol sikerult! " << jomegoldas << " feladat helyes a tizenotbol.\nProbald meg meg jobb eredmenyt elerni!" << endl;
	}
	else if (jomegoldas < 15 && jomegoldas >=13) {
		cout << "Szep munka! " << jomegoldas << " feladat helyes a tizenotbol." << endl;
	}
	else {
		cout << "Gratulalok! " << jomegoldas << " feladat helyes a tizenotbol.\nHibatlan!\n" << endl;
	}
	feladatszam = 0;
	jomegoldas = 0;
	cout << "\nNincs tobb szint. Gratulalok! Sikeresen elsajatitottad a racionalis szamokkal torteno muveleteket!";
	exit(0);

}

void racionalis::konnyu_feladat() //viszi az eredmenyt a konnyu()be majd mindig ez lesz meghivva egy uj feladatnal
{

	racionalis a(random1(), random1());
	racionalis b(random1(), random1());

	a.kiiras();
	cout << "* ";
	b.kiiras();
	cout << "= ?\n\n";

	int szaml_er;
	cout << "Mi lesz a szamlalo?\n>";
	cin >> szaml_er;
	cout << "\n";
	int nev_er;
	cout << "Mi lesz a nevezo?\n>";
	cin >> nev_er;

	racionalis elvart = a.szorzas(b);
	cout << "\nEredmeny: ";
	elvart.kiiras();
	racionalis beadott(szaml_er, nev_er);
	if (elvart.egyenloe(beadott))
	{
		cout << "\nJo megoldas!\n" << endl;
		jomegoldas++;
	}
	else {
		cout << "\nNem jo megoldas!\n" << endl;
		
	}

	if (feladatszam == 10) {
		cout << "Vege a feladatsornak. Nezd meg az eredmenyt!\nNyomj Enter-t a folytatashoz!\n" << endl;
		
		system("pause");
		system("cls");
	}
	else {
		cout << "Johet a kovetkezo feladat?\nNyomj Enter-t a folytatashoz!\n" << endl;
		system("pause");
		system("cls");
	}
	
}

int racionalis::random_muv_halado() {
	return rand() % 10 + 1;
}

void racionalis::halado_feladat()
{

	racionalis elvart;
	racionalis a(random2(), random1());
	racionalis b(random2(), random1());
	int random_muv = random_muv_halado();


	a.kiiras();
	if (random_muv >= 5) {
		cout << "/ ";
	}
	else {
		cout << "* ";
	}

	b.kiiras();
	cout << "= ?\n\n";

	int szaml_er;
	cout << "Mi lesz a szamlalo?\n>";
	cin >> szaml_er;
	cout << "\n";
	int nev_er;
	cout << "Mi lesz a nevezo?\n>";
	cin >> nev_er;

	if (random_muv >= 5) {
		elvart = a.osztas(b);
		
	}
	else {
		elvart = a.szorzas(b);
		
	}
	cout << "\nEredmeny: ";
	elvart.kiiras();
	racionalis beadott(szaml_er, nev_er);
	if (elvart.egyenloe(beadott)) {
		cout << "\nJo megoldas!\n" << endl;
		jomegoldas++;
	}
	else {
		cout << "\nNem jo megoldas!\n" << endl;
	}

	if (feladatszam == 10) {
		cout << "Vege a feladatsornak. Nezd meg az eredmenyt!\nNyomj Enter-t a folytatashoz!\n" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "Johet a kovetkezo feladat?\nNyomj Enter-t a folytatashoz!\n" << endl;
		
		system("pause");
		system("cls");
	}
}
int racionalis::random_muv_nehez() 
{
	return rand() % 20 + 1;
}
void racionalis::nehez_feladat()
{
	racionalis elvart;
	racionalis a(random2(), random2());
	racionalis b(random2(), random2());
	int random_muv = random_muv_halado();
	
	a.kiiras();
	if (random_muv <= 5) {
		cout << "/ ";
	}
	else if (random_muv <= 10 && random_muv > 5) {
		cout << "+ ";
	}
	else if (random_muv <= 15 && random_muv > 10) {
		cout << "- ";
	}
	else {
		cout << "* ";
	}
	b.kiiras();
	cout << "= ?\n\n";
	int szaml_er;
	cout << "Mi lesz a szamlalo?\n>";
	cin >> szaml_er;
	cout << "\n";
	int nev_er;
	cout << "Mi lesz a nevezo?\n>";
	cin >> nev_er;

	if (random_muv <= 5) {
		elvart = a.osztas(b);
	}
	else if (random_muv <= 10 && random_muv > 5) {
		elvart = a.osszeadas(b);
	}
	else if (random_muv <= 15 && random_muv > 10) {
		elvart = a.kivonas(b);
	}
	else {
		elvart = a.szorzas(b);
	}
	cout << "\nEredmeny: ";
	elvart.kiiras();
	racionalis beadott(szaml_er, nev_er);
	if (elvart.egyenloe(beadott))
	{
		cout << "\nJo megoldas!\n" << endl;
		jomegoldas++;
	}
	else {
		cout << "\nNem jo megoldas!\n" << endl;

	}

	if (feladatszam == 15) {
		cout << "Vege a feladatsornak. Nezd meg az eredmenyt!\nNyomj Enter-t a folytatashoz!\n" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "Johet a kovetkezo feladat?\nNyomj Enter-t a folytatashoz!\n" << endl;
		
		system("pause");
		system("cls");
	}
}

void racionalis::brutalis_feladat()
{

	racionalis elvart;
	racionalis a(random3(), random2());
	racionalis b(random3(), random2());
	int random_muv = random_muv_nehez();

	
	a.kiiras();
	if (random_muv <= 5) {
		cout << "/ ";
	}
	else if (random_muv <= 10 && random_muv > 5) {
		cout << "+ ";
	}
	else if (random_muv <= 15 && random_muv > 10) {
		cout << "- ";
	}
	else {
		cout << "* ";
	}

	b.kiiras();
	cout << "= ?\n\n";
	int szaml_er;
	cout << "Mi lesz a szamlalo?\n>";
	cin >> szaml_er;
	cout << "\n";
	int nev_er;
	cout << "Mi lesz a nevezo?\n>";
	cin >> nev_er;

	if (random_muv <= 5) {
		elvart = a.osztas(b);
	}
	else if (random_muv <= 10 && random_muv > 5) {
		elvart = a.osszeadas(b);
	}
	else if (random_muv <= 15 && random_muv > 10) {
		elvart = a.kivonas(b);
	}
	else {
		elvart = a.szorzas(b);
	}
	cout << "\nEredmeny: ";
	elvart.kiiras();
	racionalis beadott(szaml_er, nev_er);
	if (elvart.pontosanegyenloe(beadott))
	{
		cout << "\nJo megoldas!\n" << endl;
		jomegoldas++;
	}
	else {
		cout << "\nNem jo megoldas!\n" << endl;

	}

	if (feladatszam == 15) {
		cout << "Vege a feladatsornak. Nezd meg az eredmenyt!\nNyomj Enter-t a folytatashoz!\n" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "Johet a kovetkezo feladat?\nNyomj Enter-t a folytatashoz!\n" << endl;
		
		system("pause");
		system("cls");
	}
}