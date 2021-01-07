#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

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

void printFile(const char* filename, int totRoom, int arr[], string name){
	Room r;
	ofstream out(filename);
	if (out.is_open())
	{
		if (r.getStatusEmpty() == false){
			for (int i = 0; i < totRoom; i++)
			{
				out << "GUEST ROOM LIST";
				out << "No. " << setw(5) << "Room No. " << setw (10) << "Guest Name";
				out << i+1 << setw(5) << r.getRoom() << setw(10) << r.getNameCustomer() << endl;
			}
		}
		if (r.getStatusEmpty() == true){
			for (int j = 0; j < totRoom; j++){
				out << "VACANT ROOM LIST";
				out << "No. " << setw(5) << "Room No.";
				out << j+1 << setw(5) << r.getRoom() << endl;
			}
		}
	}
}

int main ()
{
	cout << "Hotel Mangement System" << endl;
	
	return 0;
}
