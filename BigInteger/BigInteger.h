#pragma once
#include <iostream>
#include <vector>

using namespace std;

const int base = 1000000000;

typedef vector<int> BigInt;

class BigInteger{

public:
	BigInt value;

public:

	// Inicjalizacje

	BigInteger();
	
	BigInteger(string str);

	BigInteger(long long integer);

	BigInteger(BigInt bigInt);

	// Wypisywanie

	string toString();

	// Operatory

	// Porownania

	bool operator > (BigInteger& other);
	
	bool operator < (BigInteger& other);

	bool operator == (BigInteger& other);

	bool operator != (BigInteger& other);

	bool operator >= (BigInteger& other);

	bool operator <= (BigInteger& other);

	// Plus

	BigInteger operator + (BigInteger& other);

	BigInteger operator + (int other);

	BigInteger operator ++ (int);

	void operator += (BigInteger& other);

	void operator += (int other);

	// Minus

	BigInteger operator - (BigInteger& other);

	BigInteger operator - (int other);

	BigInteger operator -- (int);

	void operator -= (BigInteger& other);

	void operator -= (int other);

	// Iloczyn

	BigInteger operator * (BigInteger& other);

	BigInteger operator * (int other);

	void operator *= (BigInteger& other);

	void operator *= (int other);

	// Modulo

	BigInteger operator % (BigInteger other);
	int operator % (int other);

	// Metody pomocnicze

	static void fixZero(BigInt& A); // Usuwanie 0 z vectora.*/
	
};

