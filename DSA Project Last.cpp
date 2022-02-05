#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX 50

	//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
	//                                                            //
	//               CLASS HEADER AND IMPLEMENTATION              //
	//                                                            //
	//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//

//============================================================//
//			      		Class nodeStack  			   		  //
//															  //
// This class store the the Stack Node Data Information		  //
//============================================================//

class nodeStack
{
	public :
		
		string nameCustomer; // Variable for Customer Name
		
		nodeStack *next; // Pointer to next node
}; nodeStack *top = NULL;

//============================================================//
//			      		Class Stack  				   		  //
//															  //
// This class store the Customer's room data using stack	  //
//============================================================//

class Stack
{
	public:
		// Function to initialize the Stack
		Stack() 
		{
			top = NULL;
		}
		
		// Function to check wheter the Stack is Empty or not
		bool isEmpty()
		{
			return (top == NULL);
		}
		
		// Function to add Data into stack
		void push (string nc)
		{
			struct nodeStack *newNode;
			newNode = new nodeStack;

			newNode->nameCustomer = nc;
			newNode->next = top;
			top = newNode;
			
			cout << endl;
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
			cout << "            STACK INFORMATION" << endl;
			cout << endl;
			
			cout << "Succesfully added(push) new information" << endl;
			cout << "Customer Name : " << top->nameCustomer << endl;
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
		}
		
		// Function to delete Data in the Stack
		void pop ()
		{
			if(isEmpty())
			{
				cout << endl;
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
				cout << "            STACK INFORMATION" << endl;
				cout << endl;
				
				cout << "The Stack is Empty!!!";
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
				cout << endl;				
			}
			else
			{
				nodeStack *deleteStack;
				
				cout << endl;
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
				cout << "            STACK INFORMATION" << endl;
				cout << endl;
				
				cout << "Succesfully deleted(pop) the information" << endl;
				cout << "Customer Name : " << top->nameCustomer << endl;
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
				cout << endl;
				
				deleteStack = top;
				top = deleteStack->next;
				delete(deleteStack);
			}
		}
		
		// Function to check the value of Top of Stack
		int stackTop()
		{
			if(isEmpty())
			{
				cout << endl;
				cout << "The Stack is Empty!!!";
				cout << endl;
			}
			else
			{
				cout << endl;
				cout << "Customer Name : " << top->nameCustomer << endl;
				cout << endl;
			}
		}
};

//============================================================//
//			      		Class Room  				   		  //
//															  //
// This class store the Room data.  	    				  //
// This class will be the base class						  //
//============================================================//

class Room
{
	// Private data attribute for Class Room
	private :
		int room; // Variable for Room Number
		string nameCustomer; // Variable for Customer Name
		bool statusEmpty; // Variable for Room Status
	
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
		
		void operator = (const Room &right)
		{
			room = right.getRoom();
			nameCustomer = right.getNameCustomer();
			checkIn(right.getNameCustomer());
		}
};

	//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
	//															  //
	//					FUNCTION FOR MAIN						  //
	//															  //
	//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//


//============================================================//
//						userMenu()							  //
//					Input  = None							  //
//					Output = Display User Role Menu			  //
//															  //
// This Function will display the menu for the user to choose //
// their role.												  //
//============================================================//

void userMenu()
{
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
	cout << "HOTEL DE CASA" << endl;
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-" << endl << endl;
	
	cout << "1. Hotel Manager" << endl;
	cout << "2. Customer" << endl;
	cout << "Please enter your role : ";
}

//============================================================//
//						managerMenu()						  //
//					Input  = None							  //
//					Output = Display Hotel Manager Menu		  //
//															  //
// This Function will display the menu for the user from	  //
// Hotel Manager role to choose the option.					  //
//============================================================//

void managerMenu()
{
	cout << "=============================" << endl;
	cout << "Hotel Management System" << endl;
	cout << "=============================" << endl << endl;
	
	cout << "1. Check Room Status" << endl;
	cout << "2. Room Check In" << endl;
	cout << "3. Room Check Out" << endl;
	cout << "4. Search Room Info" << endl;
	cout << "5. Input File" << endl;
	cout << "6. Print File" << endl;
	cout << "7. Check Stack Top" << endl;
	cout << "8. Display Stack" << endl;
	cout << "9. Exit" << endl << endl;
	
	cout << "Choose Option : ";
}

//============================================================//
//						customerMenu()						  //
//					Input  = None							  //
//					Output = Display Customer Menu			  //
//															  //
// This Function will display the menu for the user from	  //
// Customer role to choose the option.						  //
//============================================================//

