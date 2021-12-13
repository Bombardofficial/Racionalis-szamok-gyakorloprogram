#pragma once

class racionalis
{
public:
	racionalis(int szamlalo = 0, int nevezo = 1) : szamlalo(szamlalo), nevezo(nevezo) {}
	void kiiras();
	bool egyenloe(racionalis b);
	bool pontosanegyenloe(racionalis b);
	void konnyu();
	void halado();
	void nehez();
	void brutalis();
	void brutalis_feladat();
	void nehez_feladat();
	void halado_feladat();
	void konnyu_feladat();
	racionalis szorzas(racionalis b);
	racionalis osztas(racionalis b);
	racionalis osszeadas(racionalis b);
	racionalis kivonas(racionalis b);
	racionalis egyszerusites();
	racionalis reciprok();
	
	int random1();
	int random2();
	int random3();
	int random_muv_halado();
	int random_muv_nehez();
private:
	int nevezo;
	int szamlalo;
	int jomegoldas=0;
	int feladatszam = 1;
	char muvelet;
};

