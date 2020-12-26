#include "Person.h"

const int Person::num_of_role = NONE;

/*
name:Person
parameters:id, fullName
return value:this object
algorithm:call setters
*/
Person::Person(const char* id,const char* fullName, Role role)
{
	setId(id);
	setFullName(fullName);
	setRole(role);
}
/*
name:Person
parameters:role
return value:this object
algorithm:Enter ID number and name per person and call setter for fole 
*/
Person::Person(Role role)
{
	char tmpId[10], tmpName[100];
	cout << "enter id: ";
	cin.clear();
	fflush(stdin);
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(tmpId, 10);
	setId(tmpId);
	cin.clear();
	fflush(stdin);
	cout << "enter full name: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(tmpName, 100);
	setFullName(tmpName);
	setRole(role);
}
/*
name:Person
parameters:p
return value:this object
algorithm:Enter NULL in dynamic values and run operator =
*/
Person::Person(const Person& p)
{
	this->id = NULL;
	this->fullName =NULL;
	*this = p;
}

void Person::setRole(const Role& role) 
{
	if(!(role==PASSENGER || role == PILOT || role == BARTENDER || role == STEWARDESS))
		throw invalid_argument("Error SetRole - Role given is not in the list!");

	
	this->role = role;
}
/*
name:setId
parameters:id
return value:none
algorithm:check if is valid (only numbers)
if ok set data
else throw INVALID_ID
*/
void Person::setId(const char* id)
{
	if(id==NULL)
		throw invalid_argument("Argument passed to SetID is NULL");

	
	int length=strlen(id);//get size of id
	if (length != 9)
		throw invalid_argument("ID size isn't valid, must be 9 digits!");
	
	for(int i=0;i<length;++i)
	{
		if(!(id[i]>='0' && id[i]<='9'))
			throw logic_error("Logic Error SetID: ID Contains Characters");
	}
	
	this->id=_strdup(id);
}
/*
name:setFullName
parameters:full name
return value:none
algorithm:check if is valid
if ok set data
else throw INVALID_NAME
*/
void Person::setFullName(const char* fullName)
{
		if(fullName==NULL)
		throw invalid_argument("Argument passed to SetFullname is NULL");
	
	int length=strlen(fullName);//get size of name
	for(int i=0;i<length;++i)
	{
		if(fullName[i]>='0' && fullName[i]<='9')
			throw logic_error("Logic Error SetFullName: Name Contains Digits");
	}
	
	this->fullName=_strdup(fullName);

}

/*
name:operator==
parameters: peson to compare
return value:true if equal
algorithm:compare between the person's ids
*/
bool Person::operator==(const Person& person) const
{
	return strcmp(this->id,person.id)==0;
}
/*
name:operator<
parameters:person to compare
return value:true if small
algorithm:compare between the person's ids and return if this < id
*/
bool Person::operator<(const Person& person) const
{
	return strcmp(this->id, person.id)<0;
}
/*
name:operator>
parameters:person to compare
return value:true if greater
algorithm:check if person is NOT equal AND NOT bigger then this (using De morgan laws)
*/
bool Person::operator>(const Person& person) const
{
	return !(*this<person || *this==person);
}
/*
name:operator>
parameters:person to compare
return value:true if greater
algorithm:check if person is NOT bigger then this
*/
bool Person::operator>=(const Person& person) const
{
	return !(*this<person);
}

const Person& Person::operator=(const Person& p)
{
	if (this != &p) 
	{
		this->id = _strdup(p.id);
		this->fullName = _strdup(p.fullName);
		this->role = p.role;
	}
	return *this;
}

Person::~Person()
{
	delete[]id;
	delete[]fullName;
}
/*
name:operator<<
parameters:output stream, person to display,
return value:output stream for continous
algorithm: display the person
*/
ostream& operator<<(ostream& out, const Person& p)
{
	out << left << setw(12) << setfill(' ') << "";
	out << left << setw(12) << setfill(' ') << p.id << " ";
	out << left << setw(12) << setfill(' ') << p.fullName << " ";
	out << left << setw(12) << setfill(' ') << (p.role == PASSENGER ? "PASSENGER" : p.role == PILOT ? "PILOT" : p.role == BARTENDER ? "BARTENDER" : "STEWARDESS");
	out << left << setw(93) << setfill(' ') << "" << endl;
	return out;
}


