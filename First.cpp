#include "First.h"

First::First(const Person& mozegi, int cap, int price, bool lay, bool enter):Capsule(price,cap)
{
	setLaying(lay); //call method to set if chairs are laying
	setEntertainment(enter); // call method to set if there is entertainment on first class
	setMozeg(mozegi); // set who the stewardess is 
}

void First::setMozeg(const Person& mozegi)
	{
		if(mozegi.getRole()!=BARTENDER) //check if a person has valid role
			throw logic_error("Bartender Required"); //if not throw exception

	mozeg = &mozegi; //set given person(mozegi) as the first class stewardess(mozeg)
	}

ostream& operator<<(ostream& out, const First& f)
{
	//prints out the whole first class data
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

