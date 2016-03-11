// Kevin De La Torre and Luke Walsh
// Exercise 5: Rational Number Class
// Completed on: 2-12-2016

#include "rat.h"

// These functions can be useful for calculations with fractions
int gcd(int x, int y)
{
    if (y == 0) 
        return x;
    return gcd(y, x % y);
}

int lcm(int x, int y)
{
    return (x * y) / gcd(x, y);
}

// Put your function implementations here

rat::rat()
	: num( 0 ), den( 1 )
{
}

rat::rat( int n )
	: num( n ), den( 1 )
{
}

rat::rat( int n, int d )
	: num( n ), den( d )
{
	if ( d == 0 )
	{
		num = 0;
		den = 1;
	}
	reduce();
}

int rat::getNum() const
{
	return num;
}

int rat::getDen() const
{
	return den;
}

void rat::reduce()
{
	int g = gcd( num, den );
	num /= g;
	den /= g;
	if ( den < 0 )
	{
		num = -num;
		den = -den;
	}
}

rat rat::reciprocal() const
{
	return rat( den, num );
}

rat rat::operator+( const rat& right ) const
{
	int multiple = lcm( this->den, right.den );
	int newNum = ( this->num * ( multiple / this->den ) ) + ( right.num * ( multiple / right.den ) );
	return rat( newNum, multiple );
}

rat rat::operator-( const rat& right ) const
{
	int multiple = lcm( this->den, right.den );
	int newNum = ( this->num * ( multiple / this->den ) ) - ( right.num * ( multiple / right.den ) );
	return rat( newNum, multiple );
}

rat rat::operator*( const rat& right ) const
{
	return rat( ( this->num * right.num ), ( this->den * right.den ) );
}

rat rat::operator/( const rat& right ) const
{
	rat rec = right.reciprocal();
	return rat( ( this->num * rec.num ), ( this->den * rec.den ) );
}

bool rat::operator==( const rat& right ) const
{
	return ( this->num == right.num && this->den == right.den );
}

bool rat::operator!=( const rat& right ) const
{
	return !( *this==right );
}

bool rat::operator<( const rat& right ) const
{
	return ( ( this->num * right.den ) < ( right.num * this->den ) );
}

bool rat::operator>( const rat& right ) const
{
	return ( !( *this < right) && !( *this == right ) );
}

bool rat::operator<=( const rat& right ) const
{
	return !( *this > right );
}

bool rat::operator>=( const rat& right ) const
{
	return !( *this < right );
}

std::string rat::str() const
{
	std::ostringstream strRat;
	strRat << num << '/' << den;
	return strRat.str();
}
