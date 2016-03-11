// Kevin De La Torre and Luke Walsh
// Homework 4 - Polynomial class
// Completed on: 2-20-16

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <string>

class PolyTester;

class Polynomial
{
    friend class PolyTester;

private:
    int size;
    double* coeff;
public:
    // Constructors/Destructor
    Polynomial();
    Polynomial( double coeffs[], int size );
    Polynomial( int n );
    Polynomial( double d );
    Polynomial( const Polynomial& p );
    ~Polynomial() { delete [] coeff; };

    // Assignment
    Polynomial& operator=( const Polynomial& right );

    // Getters
    int getSize() const;
    int degree() const;

    // toString
    std::string str() const;

    // Solver
    double solve( double x ) const;

    // [] Operator
    double& operator[]( int n );

    // Arithmetic
    Polynomial operator+( const Polynomial& right );
    Polynomial operator-( const Polynomial& right );
    Polynomial operator*( const Polynomial& right );
    Polynomial operator*( double x );

    // Arithmetic Combined Operators
    Polynomial& operator+=( const Polynomial& right );
    Polynomial& operator-=( const Polynomial& right );
    Polynomial& operator*=( const Polynomial& right );
    Polynomial& operator*=( double x );

    // Relational Operators
    bool operator==( const Polynomial& right ) const;
    bool operator!=( const Polynomial& right ) const;

    // Output
    friend std::ostream& operator<<( std::ostream& os, const Polynomial& p );

};

#endif
