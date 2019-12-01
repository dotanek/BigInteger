#include <iostream>
#include "BigInteger.h"

using namespace std;

int main()
{

	BigInteger A("10");
	BigInteger B("000000000000000000000000000000000000010");

	cout << A.toString() << endl;
	cout << B.toString() << endl;

	cout << ((A == B) ? "True!" : "False!") << endl;

}
