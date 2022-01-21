#include "feladat.h"
#include <iostream>
using namespace std;

bool feladat::ellenorzes(racionalis tipp)
{
    racionalis elvart;
    if (muvelet == '*') {
        elvart = bal.szorzas(jobb);
    }
    else if (muvelet == '/') {
        elvart = bal.osztas(jobb);
    }
    else if (muvelet == '+') {
        elvart = bal.osszeadas(jobb);
    }
    else if (muvelet == '-') {
        elvart = bal.kivonas(jobb);
    }
    if (egyenlosegvizsgalat(elvart, tipp)) {
        return true;
    }
    else {
        return false;
    }
}

bool feladat::egyenlosegvizsgalat(racionalis elvart, racionalis tipp) {
    return elvart.egyenloe(tipp);
}

void feladat::kiir()
{
    cout << bal << muvelet << jobb  << "=?\n\n";
}

bool brutalisfeladat::egyenlosegvizsgalat(racionalis elvart, racionalis tipp)
{
    return elvart.pontosanegyenloe(tipp);
}
