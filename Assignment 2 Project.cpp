#include <iostream>
#include <string>

using namespace std;

<<<<<<< HEAD
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
=======
class Room
{
	// Private data attribute for Class Room
	private :
		int room;				// Variable for Room Number
		string nameCustomer;	// Variable for Customer Name
		bool statusEmpty;		// Variable for Room Status
	
	public :
		// Default Constructor
		Room(int r = 0, string nc = "", bool s = true)
		{
			room = r;
			nameCustomer = nc;
			s = statusEmpty;
		}
		
		// Mutator for Variable room
		void setRoom(int r)
		{
			room = r;
		}
		
		// Mutator for Variable nameCustomer
		void setNameCustomer(string nc)
		{
			nameCustomer = nc;
		}
		
		// Mutator for Variable statusEmpty
		void setStatusEmpty(bool s)
		{
			statusEmpty = s;
		}
		
		// Accessor for Variable room
		int getRoom() const
		{
			return room;
		}
		
		// Accessor for Variable nameCustomer
		string getNameCustomer() const
		{
			return nameCustomer;
		}
		
		// Accessor for Variable statusEmpty
		bool getStatusEmpty() const
		{
			return statusEmpty;
		}
		
		// Function for Room Check In
		void checkIn(string nc)
		{
			nameCustomer = nc;
			statusEmpty = false;
		}
		
		// Function for Room Check Out
		void checkOut()
		{
			nameCustomer = "";
			statusEmpty = true;
		}
};
>>>>>>> origin/master

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
