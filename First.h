#pragma once
#include "Capsule.h"

class First: public Capsule
{
	private:
	bool laying;
	bool entertainment;
	const Person* mozeg;

	public:
	//constructor
	First(const Person& mozegi,int cap=0, int price=0,bool lay=false, bool enter=false);
	//gets
	bool getLaying()const {return laying;}
	bool getEntertainment()const {return entertainment;}
	const Person* getMozeg()const { return mozeg; }
	//sets
	void setLaying(bool x){laying=x;}
	void setEntertainment(bool x){entertainment=x;}
	void setMozeg(const Person& mozegi);
	//operator overloading
	friend ostream& operator<< (ostream& out, const First& f);
	//operator int() const { Capsule tmp = *this; return tmp; }
	
	void operator+=(AirlineTicket& tk) { Capsule::operator+=(tk); }
	void operator-=(AirlineTicket& tk) { Capsule::operator-=(tk); }

	//~First(){ std::cout << "\n\nFirst Destructor\n";}
	
};

