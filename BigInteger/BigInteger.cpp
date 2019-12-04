#include "BigInteger.h"

// Inicjalizacje 

BigInteger::BigInteger(){}

BigInteger::BigInteger(string str){

	if(str.size() == 0){

		this->value.push_back(0);
		return;
	}

	BigInt A;

	while(str.size() % 9 != 0)
		str = "0" + str;

	for(int i = 0; i < (int)str.size(); i += 9){
	
		int tmpInt = 0;

		for(int j = i; j < i + 9; j++)
			tmpInt = (tmpInt) * 10 + (str[j] - '0');
		
		A.insert(A.begin(), tmpInt);
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

BigInteger::BigInteger(BigInt bigInt){

	this->value = bigInt;
}

// Wypisywanie


string BigInteger::toString(){

	BigInt A = this->value;

	if(A.size() == 0)
		return "0";
	else if(A.back() == 0)
		return "0";

	string str = "";

	fixZero(A);

	for(int i = 0; i < (int)A.size()-1; i++){

		int tmpInt = A[i];
		string tmpStr = "";

		for(int j = 0; j < 9; j++){

			tmpStr = (char)((tmpInt % 10) + '0') + tmpStr;

			tmpInt /= 10;
		}

		str = tmpStr + str;
	}

	int tmpInt = A.back();

	while(tmpInt > 0){

		str = (char)((tmpInt % 10) + '0') + str;

		tmpInt /= 10;
	}
		
	return str;
}

// Operatory 

bool BigInteger::operator > (BigInteger& other){

	BigInt A = this->value;
	BigInt B = other.value;

	fixZero(A);
	fixZero(B);

	if(A.size() != B.size())	
		return (A.size() > B.size());	// Zakladamy ze oba nie sa puste, bo inaczej A = { 0 } > B = {}, mimo ze obie sa 0.
		
	if(A.size() == 0)
		return false;
	
	while(A.size() > 0){

		if(A.back() > B.back())
			return true;
		else if(A.back() < B.back())
			return false;
		
		A.pop_back();
		B.pop_back();
	}

	return false;
}

bool BigInteger::operator < (BigInteger& other){

	return (other > *this);
}

bool BigInteger::operator == (BigInteger& other){

	BigInt A = this->value;
	BigInt B = other.value;

	fixZero(A);
	fixZero(B);

	if(A.size() != B.size())
		return false;

	while(A.size() > 0){

		if(A.back() != B.back())
			return false;

		A.pop_back();
		B.pop_back();
	}

	return true;
}

bool BigInteger::operator != (BigInteger& other){

	return !(*this == other);
}

bool BigInteger::operator >= (BigInteger& other){

	return (*this == other) or (*this > other);
}

bool BigInteger::operator <= (BigInteger& other){

	return (*this < other) or (*this == other);

}

// Plus

BigInteger BigInteger::operator + (BigInteger& other){

	BigInt A = this->value;
	BigInt B = other.value;

	fixZero(A);
	fixZero(B);

	BigInt C;

	int carry = 0;

	int size = (A.size() > B.size()) ? A.size() : B.size();

	for(int i = 0; i < size; i++){
	
		if(i < (int)A.size())
			carry += A[i];

		if(i < (int)B.size())
			carry += B[i];

		C.push_back(carry % base);
		carry /= base;
	}

	if(carry != 0)
		C.push_back(carry);

	fixZero(C);

	return BigInteger(C);
}

BigInteger BigInteger::operator + (int other){

	BigInteger B(other);

	return *this + B;
}

BigInteger BigInteger::operator ++ (int){

	*this = *this + 1;

	return *this;
}

void BigInteger::operator += (BigInteger& other){

	*this = *this + other;
}

void BigInteger::operator += (int other){

	BigInteger B(other);

	*this = *this + B;
}

// Minus

BigInteger BigInteger::operator - (BigInteger& other){

	if(*this < other)
		return BigInteger(0);

	BigInt A = this->value;
	BigInt B = other.value;

	fixZero(A);
	fixZero(B);

	BigInt C;

	int carry = 0;

	for(int i = 0; i < (int)A.size(); i++){
	
		carry += A[i] - ((i < (int)B.size()) ? B[i] : 0);

		if(carry < 0){

			C.push_back(carry + base);
			carry = -1;
		}
		else{

			C.push_back(carry);
			carry = 0;
		}
	}

	fixZero(C);

	return BigInteger(C);
}

BigInteger BigInteger::operator - (int other){

	BigInteger B(other);

	return *this - B;
}

BigInteger BigInteger::operator -- (int){

	*this = *this - 1;

	return *this;
}

void BigInteger::operator -= (BigInteger& other){

	*this = *this - other;
}

void BigInteger::operator -= (int other){

	BigInteger B(other);

	*this = *this - B;
}

// Metody pomocniczne

void BigInteger::fixZero(BigInt& A){

	while(A.size() > 1 and A.back() == 0)
		A.pop_back();
}

