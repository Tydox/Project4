#pragma once
#include "AirlineTicket.h"
#include "Capsule.h"
#include "Person.h"
#include "DateTime.h"
#include "Person.h"
#include "Flight.h"



class First
{
	private:

	bool laying;
	bool entertainment;
	Person* mozeg;

	public:

	First(const Person& mozegi,int cap=0, int price=0,bool lay=false, bool enter=false);
	
	bool getLaying(){return laying;}
	bool getEntertainment(){return entertainment;}
	Person* getMozeg(){return mozeg;}

	void setLaying(bool x){laying=x;}
	void setEntertainment(bool x){entertainment=x;}
	void setMozeg(const Person& mozegi);

	friend ostream& operator<< (ostream& out, const First& f);
	
};

