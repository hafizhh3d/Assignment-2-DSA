#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int size= 15; 
int A[size]; 

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

		// Function for Input File and Sort
		void InsertFile(const char* filename, int x, int a[])
		{
			//Input Data file
			int sum = 0;
			ifstream in(filename);
			if(in.is_open())
			{
			while ( in >> x ) 	
			{ 		
					A[sum++] = x;
					cout << setw(size) << x ; 	
			}
			//Bubble sort Operation	
			int temp;	  
		
			for (int i = 0; i < size - 1; i++) 		
				for (int j = 0; j < size - 1; j++) 		
				{ 			
					if (A[j] > A[j+1]) 			
					{ 				
						temp = A[j]; 
						A[j] = A[j+1];
						A[j+1] = temp;
					} 		
				}in.close();
			}else cout<<"Error: File Cannot be Found"<<endl;
		}
};



int main ()
{
	cout << "Hotel Mangement System" << endl;
	
	return 0;
}
