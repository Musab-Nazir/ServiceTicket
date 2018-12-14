/** MyLab04WorkTicket_Test.cpp
 *	
 *	Testing the header for C++ Lab 3 (Lab C3).
 *   
 *	@author		Thom MacDonald
 *	@version	2018.01
 *	@since		Jul 2018
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
 *	@see		OOP3200.LabC1.Classes.pdf
 *	@see		OOP3200.LabC2.OperatorsAndConversion.pdf
 *	@see		OOP3200.LabC3.Inheritance.pdf
 *	@see		MyLabC3WorkTicket.h
 *	@see		MyDate.h
*/

#include <iostream>		// for cin, cout
#include "MyLabC3WorkTicket.h" 	// version 2018.02
#include "MyConsoleInput.h" // for ReadInteger()

using namespace std;
using namespace ConsoleInput;

void LabC1Requirements();
void LabC2Requirements();

int main()
{
	char choice;
	bool needInput = true;
	do
	{
		cout << "\nMENU " << endl
			 << "=====" << endl << endl
			 << "\'1\' Run C++ Lab 1 Requirements" << endl
			 << "\'2\' Run C++ Lab 2 Requirements" << endl
			 << "\'Q\' to Quit" << endl << endl
			 << ": ";
			 
		fflush(stdin);
		choice = cin.get();
		choice = toupper(choice);
		
		switch(choice)
		{
			case '1':
				LabC1Requirements();
				break;
			case '2':
				LabC2Requirements();
				break;
			case 'Q':
				needInput = false;
				break;
			default:
				cout << "\nUnrecognized choice. Please try again.";
		}
	}while (needInput);
  
	cout << endl << endl;
	return 0;
}

void LabC1Requirements()
{
 	 // DECLARATIONS
	 const int NUMBER_OF_TICKETS = 3;
	 WorkTicket tickets[NUMBER_OF_TICKETS]; //	an array of at least three WorkTicket objects.
	 int ticketNumber;	 // temporary input variable
	 string clientId;	 // temporary input variable
	 int day;			 // temporary input variable
	 int month;			 // temporary input variable
	 int year;			 // temporary input variable
	 string description; // temporary input variable
	 	 
	 cout << "\n******************************************************" << endl;
	 cout << "             C++ Lab 1 Requirements" << endl;
	 cout << "            " << (string) MyDate::Today() << endl;
	 cout << "******************************************************" << endl << endl;
	 
	 // INPUT
	 for(int index = 0; index < NUMBER_OF_TICKETS; index++)
	 {
	 	 // prompt for user input for each attribute and
	 	 // store in the corresponding temp variable
		  cout << "\nWorkTicket [" << index << "]: " << endl;
		  cout << "\nEnter ticket number: ";
		  ticketNumber = ReadInteger();
		  
		  //fflush(stdin); 
		  cin.sync();
		  cout << "Enter client ID: ";
		  getline(cin, clientId);
	 	  
	 	  cout << "Enter day number: ";
		  day = ReadInteger();
		  cout << "Enter month number: ";
	 	  month = ReadInteger();
	 	  cout << "Enter year number: ";
	 	  year = ReadInteger();
	 	  
		  //fflush(stdin);
		  cin.sync();
		  cout << "Enter issue decription: ";
	 	  getline(cin, description);
	 	  
	 	  
	 	 //	The input loop should call the SetWorkTicket( ) method.  
	 	 // if setting the work ticket to the temp variables works: 
	 	 if(tickets[index].SetWorkTicket(ticketNumber, clientId, month, day, year, description))
	 	 {
	 	 	cout << "\nSuccess! WorkTicket[" << index << "] is set." << endl;
	 	 }
	 	 else
	 	 {
	 	 	cout << "\nInput Error! WorkTicket[" << index << "] will remain unchanged." << endl;
	 	 }
	 }
	 
	 // Use an output loop to display each of the work tickets in the array.
	 cout << "\n\nWorkTicket Array Contents" << endl
	 	  << "=========================" << endl;
	 for(int index = 0; index < NUMBER_OF_TICKETS; index++)
	 {
	 	tickets[index].ShowWorkTicket();
	 }
	 
     cout << endl;
}

void LabC2Requirements()
{ 
	//Declare a new object based on an existing object.
	WorkTicket ticket1(1, "ABC-123", 1, 4, 2014, "Password Reset");
	WorkTicket ticket2 = ticket1;
	
	cout << "\n******************************************************" << endl;
	cout << "             C++ Lab 2 Requirements" << endl;
	cout << "            " << (string) MyDate::Today() << endl;
	cout << "******************************************************" << endl << endl;
	
	
	//Typecast an object as a string and output it to the console.
	cout << (string) ticket1 << endl;
	
	//Have the user input an object's attributes from the console using cin.
	cin >> ticket2;
	
	//Test if two objects are equal.
	if(ticket1 == ticket2)
	{
		cout << endl << (string) ticket1 << " is the same as " 
			 << endl << (string) ticket2 << endl;
	}
	else
	{
		cout << endl << (string) ticket1 << " is different than " 
			 << endl << (string) ticket2 << endl;
	}
	
	//Assign an existing object to another existing object.
	ticket1 = ticket2;
	
	//Output an object to the console using cout.
	cout << ticket1 << endl;
	 
    cout << endl;
}
