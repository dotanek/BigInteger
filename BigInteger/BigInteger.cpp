#include "BigInteger.h"

BigInt BigInteger::Init(string str){

	// Inicjalizacje 

	BigInt A;

	if(str.size() == 0)
		return A;

	while(str.size() % 9 != 0)
		str = "0" + str;

	for(int i = 0; i < str.size(); i += 9){

		int tmp = 0;

		for(int j = 0; j < 9; j++)
			tmp = (tmp * 10) + (str[i+j] - '0');

		A.push_back(tmp);
	}

	return A;

}

BigInt BigInteger::Init(long long integer){

	BigInt A;

	string str = "";

	while(integer > 0){
		
		str = (char)((integer % 10) + '0') + str;

		integer /= 10;
	}

	A = Init(str);

	return A;
}

BigInt BigInteger::Init(unsigned int integer){

	return Init((long long)integer);
}

// Wypisywanie


string BigInteger::toString(BigInt A){

	string str = "";


	if(A.size() == 0)
		return "0";

	for(int i = 0; i < A.size(); i++){

		int tmpInt = A[i];
		string tmpStr = "";

		while(tmpInt > 0){

			tmpStr = (char)((tmpInt % 10) + '0') + tmpStr;

			tmpInt /= 10;
		}

		str += tmpStr;
	}
		
	return str;
}

// Operatory 
