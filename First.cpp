#include "First.h"

First::First(const Person& mozegi, int cap, int price, bool lay, bool enter):Capsule(price,cap)
{
	setLaying(lay);
	setEntertainment(enter);
	setMozeg(mozegi);
}

void First::setMozeg(const Person& mozegi)
	{
		if(mozegi.getRole()!=BARTENDER)
			throw logic_error("Bartender Required");

	mozeg = &mozegi;
	}

ostream& operator<<(ostream& out, const First& f)
{
	out << left << setw(25) << setfill(' ') << "Capsule First class:"<<endl;
	out << left << setw(17) << setfill(' ') << "Print Capsule:";
	out << left << setw(10) << setfill(' ') << "Laying";
	out << left << setw(17) << setfill(' ') << "Entertainment";
	out << left << setw(13) << setfill(' ') << "Mozeg ID";
	out << left << setw(12) << setfill(' ') << "Full Name";
	out << left << setw(12) << setfill(' ') << "Role" << endl;	
	out << left << setw(93) << setfill('_') << "" << endl;

	out << left << setw(17) << setfill(' ') << "";
	out << left << setw(10) << setfill(' ') << f.laying;
	out << left << setw(5) << setfill(' ') << f.entertainment
		<< *(f.mozeg)
		<< (Capsule&)f;
	
	return out;
}

