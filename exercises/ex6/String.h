// Kevin De La Torre <ktorre>
// Exercise 6 - String class
// Completed on: 2-15-16

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
#include <sstream>

class StringTester;



class String
{
    friend class StringTester;

private:
    // declare private members here
    int size;
    char* data;
public:
    // Constructors/Destructor
    String();
    String( char a );
    String( const char* cStr );
    String( const String& other );
    ~String() { delete [] data; };

    // Assignment
    String& operator=( const String& right );

    // Utility
    int length() const { return size; };
    char charAt( int n ) const;
    int indexOf( char a ) const;
    char& operator[]( int i );

    // Concatenation
    String operator+( const String& right ) const;
    String operator+( char c ) const;

    // Relational
    bool operator==( const String& right ) const;
    bool operator!=( const String& right ) const;
    bool operator<( const String& right ) const;
    bool operator<=( const String& right ) const;
    bool operator>( const String& right ) const;
    bool operator>=( const String& right ) const;

    // Substring
    String substring( int start, int end ) const;

    // Streams
    friend std::ostream& operator<<( std::ostream& os, const String& s );
    friend std::istream& operator>>( std::istream& is, String& s );
};

#endif