void customerMenu()
{
	cout << "=============================" << endl;
	cout << "Customer Hotel System Menu" << endl;
	cout << "=============================" << endl << endl;
	
	cout << "1. Check Room Status" << endl;
	cout << "2. Room Check In" << endl;
	cout << "3. Room Check Out" << endl;
	cout << "4. Exit" << endl << endl;
	
	cout << "Choose Option : ";
}

//============================================================//
//					checkAvailableRoom()					  //
//					Input  = None							  //
//					Output = Display The Room Availablity	  //
//															  //
// This Function will display the available room for both	  //
// role.													  //
// It will tell user which room that they can book.			  //
//============================================================//

void checkAvailableRoom(Room rooms[])
{
	cout << "-=-=-=-=-=-=-==-=-=--=-=-=" << endl;
	cout << "Room Status" << endl;
	cout << "-=-=-=-=-=-=-==-=-=--=-=-=" << endl;
	
	// Loop for Printing List of Available Room
	for (int i = 0; i < MAX; i -= -1)
	{
		cout << i+1 << ". Room ";
		cout << rooms[i].getRoom() << " : ";
		
		if (rooms[i].getStatusEmpty())
		{
			cout << "AVAILABLE";
		}
		else
		{
			cout << "OCCUPIED";
		}
		cout << endl;
	}
}

//============================================================//
//						checkIn()							  //
//					Input  = rnum, name						  //
//					Output = Adding New Book Room			  //
//															  //
// This Function will take the room number input from user	  //
// and check the availablity of the room for user so they	  //
// can check in.											  //
// This function also set the room information with user name.//
//============================================================//

void checkIn(Room rooms[], Stack *info)
{
	int rnum; // Variable for Room Number
	int index; // Variable for Index
	string name; // Variable for Customer Name
	
	cout << "-=-=-=-=-=-=-==-=-=--=-=-=" << endl;
	cout << "Check In" << endl;
	cout << "-=-=-=-=-=-=-==-=-=--=-=-=" << endl;
	
	// User Input for Room Number and Check Availability
	do 
	{
		cout << endl << "Please enter your desired room : ";
		cin >> rnum;
		cout << endl;
	
		for (int i = 0; i < MAX; i -= -1)
		{
			if (rnum == rooms[i].getRoom())
			{
				if (rooms[i].getStatusEmpty())
				{
					cout <<"Room is available to book" << endl;
					index = i;
				}
				else if (!rooms[i].getStatusEmpty())
				{
					cout << "Room is booked!!!" << endl;
					cout << "Please choose another one" << endl;
				}
			}
		}
	} while (!rooms[index].getStatusEmpty());
	
	// Input Customer Name
	cout << endl;
	cout << "Please enter your name : ";
	cin.ignore();
	getline(cin, name);
	rooms[index].checkIn(name);
	
	// Adding information to Stack
	info->push(name);
	
	// Output for User
	cout << endl;
	cout << "Room " << rooms[index].getRoom() << endl;
	cout << "Customer Name : " << rooms[index].getNameCustomer() << endl;
	
	cout << endl;
	cout << "Successfully Booked!!" << endl;
}

//============================================================//
//						checkOut()							  //
//					Input  = rnum							  //
//					Output = Delete The Booked Room			  //
//															  //
// This Function will delete the booked room user so the room //
// can be booked again.										  //
//============================================================//

void checkOut(Room rooms[], Stack *info)
{
	int rnum; // Variable for Room Number
	int index; // Variable for Index
	
	cout << "-=-=-=-=-=-=-==-=-=--=-=-=" << endl;
	cout << "Check Out" << endl;
	cout << "-=-=-=-=-=-=-==-=-=--=-=-=" << endl;
	
	// User Input for Room Number and Check Availability
	do 
	{
		cout << endl << "Please enter your room number : ";
		cin >> rnum;
		cin.ignore();
		cout << endl;
	
		for (int i = 0; i < MAX; i -= -1)
		{
			if (rnum == rooms[i].getRoom())
			{
				if (rooms[i].getStatusEmpty())
				{
					cout <<"Room is Empty!!!" << endl;
				}
				else if (!rooms[i].getStatusEmpty())
				{
					index = i;
				}
			}
		}
	} while (rooms[index].getStatusEmpty());
	
	// Poping Information from Stack
	info->pop();
	
	// Output for Check Out
	cout << "Room " << rooms[index].getRoom() << endl;
	cout << "Customer Name : " << rooms[index].getNameCustomer() << endl;
	rooms[index].checkOut();
	
	cout << endl;
	cout << "Successfully Check Out!!" << endl;
	
}

//============================================================//
//						searchRoom()						  //
//					Input  = rnum							  //
//					Output = Room Information				  //
//															  //
// This Function will for the room and display all the		  //
// the room information.									  //
//============================================================//

