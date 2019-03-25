#include "Child.h"
#include <iostream>
#include <string>

Child::Child() 
{
    firstName = " ";
    lastName = " ";
    age = 0;
}

Child::Child(string first, string last, int age) 
{
    firstName = first;
    lastName = last;
    this->age = age;
}

Child::Child(string first, string last) 
{
    firstName = first;
    lastName  = last;
    this->age = 0;
}

Child::Child(string last) 
{
    firstName = " ";
    lastName = last;
    this->age = 0;
}

Child::~Child() 
{
    //cout << "Object deleted" <<endl;
}

void Child::setFirst(const string first) 
{
    firstName = first;
}

void Child::setName(const string first, const string last)
{
    firstName = first;
    lastName = last;
}

void Child::setLast(const string last) 
{
    lastName = last;
}

void Child::setAge(const int age) 
{
    this->age = age;
}

string Child::getFirst() const 
{
    return firstName;
}

string Child::getlast() const 
{
    return lastName;
}

int Child::getAge() const 
{
    return age;
}

bool Child::operator==(const Child &source) const 
{
    //cout << "a donkey" << endl;
    if(this -> firstName == source.firstName)
    {
        if(this -> lastName == source.lastName)
        {
            if(this -> age == source.age)
            {
                //cout << "I am here" << endl;
                return true;
            }
        }			
    }
    return false;
}
  
bool Child::operator!=(const Child &source) const 
{
    return !(*this == source);
}

bool Child::operator>(const Child& source) const 
{
    if (this->lastName >source.lastName)  //compares last name first
    {
        return true;
    } 
    else if(this -> lastName == source.lastName)
    {
        if (this->firstName > source.firstName) //compares first name later
        {
            return true;
        }
        else if(this->firstName == source.firstName)
        {
            if(this->age > source.age)
            {
                return true;
            }
        }
    }
   return false;
}

bool Child::operator<(const Child& source) const 
{
    if(!(*this > source) && !(*this == source)) //must be opposite
        return true;
    return false;
}

/*
 By default a copy constructor performs a shallow copy.
 For a deepy copy, you need to overwrite the constructor
 with a copy constructor.
 */
void Child::operator=(const Child &source) 
{
    //cout << "Assignment operator is running" << endl;
    firstName = source.firstName;
    lastName = source.lastName;
    age = source.age;
}


ostream& operator<<(ostream &outStream, const Child&Source)
{
    if(Source.firstName != " ")
    {
        cout << Source.firstName << " ";
    }
    if(Source.lastName != " ")
    {
	cout << Source.lastName << " ";
    }
    if(Source.age != 0)
    {
	cout << Source.age;
    }
    return outStream;
}