#include <iostream>
#include <string>
#include "BigInteger.h"
#include <time.h>

using namespace std;

BigInteger generateRandom(){

	BigInteger A;

	int integer;

	for (int i = 0; i < 14; i++) {

		integer = 0;

		for(int j = 0; j < 9; j++) {
		
			integer *= 10;
			integer += rand()%10;
		}

		A.pushBack(integer);
	}

	A.pushBack(10 + rand() % 90);

	return A;
}

int main()
{
	srand(time(NULL));

	BigInteger A = generateRandom();
	BigInteger B = generateRandom();
	BigInteger C = generateRandom();

	/*BigInteger A("123456789");
	BigInteger B("11111119999");
	BigInteger C("22222229999");*/

	cout << "A = " << A.toString() << endl;
	cout << "B = " << B.toString() << endl;
	cout << "C = " << C.toString() << endl;

	/*cout << "Greater: " << ((A > B) ? "True!" : "False.") << endl;
	cout << "Lower: " << ((A < B) ? "True!" : "False.") << endl;
	cout << "Equal: " << ((A == B) ? "True!" : "False.") << endl;
	cout << "Diffrent: " << ((A != B) ? "True!" : "False.") << endl;
	cout << "Greater or Equal: " << ((A >= B) ? "True!" : "False.") << endl;
	cout << "Lower or Equal: " << ((A <= B) ? "True!" : "False.") << endl;

	cout << "A + B = " << (A + B).toString() << endl;
	cout << "A - B = " << (A - B).toString() << endl;
	cout << "A * B = " << (A * B).toString() << endl;
	cout << "A % B = " << (A % B).toString() << endl;
	cout << "A / B = " << (A / B).toString() << endl;
	cout << "A^B = " << (A^B).toString() << endl;
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
	A /= 10;
	cout << "A /= 10: " << A.toString() << endl;*/
	//cout << "A^B = " << (A ^ B).toString() << endl;

	//BigInteger p = generateRandom();

	//cout << "p = " << p.toString() << endl;

	cout << "Modular exponent A^B mod C = " << BigInteger::modularExponent(A, B, C).toString() << endl;


	return 0;
}
