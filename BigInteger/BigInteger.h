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

	// Wypisywanie

	string toString();

	// Operatory

	bool operator < (BigInteger& other);
	
	bool operator > (BigInteger& other);

	// Metody pomocnicze

	static void fixZero(BigInt& A); // Usuwanie 0 z vectora.
	
};

