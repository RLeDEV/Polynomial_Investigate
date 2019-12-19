/*
* Author : Raz Levy
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include "Monomial.h"

using namespace std;

class Polynomial {
private:
	Monomial* head;

public:
	// C'tor
	Polynomial();
	Polynomial(const Polynomial& other);
	// D'tor
	~Polynomial();

	// Operators
	friend ostream& operator<<(ostream&, const Polynomial&);
	friend istream& operator>>(istream&, Polynomial&);
	const Polynomial& operator=(const Polynomial& other);
	Polynomial operator+(const Polynomial& other) const;
	Polynomial operator+(const Monomial& mon) const;
	Polynomial operator-(const Polynomial& other) const;
	Polynomial operator-(const Monomial& mon) const;
	Polynomial operator-() const;
	const Polynomial& operator+=(const Monomial& mon);
	const Polynomial& operator+=(const Polynomial& other);
	const Polynomial& operator-=(const Monomial& mon);
	const Polynomial& operator-=(const Polynomial& other);
	double& operator[](int num);
	const double operator()(int num) const;
	const bool operator==(const Polynomial& other) const;
	const bool operator==(const Monomial& mon) const;
	const bool operator!=(const Polynomial& other) const;
	const bool operator!=(const Monomial& mon) const;


	void print() const;
	void add(const Monomial& monToAdd);
	void removeNodes();
};