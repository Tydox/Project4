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
		int getPrice()const { return price; }
		int	getCapacity()const { return capacity; }
		int	getNumofTickets()const { return numOfTickets; }

		//regular methods
		AirlineTicket** getTickets() { return at; }
		bool isFull()const { return (capacity == numOfTickets); }
		bool isEmpty()const { return (numOfTickets == 0); }

		//operator overloading
		void operator+=(AirlineTicket& tk);
		void operator-=(AirlineTicket& tk);
		friend ostream& operator<< (ostream&, const Capsule&);
		operator int() const { return (capacity - numOfTickets); }

		~Capsule()
		{
				std::cout << "\nCapsule Destructor\n";
				for (int i = 0; i < numOfTickets; ++i)
				{
					delete at[i];
					std::cout << "Delete ticket " << i << "#\n";

				}
				numOfTickets = 0;
				delete[] at;
				at = nullptr;
		}



		Capsule(const Capsule& cup)//copy
		{		
			*this = cup;
		}

		const Capsule& operator=(const Capsule& cup)//op==
		{
			if (this != &cup)
			{
				price = cup.price;
				capacity = cup.capacity;
				numOfTickets = 0;
				for(int i=0;i<cup.numOfTickets;++i)
				{
					this->operator+= (*(cup.at[i]));
				}
				
			}
			return *this;
		}
};

