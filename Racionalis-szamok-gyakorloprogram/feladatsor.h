#pragma once
#include "feladat.h"


class statisztika {
public:
	statisztika() : eddigfeladott(0), jokSzama(0) {}
	void jo() { eddigfeladott++; jokSzama++; }
	void rossz() { eddigfeladott++; }
	int getJokSzama() { return jokSzama; }
	int getOsszes() { return eddigfeladott; }

private:
	int eddigfeladott;
	int jokSzama;
};

class feladatsor
{
public:
	feladatsor(int db) :feladatszam(db), eddigfeladott(0) {}
	bool vanEFeladat();
	virtual feladat* kovetkezoFeladat() = 0;
	virtual void szintleiras() = 0;
	virtual string szint() = 0;
	virtual string ajanloSzoveg() = 0;
	statisztika folyamat();
	int random1();
	int random2();
	int random3();
	int random_muv_nehez();
	int random_muv_halado();
protected:
	int feladatszam;
	int eddigfeladott;
}; //S.O.L.I.D. elvek, SRP - single responsibility principle , Uncle Bob (Robert C. Martin)

class foprogram {
public:
	foprogram() : szint(0) {}
	
	feladatsor* kovetkezoFeladatsor(statisztika s1);
	void gyakoroltatas();

private:
	int szint; // 0 - meg semmi nem volt, 1 - konnyu, 2 - halado, 3 - nehez, 4 - brutalis
};




class konnyufeladatsor : public feladatsor {
public:
	konnyufeladatsor() : feladatsor(10) {}
	feladat* kovetkezoFeladat();
	void szintleiras();
	string szint();
	string ajanloSzoveg();
};
class haladofeladatsor : public feladatsor {
public:
	haladofeladatsor() : feladatsor(10) {}
	feladat* kovetkezoFeladat();
	void szintleiras();
	string szint();
	string ajanloSzoveg();
};
class nehezfeladatsor : public feladatsor {
public:
	nehezfeladatsor() : feladatsor(15) {}
	feladat* kovetkezoFeladat();
	void szintleiras();
	string szint();
	string ajanloSzoveg();
};
class brutalisfeladatsor : public feladatsor {
public:
	brutalisfeladatsor() : feladatsor(15) {}
	feladat* kovetkezoFeladat();
	void szintleiras();
	string szint();
	string ajanloSzoveg();
};
