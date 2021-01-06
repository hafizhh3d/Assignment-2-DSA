#include <iostream>
#include<fstream>
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
			statusEmpty = true;
		}
};

void InsertFile(const char* filename, int x, int a[])
{
	ifstream in(filename);
	if(in.is_open())
    {
		bool swapped = true;
		
	    int y = 0;
	    int tmp;
	    while (swapped) {
	        swapped = false;
			y++;
	        for (int i = 0; i < x - y; i++) {
	      			if (a[i] > a[i + 1]) {
	                    tmp = a[i];
	                    a[i] = a[i + 1];
	                    a[i + 1] = tmp;
	                    swapped = true;
						}
	                  }
	
	            }
	}else cout<<"Error: File Cannot be Found"<<endl;
}

int main ()
{
	cout << "Hotel Mangement System" << endl;
	
	return 0;
}
