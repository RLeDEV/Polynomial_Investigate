/*
* Author : Raz Levy
*/

#ifndef Monomial_h
#define Monomial_h

#include <iomanip>
#include <iostream>
using namespace std;

class Monomial {
private:
	double c;
	int d;
	static int numberOfMonomials;
	Monomial* next;

public:
	Monomial(double coe = 1, const int deg = 0);
	Monomial(const Monomial& other);
	Monomial(string);
	~Monomial();
	friend ostream& operator <<(ostream&, const Monomial&);
	friend istream& operator >>(istream&, Monomial&);
	const Monomial& operator=(const Monomial& other);
	const bool operator==(const Monomial& other) const;
	const bool operator!=(const Monomial& other) const;
	Monomial operator+(const Monomial& other) const;
	Monomial operator-(const Monomial& other) const;
	Monomial operator-() const;
	Monomial operator*(const Monomial& other) const;
	void operator*=(int num);
	const Monomial& operator+=(const Monomial& other);
	const Monomial& operator-=(const Monomial& other);
	const double operator()(const int num) const;
	const bool add(const Monomial& other);
	static int getNumberOfMonomials() { return numberOfMonomials; };
	void print() const;
	const int getDegree() const { return d; };
	double getCoefficient() const { return c; };
	double& getCoeByRef() { return c; };
	Monomial* getNext() const { return next; };
	void setCoefficient(const int coe) { c = coe; };
	void setDegree(const int deg) { d = deg; };
	void setNext(Monomial *newNext) { next = newNext; };
};

#endif /* Monomial_h */