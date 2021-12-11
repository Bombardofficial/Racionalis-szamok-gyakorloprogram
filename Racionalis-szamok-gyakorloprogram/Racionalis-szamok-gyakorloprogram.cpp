#include <iostream>
#include "tarolo.h"
#include <cstdlib>
#include "racionalis.h"
using namespace std;
int main()
{
	cout << "Udvozollek a racionalis szamok vilagaban!\n" << endl;
	tarolo t;
	srand(time(NULL));

	t.szamologep();
	return 0;
}
