#include <iostream>
#include <string>
#include "BigInteger.h"

using namespace std;

int main()
{


	BigInteger A("3432432432");
	BigInteger B("5");

	cout << "A = " << A.toString() << endl;
	cout << "B = " << B.toString() << endl;

	cout << "Greater: " << ((A > B) ? "True!" : "False.") << endl;
	cout << "Lower: " << ((A < B) ? "True!" : "False.") << endl;
	cout << "Equal: " << ((A == B) ? "True!" : "False.") << endl;
	cout << "Diffrent: " << ((A != B) ? "True!" : "False.") << endl;
	cout << "Greater or Equal: " << ((A >= B) ? "True!" : "False.") << endl;
	cout << "Lower or Equal: " << ((A <= B) ? "True!" : "False.") << endl;

	cout << "A + B = " << (A + B).toString() << endl;
	cout << "A - B = " << (A - B).toString() << endl;
	cout << "A * B = " << (A * B).toString() << endl;
	cout << "A % B = " << (A % B).toString() << endl;
	A++;
	cout << "A++: " << A.toString() << endl;
	A--;
	cout << "A--: " << A.toString() << endl;
	A += 10;
	cout << "A += 10: " << A.toString() << endl;
	A -= 10;
	cout << "A -= 10: " << A.toString() << endl;
	A *= 10;
	cout << "A *= 10: " << A.toString() << endl;

	return 0;
}
