// Kevin De La Torre and Luke Walsh
// Exercise 7 - Conway's Game of Life
// Completed on: 2-24-16

#include "Conway.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib> // for atoi()

const char ALIVE = 'X';
const char DEAD = '.';
const char SPACE = ' ';

// Constructors
void Conway::allocate() 
{
    board = new bool*[ rows ];
    for ( int i = 0; i < rows; i++ )
    {
	board[ i ] = new bool[ columns ];
    }

    for ( int i = 0; i < rows; i++ )
    {
	for ( int j = 0; j < columns; j++ )
	{
	    board[ i ][ j ] = 0;
	}
    }
}

Conway::Conway() // Setting default board to be size 5x5
    : rows( 5 ), columns( 5 )
{
	allocate();
}

Conway::Conway( int row, int column )
    : rows( row ), columns( column )
{
	allocate();
}

Conway::Conway( std::string filename )
{
    std::ifstream fin( filename.c_str() );
    fin >> rows;
    fin >> columns;

    board = new bool*[ rows ];
    for ( int i = 0; i < rows; i++ )
    {
	board[ i ] = new bool[ columns ];
    }

    for ( int i = 0; i < rows; i++ )
    {
	for ( int j = 0; j < columns; j++)
	{ 
		fin >> board[ i ][ j ]; 
	} 
    }
}


Conway::Conway( const Conway& other ) // Copy constructor
	: rows( other.rows ), columns( other.columns )
{
	allocate();
	for ( int i = 0; i < rows; i++ )
	{
		for ( int j = 0; j < columns; j++ )
		{
			board[ i ][ j ] = other.board[ i ][ j ];
		}
	}
}

Conway::~Conway()
{
	for ( int i = 0; i < rows; i++ )
	{
		delete [] board[ i ];
		board[ i ] = nullptr;
	}
	delete [] board;
	board = nullptr;
}

// Assignment Function
Conway& Conway::operator=( const Conway& right )
{
	rows = right.rows;
	columns = right.columns;
	this->~Conway(); // Call destructor to get rid of *this->board so we can reallocate.
	allocate();
	for ( int i = 0; i < rows; i++ )
	{
		for ( int j = 0; j < columns; j++ )
		{
			board[ i ][ j ] = right.board[ i ][ j ];
		}
	}

	return *this;

}

// String function
std::string Conway::str() const
{
	// Print out the current board.
	std::ostringstream s;

	for ( int i = 0; i < rows; i++ )
	{
		for ( int j = 0; j < columns; j++ )
		{
			s << ( board[ i ][ j ] ? ALIVE : DEAD ) << SPACE;
		}
		s << std::endl;
	}

	return s.str();
} 
// Getter/Setter functions
bool Conway::alive(int row, int col)
{
	return board[row][col];
}

void Conway::flip(int row, int col)
{
	board[row][col] = !board[row][col];
}

// Engine
int liveNeighbors( Conway& board, int row, int col, int rows, int columns )
{
	int live = 0;
	for ( int i = ( row - 1 ); i <= ( row + 1 ); i++ )
	{
		for ( int j = ( col - 1 ); j <= ( col + 1 ); j++ )
		{
			if ( j >= 0 && j < columns && i >= 0 && i < rows && !( i == row && j == col ) )
			{
				if ( board.alive( i, j ) ) 
				{ 
					live++;
				}
			}
		}
	}
	
	return live;
}

void Conway::step()
{
	Conway nextBoard( *this );

	int live = 0;
	for ( int i = 0; i < rows; i++ )
	{
		for ( int j = 0; j < columns; j++ )
		{
			live = liveNeighbors( *this, i, j, rows, columns );
			if ( live == 3 )
			{
				nextBoard.board[ i ][ j ] = 1;
			} else
			{
				if ( live < 2 || live > 3 && board[ i ][ j ] == 1 )
				{
					nextBoard.board[ i ][ j ] = 0;
				}
			}
		}
	}
	this->~Conway();
	allocate();
	for ( int i = 0; i < rows; i++ )
	{
		for ( int j = 0; j < columns; j++ )
		{
			board[ i ][ j ] = nextBoard.board[ i ][ j ];
		}
	}
	
}

void Conway::play( int n )
{
	for ( int i = 0; i < n; i++ )
	{
		std::cout << this->str() << std::endl << std::endl;
		step();
	}
}

int main( int argc, char *argv[] )
{
	if ( argc != 3 )
	{
		std::cout << "Usage: " << argv[ 0 ] << " <file> <iterations>" << std::endl;
	} else
	{
		Conway game( argv[ 1 ] );
		game.play( std::atoi( argv[ 2 ] ) );
	}

	return 0;
}
