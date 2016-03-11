// Kevin De La Torre <ktorre>
// Exercise 6 - String class
// Completed on: 2-15-16

#include "String.h"
#include <cstring>


// Constructors
String::String()
    : size( 0 ), data( new char[ 10 ] )
{
}

String::String( char a )
    : size( 1 ), data( new char[ 10 ] )
{
    *data = a; // Set the first char in the array to a.
}

String::String( const char* cStr )
{
    int strSize = strlen( cStr );
    size = strSize;
    data = new char[ strSize ];
    for ( int i = 0; i < strSize; i++ )
    {
	*( data + i ) = *( cStr + i );
    }
}

String::String( const String& other ) // Copy Constructor
{
    size = other.size;
    data = new char[ other.size ];
    for ( int i = 0; i < other.size; i++ )
    {
	*( this->data + i ) = *( other.data + i );
    }
}


// Assignment
String& String::operator=( const String& right )
{
    // If the size of our current array is smaller, allocate more space
    if ( this->size < right.size )
    {
	delete [] this->data;
	this->data = new char[ size ];
    }
    this->size = right.size;

    for ( int i = 0; i < this->size; i++ )
    {
	*( this->data + i ) = *( right.data + i );
    }

    return *this;
}


// Utility
char String::charAt( int n ) const
{
	if ( n < size )
	{
		return *( data + n );
	}
}

int String::indexOf( char a ) const
{
	for ( int i = 0; i < size; i++ )
	{
		if ( *( data + i ) == a )
		{
			return i;
		}
	}
	return -1;
}

char& String::operator[]( int i )
{
	return data[ i ];
}


// Concatenation
String String::operator+( const String& right ) const
{
	String temp;
	delete [] temp.data;
	temp.size = ( this->size + right.size );
	temp.data = new char[ temp.size ];
	for ( int i = 0; i < this->size; i++ )
	{
		*( temp.data + i ) = *( this->data + i );
	}
	for ( int i = 0; i < right.size; i++ )
	{
		*( temp.data + i + this->size ) = *( right.data + i );
	}

	return temp;
}

String String::operator+( char c ) const
{
	String temp;
	delete [] temp.data;
	temp.size = ( this->size + 1 );
	temp.data = new char[ temp.size ];
	for ( int i = 0; i < temp.size; i++ )
	{
		*( temp.data + i ) = *( this->data + i );
	}
	*( temp.data + this->size ) = c;
	return temp;
}


// Relational
bool String::operator==( const String& right ) const
{
	if ( this->size != right.size )
	{
		return false;
	}

	for ( int i = 0; i < this->size; i++ )
	{
		if ( *( this->data + i ) != *( right.data + i ) )
		{
			return false;
		}
	}
	return true;
}

bool String::operator!=( const String& right ) const
{
	return !( *this == right );
}

bool String::operator<( const String& right ) const
{
	int tempSize = this->size; // I want to only loop through the smaller size.
	if ( this->size > right.size )
	{
		tempSize = right.size;
	}

	for ( int i = 0; i < tempSize; i++ )
	{
		if ( int( *( this->data + i ) ) < int( *( right.data + i ) ) )
		{
			return true;
		}
	}
	return false;
}

bool String::operator<=( const String& right ) const
{
	return ( ( *this < right ) || ( *this == right ) );
}

bool String::operator>( const String& right ) const
{
	return !( *this <= right );
}

bool String::operator>=( const String& right ) const
{
	return !( *this < right );
}


// Substring
String String::substring( int start, int end ) const
{
	String sub;
	if ( start < 0 || start >= this->size || end <= start )
	{
		return sub; // If error return empty string
	}

	if ( end > this->size )
	{
		end = this->size;
	}

	delete [] sub.data;
	sub.size = ( end - start );
	sub.data = new char[ sub.size ];

	for ( int i = start, j = 0; i < end; i++, j++ )
	{
		*( sub.data + j ) = *( this->data + i );
	}

	return sub;
}


// Stream overloading
std::ostream& operator<<( std::ostream& os, const String& s )
{
	for ( int i = 0; i < s.size; i++ )
	{
		os << *( s.data + i );
	}

	return os;
}

std::istream& operator>>( std::istream& is, String& s )
{
	std::string temp = "";
	is >> temp;
	s.size = temp.length();
	delete [] s.data;
	s.data = new char[ s.size ];
	for ( int i = 0; i < s.size; i++ )
	{
		*( s.data + i ) = temp[ i ];
	}

	return is;
}
