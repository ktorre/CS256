// Kevin De La Torre and Luke Walsh
// Exercise 5: Rational Number Class
// Completed on: 2-12-2016


#ifndef RAT_H
#define RAT_H

#include <iostream>
#include <string>
#include <sstream>

class RatTester;

class rat
{
    friend class RatTester;

private:
    int num;
    int den;
    void reduce();

public:
    rat();
    rat( int n );
    rat( int n, int d );

    int getNum() const;
    int getDen() const;

    rat reciprocal() const;

    rat operator+( const rat& right ) const;
    rat operator-( const rat& right ) const;
    rat operator*( const rat& right ) const;
    rat operator/( const rat& right ) const;

    bool operator==( const rat& right ) const;
    bool operator<( const rat& right ) const;
    bool operator!=( const rat& right ) const;
    bool operator>( const rat& right ) const;
    bool operator<=( const rat& right ) const;
    bool operator>=( const rat& right ) const;

    std::string str() const;

};

#endif
