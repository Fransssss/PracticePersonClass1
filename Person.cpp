// Implementation of Person Class

#include <cstring>                    // dealing with c-string, use c-string functions
#include <sstream>
#include "Person.h"

using std::stringstream;

Person::Person(const char *nm, const char *ph, int lv)
{
    _name = new char[strlen(nm)+1];                       // dynamically allocate a block of memory size+1 for null char
    strcpy(_name,nm);                             // _name is char so to take value, it has to be copied
    strcpy(_phone,ph);                            // _phone is fixed size so , value can be copied directly into it
    _level = lv;
}

Person::Person(const Person &person)                        // copy constructor
{
    _name = new char[strlen(person._name) + 1];         // dynamically allocate a block of memory size+1 for null char
    strcpy(_name, person._name);                // _name is char so to take value, it has to be copied
    strcpy(_phone, person._phone);              // _phone is fixed size so , value can be copied directly into it
    _level = person._level;
}

const Person& Person::operator=(const Person &person)       // copy assignment operator=
{
    if(strlen(_name) != strlen(person._name))       // see if the length is different
    {
        delete[] _name;
        _name = new char[strlen(person._name)+1];
    }
    strcpy(_name,person._name);
    strcpy(_phone,person._phone);
    _level = person._level;
    return *this;                                           // return updated value of data member
}

Person::~Person()
{
    delete[] _name;
}

string Person::GetName() const
{
    return string(_name);
}

string Person::GetPhone() const
{
    return _phone;
}

int Person::GetLevel() const
{
    return _level;
}

string Person::ToString() const
{
    stringstream st;
    st << "| String Format |  Name: " << _name << ", Phone: " << _phone << ", Level: " << _level;
    return st.str();
}

string Person::ToJson() const
{
    stringstream sj;
    sj << "| Json Format   | \"Name\": \"" << _name << "\", \"Phone\": " << _phone << ", \"Level\": " << _level;
    return sj.str();
}

bool Person::Equal(const Person &person) const                        // compare phone number
{
    if(strcmp(_phone,person._phone) == 0)
    {
        return true;                                                  // if the same
    }
    return false;
}

istream& Person::Read(istream &input)                                 // data in input is separated by space
{
    string name, phone;                                               // new variable to take data from input
    int level = 0;
    input >> name >> phone >> level;
    Person temp(name.c_str(), phone.c_str(), level);      // use c_str() since type of data members are char
    *this = temp;                                                     // assign new value to data member;
    return input;
}

ostream& Person::Write(ostream &output)
{
    output << _name << " " << _phone << " " << _level;
    return output;
}