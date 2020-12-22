#include "Capsule.h"

void Capsule::operator+=(AirlineTicket& tk)
{
	if (isFull())
		throw out_of_range("Error: Operator +=, Capacity is full!");

	int i = 0;
	for(;i<numOfTickets;++i)
		if (*at[i] == tk)
			throw invalid_argument("Error: Operator +=, Given Ticket already exist");


	AirlineTicket** newALT = new AirlineTicket * [numOfTickets+1];

	if(isEmpty()) //first ticket to add
	{
		newALT[0] = &tk;
		at = newALT;
		++numOfTickets;
		return;
	}
	
	for(i=0; i<numOfTickets;++i) //sec+ ticket to add
	{
		newALT[i] = at[i];//copy old pointers to new array
	}
	newALT[i] = &tk;//copy new ticket to new slot

	delete[] at;

	at = newALT;
	++numOfTickets;
}

void Capsule::operator-=(AirlineTicket& tk)
{
	int i = 0;
	for (; i < numOfTickets; ++i) //find the index is exists
		if ((*at[i]) == tk)
			break;
	
	if (i == numOfTickets)//no cards were found
		throw out_of_range("Capsule::Operator-= did not find an equal ticket");

	delete at[i];

	AirlineTicket** newALT = new AirlineTicket * [--numOfTickets];

	for(int j=0;j<i;++j)//copy all previous
		newALT[j] = at[j];
	for(int w=i+1; i<numOfTickets;++w,++i)//i=present, w=next
		newALT[i] = at[w];

	
	delete[] at;
	
	at = newALT;
}


ostream& operator<<(ostream& out, const Capsule& c)
{
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

	for(int i=0;i<c.numOfTickets;++i)
		out << *(c.at[i]);
	
	return out;
}