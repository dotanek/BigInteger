#include <iostream>
#include <string>
#include "BigInteger.h"

using namespace std;

int main()
{


	BigInteger A("12345673333333333333333333444444444444444444444441111111111112222222222222222222222222123456733333333333333333334444444444444444444444411111111111122222222222222222222222221234567333333333333333333344444444444444444444444111111111111222222222222222222222222212345673333333333333333333444444444444444444444441111111111112222222222222222222222222123456733333333333333333334444444444444444444444411111111111122222222222222222222222221234567333333333333333333344444444444444444444444111111111111222222222222222222222222212345673333333333333333333444444444444444444444441111111111112222222222222222222222222");
	BigInteger B("1234567890");

	cout << "A = " << A.toString() << endl;
	cout << "B = " << B.toString() << endl;

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
	A++;
	cout << "A++: " << A.toString() << endl;
	A--;
	cout << "A--: " << A.toString() << endl;
	A += 10;
	cout << "A += 10: " << A.toString() << endl;
	A -= 10;
	cout << "A -= 10: " << A.toString() << endl;
	A *= 10;
	cout << "A *= 10: " << A.toString() << endl;*/

	cout << (A / 1234567890).toString() << endl;
		

	return 0;
}
