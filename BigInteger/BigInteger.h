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

	bool  operator > (const BigInteger& other) const;
	
	bool operator < (const BigInteger& other) const;

	bool operator == (const BigInteger& other) const;

	bool operator != (const BigInteger& other) const;

	bool operator >= (const BigInteger& other) const;

	bool operator <= (const BigInteger& other) const;

	// Plus

	BigInteger operator + (const BigInteger& other) const;

	BigInteger operator + (const int other) const;

	BigInteger operator ++ (const int);

	void operator += (const BigInteger& other);

	void operator += (const int other);

	// Minus

	BigInteger operator - (const BigInteger& other) const;

	BigInteger operator - (const int other) const;

	BigInteger operator -- (const int);

	void operator -= (const BigInteger& other);

	void operator -= (const int other);

	// Iloczyn

	BigInteger operator * (const BigInteger& other) const;

	BigInteger operator * (const int other) const;

	void operator *= (const BigInteger& other);

	void operator *= (const int other);

	// Modulo

	BigInteger operator % (const BigInteger& other) const;

	BigInteger operator % (const int other) const;

	// Metody pomocnicze

	static void fixZero(BigInt& A); // Usuwanie 0 z vectora.*/
	
};

