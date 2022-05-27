// Declaration of Person Class

#ifndef PRACTICEPERSONCLASS1_PERSON_H
#define PRACTICEPERSONCLASS1_PERSON_H

#include <iostream>
using std::string;
using std::istream;
using std::ostream;

class Person
{
private:
    char* _name;                        // _name as a pointer since we don't know length ot name/s will be given later
    char _phone[11];                    // U.S. phone number is
    int _level;                          // indication how close someone is
public:
    Person(const char* nm, const char* ph, int lv = 0);          // class constructor
    Person(const Person& person);                                // copy constructor
    const Person& operator=(const Person& person);         // copy assignment operator
    ~Person();                                                   // destructor
    string GetName() const;
    string GetPhone() const;
    int GetLevel() const;
    string ToString() const;
    string ToJson() const;
    bool Equal(const Person& person)const;                        // to compare phone number
    istream& Read(istream& input);
    ostream& Write(ostream&);
};

#endif //PRACTICEPERSONCLASS1_PERSON_H