void searchRoom(Room rooms[])
{
	int found = - 1; // Variable for Found; Used for Sequential Search
	int rnum; // Variable for Room Number
	
	cout << "-=-=-=-=-=-=-==-=-=--=-=-=" << endl;
	cout << "Search Room Info" << endl;
	cout << "-=-=-=-=-=-=-==-=-=--=-=-=" << endl;
	
	cout << "Please enter the Room Number : ";
	cin >> rnum;
	cout << endl;
	
	for (int i = 0; i < MAX; i -= -1)
	{
		if (rnum == rooms[i].getRoom())
		{
			found = i;
		}
	}
	
	if (found == -1)
	{
		cout << "Room not Found!!!";
	}
	else
	{
		cout << "Room " << rooms[found].getRoom() << endl;
		
		if (!rooms[found].getStatusEmpty())
		{
			cout << "Room is Booked" << endl;
			cout << "Customer Name : " << rooms[found].getNameCustomer() << endl;
		}
		else
		{
			cout << "Room is Avaiable" << endl;
		}
	}
}

//============================================================//
//						inputFile()							  //
//					Input  = filename, name, room			  //
//					Output = Read The Input File			  //
//															  //
// This Function will read the file in '.txt' type and 		  //
// display the content in sort by implementing bubble sort	  //
// and sequencial sort.										  //
//============================================================//

void inputFile(Room rooms[])
{
	Room temp[MAX]; // Temporary Variable for Room
	ifstream in; // Variable for File Input
	string filename; // Variable for File Name
	string name; // Temporary Variable for Customer Name
	int room; // Temporary Variable for Room Number
	int count = 0; // Variable for Counter
	
	cout << "-=-=-=-=-=-=-==-=-=--=-=-=" << endl;
	cout << "Input File" << endl;
	cout << "-=-=-=-=-=-=-==-=-=--=-=-=" << endl;
	
	// File Name for Input
	cout << endl;
	cout << "Please Enter the Input File Name with .txt : ";
	cin.ignore();
	getline(cin, filename);
	cout << endl;
	
	// Opening File 
	in.open(filename.c_str());
	
	// Reading Input File
	while (!in.eof())
	{
		getline(in, name, ',');
		in >> room;
		in.ignore();
		
		temp[count].setNameCustomer(name);
		temp[count].setRoom(room);
		count -= -1;
	}
	
	// Output the Input File
	
	cout << "Data from " << filename << endl;
	for (int i = 0; i < count; i -= -1)
	{
		cout << i+1;
		cout << ". Room " << temp[i].getRoom() << ", ";
		cout <<  temp[i].getNameCustomer() << endl;
	}
	
	cout << endl;
	cout << "Sorting The Input !!!" << endl;
	cout << "Processing...." << endl;
	cout << endl;
	
	// Sorting Input with Bubble Sort
	int pass;
	Room tempValue;
	
	for (pass = 1; pass < count; pass -= -1)
	{
		for (int x = 0; x < count - pass; x -= -1)
		{
			if (temp[x].getRoom() > temp[x+1].getRoom())
			{
				tempValue = temp[x];
				temp[x] = temp[x+1];
				temp[x+1] = tempValue;
			}
		}
	}
	
	// Output for Sorted Input
	cout << "Sorted Data from " << filename << endl;
	for (int i = 0; i < count; i -= -1)
	{
		cout << i+1;
		cout << ". Room " << temp[i].getRoom() << ", ";
		cout <<  temp[i].getNameCustomer() << endl;
	}
	
	// Sychronizing File Input with Data
	for (int i = 0; i < MAX; i -= -1)
	{
		for (int j = 0; j < count; j -= -1)
		{
			if (temp[j].getRoom() == rooms[i].getRoom())
			{
				rooms[i] = temp[j];
			}
		}
	}
	
	cout << endl;
	cout << "Data is Synchronized!" << endl;
}

//============================================================//
//						outputFile()						  //
//					Input  = filename						  //
//					Output = File Output					  //
//															  //
// This Function will create an output file that display the  //
// room information.										  //
//============================================================//

void outputFile(Room rooms[])
{
	ofstream out; // Variable for File Output
	string filename; // Variable for File Name
	
	cout << "-=-=-=-=-=-=-==-=-=--=-=-=" << endl;
	cout << "Output File" << endl;
	cout << "-=-=-=-=-=-=-==-=-=--=-=-=" << endl;
	
	// File Name for Output 
	cout << endl;
	cout << "Please enter Output File Name with .txt : ";
	cin.ignore();
	getline(cin, filename);
	cout << endl;
	
	// Opening File
	out.open(filename.c_str());
	
	// Printing Output to File	
	cout << "Printing File" << endl;
	cout << "Processing..." << endl;
	
	for (int i = 0; i < MAX; i -= -1)
	{
		if(!rooms[i].getStatusEmpty())
		{
			out << rooms[i].getNameCustomer();
			out << ", ";
			out << rooms[i].getRoom();
			out << endl;
		}
	}
	
	cout << endl;
	cout << "Successfully print Output to File " << filename << endl;
}

