#include "BigInteger.h"
#include <string>

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

	if(integer == 0)
		this->value.push_back(0);

	BigInt A;

	string str = std::to_string(integer);

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

bool BigInteger::operator > (const BigInteger& other) const {

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

bool BigInteger::operator < (const BigInteger& other) const {

	return (other > *this);
}

bool BigInteger::operator == (const BigInteger& other) const {

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

bool BigInteger::operator != (const BigInteger& other) const {

	return !(*this == other);
}

bool BigInteger::operator >= (const BigInteger& other) const {

	return (*this == other) or (*this > other);
}

bool BigInteger::operator <= (const BigInteger& other) const {

	return (*this < other) or (*this == other);

}

// Plus

BigInteger BigInteger::operator + (const BigInteger& other) const {

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

BigInteger BigInteger::operator + (const int other) const {

	BigInteger B(other);

	return *this + B;
}

BigInteger BigInteger::operator ++ (int){

	*this = *this + 1;

	return *this;
}

void BigInteger::operator += (const BigInteger& other){

	*this = *this + other;
}

void BigInteger::operator += (int other){

	BigInteger B(other);

	*this = *this + B;
}

// Minus

BigInteger BigInteger::operator - (const BigInteger& other) const {

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

BigInteger BigInteger::operator - (const int other) const {

	BigInteger B(other);

	return *this - B;
}

BigInteger BigInteger::operator -- (const int){

	*this = *this - 1;

	return *this;
}

void BigInteger::operator -= (const BigInteger& other){

	*this = *this - other;
}

void BigInteger::operator -= (const int other){

	BigInteger B(other);

	*this = *this - B;
}

// Iloczyn

BigInteger BigInteger::operator * (const BigInteger& other) const {

	BigInt A = this->value;
	BigInt B = other.value;

	fixZero(A);
	fixZero(B);

	BigInt C;

	long long carry = 0;
	long long multiply = 0;

	C.assign(A.size() + B.size(), 0);

	for(int i = 0; i < (int)A.size(); i++){
	
		carry = 0;

		for(int j = 0; j < (int)B.size() or carry > 0; j++){

			multiply = C[i + j] + carry + (long long)A[i] * ((j < (int)B.size()) ? B[j] : 0);

			C[i + j] = multiply % base;
			carry = multiply / base;
		}
	}

	fixZero(C);

	return BigInteger(C);
}

BigInteger BigInteger::operator * (const int other) const {

	BigInteger B(other);

	return *this * B;
}

void BigInteger::operator *= (const BigInteger& other){

	*this = *this * other;
}

void BigInteger::operator *= (int other){

	BigInteger B(other);

	*this = *this * B;
}

// Modulo

BigInteger BigInteger::operator % (const BigInteger& other) const {

	BigInt A = this->value;
	BigInt B = other.value;

	fixZero(A);
	fixZero(B);

	if(B.size() == 0)
		return BigInteger(0);	 // Nie dozwolone dzialanie (MOD 0).
	else if(B.size() == 1){

		if(B[0] == 0)
			return BigInteger(0); // J.w.
	}

	BigInt C;
	BigInteger tmp1;
	BigInteger tmp2;

	for(int i = A.size() - 1; i >= 0; i--){

		C.insert(C.begin(), A[i]);

		int x = 0, left = 0, right = base;

		while(left <= right){

			int middle = (left + right) >> 1; // Przesuniecie bitow w prawo o 1 - dziala jak podzielenie przez 2.

			tmp1 = BigInteger(B) * middle;
			tmp2 = BigInteger(C);

			if(tmp1 > tmp2){

				x = middle;
				right = middle - 1;
			}
			else
				left = middle + 1;
		}

		C = (BigInteger(C) - BigInteger(B) * (x - 1)).value;
	}

	fixZero(C);

	return BigInteger(C);
}

BigInteger BigInteger::operator % (const int other) const {

	BigInteger B(other);

	return *this % B;
}


// Metody pomocniczne

void BigInteger::fixZero(BigInt& A){

	while(A.size() > 1 and A.back() == 0)
		A.pop_back();
}

