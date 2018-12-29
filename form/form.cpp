#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Info {
	char first_name[15];
	char last_name[15];
	char street[30];
	char city[20];
	char state[5];
	long zip;
};

int main() {
	Info person;
	fstream indata;
	ofstream outdata;
	char input;

	indata.open("person.dat", ios::out | ios::binary);

	do {
		cout << "Enter the following information" << endl;
		cout << "Person's First Name: ";
		cin.getline(person.first_name, sizeof(person.first_name));

		cout << "Person's Last Name: ";
		cin.getline(person.last_name, sizeof(person.last_name));

		cout << "Street: ";
		cin.getline(person.street, sizeof(person.street));

		cout << "City: ";
		cin.getline(person.city, sizeof(person.city));

		cout << "State: ";
		cin.getline(person.state, sizeof(person.state));

		cout << "Zip: ";
		cin >> person.zip;

		cout << endl;

		indata.write((char*)&person, sizeof(person));

		cout << "Enter a Y if you would like to input more data" << endl;
		cin >> input;
		cin.ignore();
	} while (toupper(input) == 'Y');
	cout << "That's all the information" << endl;

	indata.close();

	indata.open("person.dat", ios::in | ios::binary);
	outdata.open("person.txt");
	indata.read((char *)&person, sizeof(person));

	outdata << left;
	outdata << setw(15) << "First Name" << setw(15) << "Last Name" << setw(30) << "Street"
		<< setw(20) << "City" << setw(7) << "State" << setw(10) << "Zip Code" << endl;

	while (!indata.eof()) {
		outdata << setw(15) << person.first_name << setw(15) << person.last_name << setw(30) <<
			person.street << setw(20) << person.city << setw(7) <<
			person.state << setw(10) << person.zip << endl;
		indata.read((char *)&person, sizeof(person));
	}

	indata.close();
	outdata.close();
	return 0;
}