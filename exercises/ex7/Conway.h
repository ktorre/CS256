// Kevin De La Torre and Luke Walsh
// Exercise 7 - Conway's Game of Life
// Completed on: 2-24-16

#ifndef CONWAY_H
#define CONWAY_H

#include <string>

class Conway
{
private:
    int rows;
    int columns;
    bool** board;
    void allocate();
public:
    // Constructors
    Conway();
    Conway( int row, int column );
    Conway( std::string filename );
    Conway( const Conway& other );
    ~Conway();

    // Assignment
    Conway& operator=( const Conway& right );

    // Str() function
    std::string str() const;

    // Getter/Setter
    bool alive( int row, int col );
    void flip( int row, int col );

    // Engine
    void play( int n );
    void step();

};

#endif
