#pragma once
#include "AirlineTicket.h"

class Capsule
{
	private:

	int price;
	int capacity;
	AirlineTicket** at;
	int numOfTickets;

		//set capacity of capsule
		void setCapacity(int num) { if (!(num > 0)) throw invalid_argument("Invalid Capacity Number"); capacity = num; }
	
	public:
		//constructor which acts as empty constructor as well
		Capsule(int p = 0, int c = 0):at(),numOfTickets(0) { this->setPrice(p); this->setCapacity(c);}
		//copy constructor
		Capsule(const Capsule& cup) { *this = cup; }
		//destructor
		~Capsule();
	
		//set price of capsule
		void setPrice(int num) { price = num; }		

		//gets - price,capacity,number of concurrent tickets
		int getPrice()const { return price; }
		int	getCapacity()const { return capacity; }
		int	getNumofTickets()const { return numOfTickets; }

		//return Airline Ticket pointer
		AirlineTicket** getTickets() const { return at; }
		//return if capsule is full
		bool isFull() const { return (capacity == numOfTickets); }
		//return if capsule is empty
		bool isEmpty() const { return (numOfTickets == 0); }

		//operator overloading
		//operator +=
		void operator+=(AirlineTicket& tk);
		//operator -=
		void operator-=(AirlineTicket& tk);
		//operator << cout
		friend ostream& operator<< (ostream&, const Capsule&);
		//operator casting class to int
		operator int() const { return (capacity - numOfTickets); }
		//operator =
		const Capsule& operator=(const Capsule& cup);
};

