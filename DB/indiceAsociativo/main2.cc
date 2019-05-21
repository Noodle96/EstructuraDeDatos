// objects in C++.
#include <iostream>
#include <fstream>
#include<array>
using namespace std;

// Class to define the properties
class Contestant {
public:
	// Instance variables
	string Name;
	int Age, Ratings;

	// Function declaration of input() to input info
	int input();

	// Function declaration of output_highest_rated() to
	// extract info from file Data Base
	int output_highest_rated();
};

// Function definition of input() to input info
int Contestant::input()
{
	// Object to write in file
	ofstream file_obj;

	// Opening file in append mode
	file_obj.open("Input.txt", ios::app);

	// Object of class contestant to input data in file
	Contestant obj;

	// Feeding appropriate data in variables
	string str = "Micheal";
	int age = 18, ratings = 2500;

	// Assigning data into object
	obj.Name = str;
	obj.Age = age;
	obj.Ratings = ratings;

	// Writing the object's data in file
	file_obj.write((char*)&obj, sizeof(obj));

	// Feeding appropriate data in variables
	str = "Terry";
	age = 21;
	ratings = 3200;

	// Assigning data into object
	obj.Name = str;
	obj.Age = age;
	obj.Ratings = ratings;

	// Writing the object's data in file
	file_obj.write((char*)&obj, sizeof(obj));

	return 0;
}

// Function definition of output_highest_rated() to
// extract info from file Data Base
int Contestant::output_highest_rated()
{
	// Object to read from file
	ifstream file_obj;

	// Opening file in input mode
	file_obj.open("Input.txt", ios::in);

	// Object of class contestant to input data in file
	Contestant obj;

	// Reading from file into object "obj"
	file_obj.read((char*)&obj, sizeof(obj));

	// max to store maximum ratings
	int max = 0;

	// Highest_rated stores the name of highest rated contestant
	string Highest_rated;

	// Checking till we have the feed
	while (!file_obj.eof()) {
		// Assigning max ratings
		if (obj.Ratings > max) {
			max = obj.Ratings;
			Highest_rated = obj.Name;
		}

		// Checking further
		file_obj.read((char*)&obj, sizeof(obj));
	}

	// Output is the highest rated contestant
	cout << Highest_rated;
	return 0;
}

// Driver code
int main()
{
	// Creating object of the class
	Contestant object;

	// Inputting the data
	//object.input();

	// Extracting the max rated contestant
	//object.output_highest_rated();

	std::array<std::pair<std::string,int>,10> int_ar;
	int_ar.fill(std::make_pair("monos",-1));
	for(auto it = int_ar.begin() ;  it != int_ar.end(); it++){
		std::cout << (*it).first << " " <<(*it).second <<std::endl;
	}




	return 0;
}
