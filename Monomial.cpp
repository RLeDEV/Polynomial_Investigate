/*
* Author : Raz Levy
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <string>
#include <math.h>
#include "Monomial.h"

using namespace std;


int Monomial::numberOfMonomials = 0;
Monomial::Monomial(double coe, int deg) {
	c = coe;
	d = deg;
	next = NULL;
	numberOfMonomials++;
}

// C'tor with string
Monomial::Monomial(string s) {
	bool xExist = false;
	double finalC;
	string num;
	int i;
	if (s[0] != '-') { // this is a positive number
		for (i = 0; i < (int)(s.length()); i++) {
			if (s[i] == 'x')
				break;
			num += s[i];
		}
		if (s[0] == 'x' || (s[0] == '1' && s[1] == 'x')) {
			this->c = 1;
		}
		else {
			finalC= stod(num);
			this->c = finalC;
		}
		num = "";
		for (int j = 0; j < (int)(s.length()); j++) {
			if (s[j] == 'x')
				xExist = true;
		}
		if (xExist == false)
		{
			this->d = 0;
		}
		else if (i == (int)(s.length()) - 1) {
			this->d = 1;
		}
		else {
			for (i = i+2; i < (int)(s.length()); i++) {
				num += s[i];
			}
			this->d = stoi(num);
		}
	}
	else { // this is a negative number
		int i;
		for (i = 1; i < (int)(s.length()); i++) {
			if (s[i] == 'x')
				break;
			num += s[i];
		}
		if (s[1] == 'x' || (s[1] == '1' && s[2] == 'x')) {
			this->c = -1;
		}
		else {
			finalC = stod(num) * (-1);
			this->c = finalC;
		}
		num = "";
		for (int j = 0; j < (int)(s.length()); j++) {
			if (s[j] == 'x')
				xExist = true;
		}
		if (xExist == false)
		{
			this->d = 0;
		}
		else if (i == (int)(s.length()) - 1) {
			this->d = 1;
		}
		else {
			for (i = i + 2; i < (int)(s.length()); i++) {
				num += s[i];
			}
			this->d = stoi(num);
		}
	}
	this->next = NULL;
	numberOfMonomials++;
}

Monomial::Monomial(const Monomial& other)
	: d(other.d) {
	c = other.c;
	this->next = NULL;
	numberOfMonomials++;
}

Monomial::~Monomial() {
	numberOfMonomials--;
}

istream& operator>>(istream& in, Monomial& m) {
	string s;
	getline(in, s); // getting the input string
	// Setting c & d
	m = s;
	return in;
}

ostream& operator<<(ostream& out, const Monomial& m) {
	m.print();
	return out;
}

const Monomial& Monomial::operator=(const Monomial& other) {
	c = other.c;
	d = other.d;
	return *this;
};

const bool Monomial::operator==(const Monomial& other) const {
	if (c == other.c && d == other.d) return true;
	else return false;
}

const bool Monomial::operator!=(const Monomial& other) const {
	if (c == other.c && d == other.d) return false;
	else return true;
}

Monomial Monomial::operator+(const Monomial& other) const {
	if (d == other.d) return Monomial(c + other.c, d);
	else return Monomial(c, d);
}

Monomial Monomial::operator-(const Monomial& other) const {
	if (d == other.d) return Monomial(c - other.c, d);
	else return Monomial(c, d);
}

Monomial Monomial::operator-() const {
	return Monomial(-c, d);
}


Monomial Monomial::operator*(const Monomial& other) const {
	return Monomial(c * other.c, d + other.d);
}

void Monomial::operator*=(int num) {
	c *= num;
}

const Monomial& Monomial::operator+=(const Monomial& other) {
	if (d == other.d) {
		c += other.c;
	}
	return *this;
}

const Monomial& Monomial::operator-=(const Monomial& other) {
	if (d == other.d) {
		c -= other.c;
	}
	return *this;
}


const double Monomial::operator()(const int num) const {
	return c * pow(num, d);
}

void Monomial::print() const {
	if (c == 0)
		cout << 0;
	else if (d == 0) {
		cout << c;
	}
	else if (c == 1 && d == 1) {
		cout << "x";
	}
	else if (c == -1 && d == 1) {
		cout << "-x";
	}
	else if (c == 1 && d > 1) {
		cout << "x^" << d;
	}
	else if (d == 1) { // coefficient != 1
		cout << c << "*x";
	}
	else { // coefficient !=1 AND degree != 1
		cout << c << "*x^" << d;
	}
}

const bool Monomial::add(const Monomial& other) {
	if (d != other.d)
		return false;
	else {
		c += other.c;
		return true;
	}
};