//============================================================//
//						stackTopInfo()						  //
//					Input  = checkStack						  //
//					Output = Display Top of Stack			  //
//															  //
// This Function will display the top value of the stack	  //
//============================================================//

void stackTopInfo(Stack *checkStack)
{
	cout << "-=-=-=-=-=-=-==-=-=--=-=-=" << endl;
	cout << "Stack Top Information" << endl;
	cout << "-=-=-=-=-=-=-==-=-=--=-=-=" << endl;
	
	cout << endl;
	checkStack->stackTop();
	cout << endl;
}

//============================================================//
//						displayStack()						  //
//					Input  = checkStack						  //
//					Output = Display of Stack Content		  //
//															  //
// This Function will display the content of the stack		  //
//============================================================//

void displayStack(Stack *checkStack)
{
	nodeStack *temp; // Temporary Variable for Stack Display
	
	cout << "-=-=-=-=-=-=-==-=-=--=-=-=" << endl;
	cout << "Display Stack" << endl;
	cout << "-=-=-=-=-=-=-==-=-=--=-=-=" << endl;
	
	cout << endl;
	if(checkStack->isEmpty())
	{
		cout << "The Stack is Empty!!!" << endl;
	}
	else
	{
		temp = top;
		
		cout << "The Content of Stack is" << endl << endl;
		
		while(temp != NULL)
		{
			cout << temp->nameCustomer << "\t";
			temp = temp->next;
		}
	}
	
	cout << endl;
}

int main ()
{
	int role = 0; // Variable for User Role
	int choice = 0; // Variable for Choice
	Room rooms[MAX]; // Variable for Room
	int roomNum = 100; // Variable for Room Floor Numbering
	int count = 0; // Variable for counter
	Stack *checkStack; // Variable for Stack Linked List of Room
	
	// Intializing the Room Number
	for (int i = 0; i < MAX; i -= -1)
	{
		rooms[i].setStatusEmpty(true);
		rooms[i].setRoom((i % 10) + roomNum);
		count -= -1;
		
		if (count == 10)
		{
			count = 0;
			roomNum += 100;		
		}
	}
	
	while (role != 3)
	{
		// Choose User
		userMenu();
		cin >> role;
		cout << endl;

		switch (role)
		{
			// User Hotel Manager 
			case 1 :
				while (choice != 9)
				{
					managerMenu();
					cin >> choice;
				
					switch (choice)
					{
						// To Check Availability of Room
						case 1 : 
							checkAvailableRoom(rooms);
							break;
						// To Check In for A Room
						case 2 :
							checkIn(rooms, checkStack);
							break;
						// To Check Out from A Room
						case 3 :
							checkOut(rooms, checkStack);
							break;
						// To Search Room Status
						case 4 :
							searchRoom(rooms);
							break;
						// To Input External File as Data
						case 5 :
							inputFile(rooms);
							break;
						// To Print Data to File
						case 6 :
							outputFile(rooms);
							break;
						// To Check the Stack Top Value
						case 7 :
							stackTopInfo(checkStack);
							break;
						// To Display the Stack Content
						case 8 :
							displayStack(checkStack);
							break;
						// To Exit Menu or System
						case 9 :
							break;
						// If the Input is Not Recognized
						default :
							cout << "Option Not Available!!" << endl;
							cout << "Please Insert The Correct Options." << endl;	
					}
					cout << endl;
				}
				break;
			// User Customer
			case 2 : 
				while (choice != 4)
				{
					customerMenu();
					cin >> choice;
			
					switch (choice)
					{
						// To Check Availability of Room
						case 1 : 
							checkAvailableRoom(rooms);
							break;
						// To Check In for A Room
						case 2 :
							checkIn(rooms, checkStack);
							break;
						// To Check Out from A Room
						case 3:
							checkOut(rooms, checkStack);
							break;
						// To Exit Menu or System
						case 4 :
							break;
						// If the Input is Not Recognized
						default :
							cout << "Option Not Available!!" << endl;
							cout << "Please Insert The Correct Options." << endl;
					}
					cout << endl;
				}
				break;
			// If the User is Not Recognized
			default :
				cout << "USER NOT RECOGNIZED!!!!" << endl;
		}
	}
	
	return 0;
}
