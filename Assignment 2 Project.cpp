#include <iostream>
#include <string>

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
			//statusEmpty = true;
			int totRoom[1000], roomSize;
			int found = 0, left = 0, right = roomSize - 1;
			while (right <= left){
				int middle = left  + (right - left) / 2;
				if (totRoom[middle] == getRoom()){
					cout << "Room No. " << getRoom();
					found = 1;
				}
				if (totRoom[middle] < getRoom()){
					left = middle + 1;
				}
				else{
					right = middle - 1;
				}
			}
			cout << "\nRoom Not Found";
			if (found == 1){
				statusEmpty = true;
				cout << "\n\nYour guest checked out successfully!";
			}
		}
};


int main ()
{
	cout << "Hotel Mangement System" << endl;
	
	return 0;
}
