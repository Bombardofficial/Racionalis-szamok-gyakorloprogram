#include <iostream>
#include "tarolo.h"
#include <cstdlib>
#include "racionalis.h"
#include "feladatsor.h"
using namespace std;
int main()
{
	cout << "Udvozollek a racionalis szamok vilagaban!\n" << endl;
	srand((unsigned int)time(NULL));
	foprogram fp;
	fp.gyakoroltatas();
	return 0;
}
