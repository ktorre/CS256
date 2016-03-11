// Kevin De La Torre
// Homework 1 - AgeArithmetic
// Completed 1-12-2016

#include <iostream>

int main()
{
	// So I don't have to keep typing std::
	using namespace std;
	
	// Initiate variables
	int age;
	int ageSquared;
	int ageHalved;

	// Get age
	do 
	{
		cout << "Enter your age: ";
		cin >> age;
	} while ( age < 0 );

	ageSquared = ( age * age );
	ageHalved = ( age / 2 );

	// Print out variables
	// Used endl instead of making it one line with newline characters
	// because I didn't want to have one long line with multiple newlines
	// when I could just use the endl statement.
	
	cout << "\nAge: " << age << endl;
	cout << "Age Squared: " << ageSquared << endl;
	cout << "Age Halved: " << ageHalved << endl;

	// Perform calculations and output result
	cout << "\nAge * AgeHalved: " << ( age * ageHalved ) << endl;
	cout << "AgeSquared / AgeHalved: " << ( ageSquared / ageHalved ) << endl;
	cout << "AgeSquared % AgeHalved: " << ( ageSquared % ageHalved ) << endl;
	cout << "AgeHalved - Age: " << ( ageHalved - age ) << endl;
	cout << "Age / AgeSquared: " << ( age / ageSquared ) << endl;
	cout << "AgeSquared + Age: " << ( ageSquared + age ) << endl;
	cout << "Mean of ( Age + AgeSquared + AgeHalved ): " << ( float )( age + ageSquared + ageHalved ) / 3 << endl;

	return 0;
}
