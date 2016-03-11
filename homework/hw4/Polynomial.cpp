// Kevin De La Torre and Luke Walsh
// Homework 4 - Polynomial class
// Completed on: 2-20-16

#include <sstream>
#include <cmath>

#include "Polynomial.h"

// Constructors
Polynomial::Polynomial()
	: size( 1 ), coeff( new double[ 1 ] )
{
	*coeff = 0;
}

Polynomial::Polynomial( double coeffs[], int s )
	: size( s ), coeff( new double[ size ] )
{ 
	for ( int i = 0; i < size; i++ )
	{
		*( coeff + i ) = coeffs[ i ];
	}
}

Polynomial::Polynomial( int n )
	: size( 1 ), coeff( new double[ 1 ] )
{
	*coeff = ( double ) n;
}

Polynomial::Polynomial( double d )
	: size( 1 ), coeff( new double[ 1 ] )
{
	*coeff = d;
}

Polynomial::Polynomial( const Polynomial& p )
{
	size = p.size;
	coeff = new double[ size ];

	for ( int i = 0; i < size; i++ )
	{
		*( coeff + i ) = *( p.coeff + i );
	}
}

// Assignment
Polynomial& Polynomial::operator=( const Polynomial& right )
{
	if ( size < right.size )
	{
		delete [] coeff;
		coeff = new double[ right.size ];
	}
	size = right.size;

	for ( int i = 0; i < size; i++ )
	{
		*( coeff + i ) = *( right.coeff + i );
	}

	return *this;
}

// Getters
int Polynomial::getSize() const
{
	return size;
}

int Polynomial::degree() const
{
	int degree = 0;
	for ( int i = 0; i < size; i++ )
	{
		if ( *( coeff + i ) != 0 )
		{
			degree = i;
		}
	}

	return degree;
}

// toString
std::string Polynomial::str() const
{
	std::ostringstream s;
	for ( int i = size-1; i >=0; i-- )
	{
		if ( *( coeff + i ) != 0 ) // Don't print coefficients with 0.
		{
			if ( i != this->degree() ) // Print +/- if not first term.
			{
				if ( *( coeff + i ) < 0 )
				{
					s << " - ";
				} else
				{
					s << " + ";
				}
			}

			if ( *( coeff + i ) != 1 && *( coeff + i ) != -1 )
			{
				if ( *( coeff + i ) < 0 )
				{
					if ( i == this->degree() )
					{
						s << *( coeff + i );
					} else
					{
						s << *( coeff + i ) * -1;
					}
				} else
				{
					s << *( coeff + i );
				}
			} else
			{
				if ( i == this->degree() && *( coeff + i ) == -1 ) // Needed to print first term correct
				{
					s << "-";
				}
			}

			if ( i != 0 )
			{
				if ( i == 1 )
				{
					s << "x";
				} else 
				{
					s << "x^" << i;
				}
			}

		}
	}

	return s.str();
}

// Solver
double Polynomial::solve( double x ) const
{
	double total = 0;

	for ( int i = 0; i < size; i++ )
	{
		total += ( pow( x, i ) * *( coeff + i ) );
	}
	
	return total;
}

// [] Operator
double& Polynomial::operator[]( int n )
{
	if ( n >= size )
	{
		double* temp = new double[ n + 1 ];

		for ( int i = 0; i < size; i++ )
		{
			*( temp + i ) = *( coeff + i );
		}
		for ( int i = size; i < n; i++ )
		{
			*( temp + i ) = 0;
		}
		delete [] coeff;
		coeff = temp;
		size = n + 1;
	}

	return coeff[ n ];

}

// Arithmetic
Polynomial Polynomial::operator+( const Polynomial& right )
{
	Polynomial temp( *this );
	int smallSize = right.size;
	if ( size < right.size )
	{
		delete [] temp.coeff;
		temp.size = right.size;
		temp.coeff = new double[ temp.size ];
		for ( int i = 0; i < temp.size; i++ )
		{
			*( temp.coeff + i ) = *( right.coeff + i );
		}
		smallSize = size;
       	}

	for ( int i = 0; i < smallSize; i++ )
	{
		*( temp.coeff + i ) = ( *( right.coeff + i ) + *( this->coeff + i ) );
	}

	return temp;
}

Polynomial Polynomial::operator-( const Polynomial& right )
{
	Polynomial leftTemp;
	Polynomial rightTemp;

	int biggerSize = size;
	if ( size < right.size )
	{
		biggerSize = right.size;
	}

	leftTemp.size = rightTemp.size = biggerSize;
	leftTemp.coeff = new double[ biggerSize ];
	rightTemp.coeff = new double[ biggerSize ];

	for ( int i = 0; i < size; i++ )
	{
		leftTemp.coeff[ i ] = this->coeff[ i ];
	}

	for ( int i = size; i < biggerSize; i++ )
	{
		leftTemp.coeff[ i ] = 0;
	}

	for ( int i = 0; i < right.size; i++ )
	{
		rightTemp.coeff[ i ] = right.coeff[ i ];
	}

	for ( int i = right.size; i < biggerSize; i++ )
	{
		rightTemp.coeff[ i ] = 0;
	}

	for ( int i = 0; i < biggerSize; i++ )
	{
		leftTemp.coeff[ i ] = leftTemp.coeff[ i ] - rightTemp.coeff[ i ];
	}

	return leftTemp;
}

Polynomial Polynomial::operator*( const Polynomial& right )
{
	Polynomial prod;
	delete [] prod.coeff;
	prod.size = size + right.size - 1;
	prod.coeff = new double[ prod.size ];

	for ( int i = 0; i < prod.size; i++ )
	{
		prod[ i ] = 0;
	}

	for ( int i = 0; i < size; i++ )
	{
		for ( int j = 0; j < right.size; j++ )
		{
			prod[ i + j ] += ( this->coeff[ i ] * right.coeff[ j ] );
		}
	}
	return prod;
}

Polynomial Polynomial::operator*( double x ) 
{
	Polynomial temp( *this );
	for ( int i = 0; i < size; i++ )
	{
		*( temp.coeff + i ) = *( coeff + i ) * x;
	}

	return temp;
}

// Arithmetic Combined Operators
Polynomial& Polynomial::operator+=( const Polynomial& right )
{
	*this = *this + right;
	return *this;
}

Polynomial& Polynomial::operator-=( const Polynomial& right )
{
	*this = *this - right;
	return *this;
}

Polynomial& Polynomial::operator*=( const Polynomial& right )
{
	*this = ( *this * right );
}

Polynomial& Polynomial::operator*=( double x )
{
	*this = *this * x;
	return *this;

}

// Relational Operators
bool Polynomial::operator==( const Polynomial& right ) const
{
	if ( size != right.size )
	{
		return false;
	}

	for ( int i = 0; i < size; i++ ) 
	{
		if ( *( this->coeff + i ) != *( right.coeff + i ) )
		{
			return false;
		}
	}

	return true;
}

bool Polynomial::operator!=( const Polynomial& right ) const
{
	return !( *this == right );
}

// Output
std::ostream& operator<<( std::ostream&os, const Polynomial& p )
{
	os << p.str();
	return os;
}
