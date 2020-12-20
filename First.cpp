#include "First.h"

First::First(const Person& mozegi, int cap, int price, bool lay, bool enter)
{
	setLaying(lay);
	setEntertainment(enter);
	setMozeg(mozegi);
	setPrice(price);
	SetCapacity(cap);
	
	
}

void First::setMozeg(const Person& mozegi)
	{
		if(mozegi.getRole()!=BARTENDER)
			throw logic_error("Bartender Required");

		*mozeg = mozegi;
	}

ostream& operator<<(ostream& out, const First& f)
{
	out << "\tLaying: " << f.laying
		<< "\tEntertainment: " << f.entertainment
		<< f.mozeg;
	return out;
}
