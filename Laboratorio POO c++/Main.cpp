#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	string name;
	int    age;
	// Your code here
	double height;
	double weight;
};

void print(Person* person)
{
	cout << person->name << " is " << person->age 
		<< " years old, they're " << person->height 
		<< " meters tall and weigh " << person->weight << " Kilograms" << endl;
}


int main()
{
	Person person;
	person.name = "Harry";
	person.age = 23;
	person.height = 1.76;
	person.weight = 78.6;

	cout << "Meet " << person.name << endl;
	print(&person);

	// Your code here

	return 0;
}