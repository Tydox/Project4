#pragma once
#include "Capsule.h"

class First: public Capsule
{
	private:
	bool laying;
	bool entertainment;
	const Person* mozeg;

	public:
	//constructor which acts as a copy constructor as well
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
	void operator+=(AirlineTicket& tk) { Capsule::operator+=(tk); }
	void operator-=(AirlineTicket& tk) { Capsule::operator-=(tk); }

	//destructor - prints when being used for debug
	//~First(){ std::cout << "\nFirst Destructor";}
};

