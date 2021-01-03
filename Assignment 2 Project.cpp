#include <iostream>

using namespace std;

void menu()
{
	cout << "=============================" << endl;
	cout << "Hotel Management System" << endl;
	cout << "=============================" << endl << endl;
	
	cout << "1. Check Available Room" << endl;
	cout << "2. Book Room" << endl;
	cout << "3. Exit" << endl << endl;
	
	cout << "Choose Option : ";
}

int main ()
{
	int choice = 0; // Variable for Choice
	
	while (choice != 3)
	{
		menu();
		cin >> choice;
	}
	
	return 0;
}
