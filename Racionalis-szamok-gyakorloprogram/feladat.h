#pragma once
#include "racionalis.h"
class feladat
{

public:
	feladat(racionalis bal, char muvelet, racionalis jobb) : bal(bal), muvelet(muvelet), jobb(jobb) {}
	bool ellenorzes(racionalis tipp);
	void kiir();
	bool egyenlosegvizsgalat(racionalis elvart, racionalis tipp);

private:
	char muvelet;
	racionalis bal;
	racionalis jobb;

};

class brutalisfeladat : public feladat {
public:
	brutalisfeladat(racionalis bal, char muvelet, racionalis jobb) : feladat(bal, muvelet, jobb) {}
	bool egyenlosegvizsgalat(racionalis elvart, racionalis tipp);
};

