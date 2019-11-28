#pragma once
#include <iostream>
#include <vector>

using namespace std;

const int base = 1000000000;

typedef vector<int> BigInt;

class BigInteger{

public:

	// Inicjalizacje
	
	static BigInt Init(string str);

	static BigInt Init(long long integer);

	static BigInt Init(unsigned int integer);

	// Wypisywanie

	static string toString(BigInt A);

	// Operatory
	
};

