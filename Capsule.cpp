#include "Capsule.h"

Capsule::~Capsule()
{
	//print deletion proccess for log 
	//std::cout << "\nCapsule Destructor\n"; //debug
	for (int i = 0; i < numOfTickets; ++i)
	{
		delete at[i]; //delete each ticket separately
		//std::cout << "Deleted ticket " << i << "#\n"; //debug

	}
	numOfTickets = 0; //set tickets num to 0 - empty
	delete[] at; //delete pointers array
	at = nullptr; //set pointer to null to avoid future conflicts
}

void Capsule::operator+=(AirlineTicket& tk)
{
	if (isFull())//check if capsule is full->throw exception
		throw out_of_range("Error: Operator +=, Capacity is full!");

	int i = 0;
	for(;i<numOfTickets;++i)//before adding a ticket, check if exist->throw exception
		if (*at[i] == tk)
			throw invalid_argument("Error: Operator +=, Given Ticket already exist");

	AirlineTicket** newALT = new AirlineTicket * [numOfTickets + 1]; //create a new array*

	if(isEmpty()) //first ticket to add
	{
		newALT[0] = new AirlineTicket(tk); //copy new ticket to new slot
		at = newALT; //empty array to new array
		++numOfTickets;//add 1 to Num Of Tickets 
		return; // stop running this method
	}
	
	for(i=0; i<numOfTickets;++i) //sec+ ticket to add
		newALT[i] = at[i];//copy old pointers to new array

	newALT[i] = new AirlineTicket(tk);//copy new ticket to new slot
	delete[] at; //delete old array
	at = newALT; //update old array to new array
	++numOfTickets; //add 1 to Num Of Tickets 
}

void Capsule::operator-=(AirlineTicket& tk)
{
	if (isEmpty())//check if capsule is empty->throw exception
		throw out_of_range("Error: Operator -=, Capacity is empty!");
	
	int i = 0;
	for (; i < numOfTickets; ++i) //if a ticket already exists find the relative index
		if ((*at[i]) == tk)
			break;
	
	if (i == numOfTickets)//if the given ticket was not found in the array throw exception
		throw out_of_range("Capsule::Operator-= did not find an equal ticket");

	//only if given ticket was found continue
	delete at[i]; //delete given ticket from the airline ticket array

	AirlineTicket** newALT = new AirlineTicket * [--numOfTickets]; //create a new airline ticket array*

	for(int j=0;j<i;++j)//copy all previous tickets to new array
		newALT[j] = at[j];
	for(int w=i+1; i<numOfTickets;++w,++i)//i=present, w=next, skip deleted index, continue to copy^
		newALT[i] = at[w];

	delete[] at; //delete old array
	at = newALT; //update old array to new array
}

const Capsule& Capsule::operator=(const Capsule& cup)
{
		if (this != &cup)
		{
			price = cup.price; //set to given price
			capacity = cup.capacity; //set to given capacity
			numOfTickets = 0; //set numoftickets to 0, will be updated after next loop
			for (int i = 0; i < cup.numOfTickets; ++i)//copy all tickets from given capsule
				this->operator+= (*(cup.at[i]));
		}
		return *this;
}


ostream& operator<<(ostream& out, const Capsule& c)
{
	//print all capsule data
	out << endl;
	out << left << setw(17) << setfill(' ') <<"Print Capsule:";
	out << left << setw(10) << setfill(' ') << "Capacity";
	out << left << setw(10) << setfill(' ') << "Price";
	out << left << setw(10) << setfill(' ') << "Num of tickets"<<endl;
	out << left << setw(93) << setfill('_') << "" << endl;
	
	out << left << setw(17) << setfill(' ') << "";
	out << left << setw(10) << setfill(' ') << c.capacity;
	out << left << setw(10) << setfill(' ') << c.price;
	out << left << setw(10) << setfill(' ') << c.numOfTickets<<endl<<endl;

	out << left << setw(25) << setfill(' ') << "Print Tickets:";
	out << left << setw(20) << setfill(' ') << "Ticket #";
	out << left << setw(12) << setfill(' ') << "Meal";
	out << left << setw(15) << setfill(' ') << "Ticket Type"<<endl;
	out << left << setw(93) << setfill('_') << "" << endl;

	for(int i=0;i<c.numOfTickets;++i) //print each ticket data
		out << *(c.at[i]);
	
	return out;
}