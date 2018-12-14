/*		   
*			Lab_3 - Inheritance and overloading
*
*		   Name:	Soban Farhan
*					Musab Nair
*
*		   Date:	30th, September 2018
*	
*	Description:	This is lab is combination of our old WorkTicket class.
*					A new class is made which is used to inherit attributes from 
*					WorkTicket class. The new class will use be to inherit and overload
*					the existing attributes and methods. 
*
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

//Including the provided header file
#include "MyLabC3WorkTicket.h"

using namespace std;


//Declaring a new class and using header file class for inheritance
class ExtendedWorkTicket : public WorkTicket
{

	public:
		
		//Default constructor - calls default constructor of base class and sets status as open
		//ExtendedWorkTicket(){ WorkTicket(); IsOpen = true;}
		ExtendedWorkTicket():WorkTicket(), IsOpen(true){}
		
		//Parameterized constructor - with attribute inherited from the WorkTicket class
		ExtendedWorkTicket(int ticketNumber, string clientId, int month, int day, int year, 
		string description, bool ticketOpen) : WorkTicket(ticketNumber, clientId, month, day, year, description), IsOpen(ticketOpen) {}
		
		// Overloaded SetWorkTicket method
		bool SetWorkTicket(int ticketNumber, string clientId, int day, int month, int year,
		 string description, bool ticketOpen);
		
		// ShowWorkTicket Overload
		void ShowWorkTicket() const;
		
		//Mutator
		void SetTicketStatus(bool status) {IsOpen = status;}	
		
		//Accessor - Get the status of the Tickert
		bool GetTicketStatus() const { return IsOpen; }			
		
		// closes the ticket 
		void CloseTicket(){ IsOpen = false;}		
		
		// Use the out operator to display the output to the user. 
		friend ostream& operator<<(ostream& out, const ExtendedWorkTicket& theTicket);
		
	private:
		
		// Bool for the IsOpen status on a ticket.
		bool IsOpen; 
 		
		
};

int main()
{
 ExtendedWorkTicket testTicket1;
 ExtendedWorkTicket testTicket2(1, "AMCE_123", 1, 7, 2014, "Password Reset", true);

 cout << endl << "As Initialized: " << endl;
 testTicket1.ShowWorkTicket();
 testTicket2.ShowWorkTicket();


 if(!testTicket1.SetWorkTicket(2, "MACDONALD-001", 10, 3, 2012, "User cannot locate \'any\' key.", true))
 cout << "\nErrors! No changes to the ticket made." << endl;

 cout << endl << "Ticket 1: " << testTicket1 << endl;

 if(!testTicket2.SetWorkTicket(-1, "BLAGO-042", 13, 32, 11, "", false))
 cout << "\nErrors! No changes to the ticket made." << endl;

 cout << endl << "Ticket 2: " << testTicket2 << endl;
 testTicket2.CloseTicket();

 cout << endl << "After Ticket 2 closed: " << testTicket2 << endl;

 cout << endl << endl;
 return 0;
}

//SetWorkTicket overload implementation
bool ExtendedWorkTicket::SetWorkTicket(int ticketNumber, string clientId, int day, int month, int year,
string description, bool ticketOpen)
{
	bool argumentsSet = false;
	
	if(WorkTicket::SetWorkTicket(ticketNumber, clientId, day, month, year, description))
	{
		IsOpen = ticketOpen;
		argumentsSet = true;
	}
	
	return argumentsSet;
}

//ShowWorkTicket
void ExtendedWorkTicket::ShowWorkTicket() const
{
	string status;		//variable to hold the status
	if(IsOpen == true){status = "OPEN";}
	else {status = "CLOSED";}
	//Call base version of the method
	WorkTicket::ShowWorkTicket();
	//Append the ticket status info
	cout << "Ticket: " << status <<endl;
}

ostream& operator<<(ostream& out, const ExtendedWorkTicket& theTicket)
{
	string status;		//variable to hold the status
	if(theTicket.GetTicketStatus() == true){status = "OPEN";}
	else {status = "CLOSED";}
	
	out << (WorkTicket)theTicket <<"Ticket: " << status << endl;
	return out;
}
