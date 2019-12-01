#include "BigInteger.h"

// Inicjalizacje 

BigInteger::BigInteger(){}

BigInteger::BigInteger(string str){

	if(str.size() == 0)
		*this = BigInteger();

	BigInt A;

	while(str.size() % 9 != 0)
		str = "0" + str;

	for(int i = 0; i < (int)str.size(); i += 9){

		int tmp = 0;

		for(int j = 0; j < 9; j++)
			tmp = (tmp * 10) + (str[i+j] - '0');

		A.push_back(tmp);
	}

	this->value = A;
}

BigInteger::BigInteger(long long integer){

	string str = "";

	while(integer > 0){
		
		str = (char)((integer % 10) + '0') + str;

		integer /= 10;
	}

	*this = BigInteger(str);	
}

// Wypisywanie


string BigInteger::toString(){

	string str = "";

	BigInt A = this->value;

	if(A.size() == 0)
		return "0";

	for(int i = 0; i < (int)A.size(); i++){

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

bool BigInteger::operator > (BigInteger& other){


	BigInt A = this->value;
	BigInt B = other.value;

	if(A.size() > B.size())
		return true;

	if(A.size() == B.size() and A.size() != 0){
	
		for(int i = 0; i < (int)A.size(); i++){
		
			if(A[i] > B[i])
				return true;
		}
	}

	return false;
}

bool BigInteger::operator < (BigInteger& other){

	return (other > *this);
}

// Metody pomocniczne

void BigInteger::fixZero(BigInt& A){

	while(A.size() > 0 and A[0] == 0)
		A.erase(A.begin());
}

