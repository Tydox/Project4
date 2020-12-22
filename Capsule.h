#pragma once
#include "AirlineTicket.h"
//#include "Person.h"
#include "DateTime.h"
//#include "Person.h"
//#include "Flight.h"

class Capsule
{
	private:

	int price;
	int capacity;
	AirlineTicket** at;
	int numOfTickets;

		//set
		void setCapacity(int num) { if (!(num > 0)) throw invalid_argument("Invalid Capacity Number"); capacity = num; }
	
	public:
		//constructor
		Capsule(int p = 0, int c = 0):at(),numOfTickets(0) { this->setPrice(p); this->setCapacity(c);}
		
		//set
		void setPrice(int num) { price = num; }		

		//gets
		int getPrice() { return price; }
		int	getCapacity() { return capacity; }
		int	getNumofTickets() { return numOfTickets; }

		//regular methods
		AirlineTicket** getTickets() { return at; }
		bool isFull() { return (capacity == numOfTickets); }
		bool isEmpty() { return (numOfTickets == 0); }

		//operator overloading
		void operator+=(AirlineTicket& tk);
		void operator-=(AirlineTicket& tk);
		friend ostream& operator<< (ostream&, const Capsule&);
		operator int() const { return (capacity - numOfTickets); }
	
};

