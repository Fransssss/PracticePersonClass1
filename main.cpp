// Title: practice create a simple program with a class 
// Purpose: practice dynamically memory, set value, and deallocate allocated memory
// Author : Fransiskus Agapa
// Have fun - enjoy the process - Practices make improvement

#include <iostream>
#include "Person.h"
#include <cctype>
using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::isalpha;
using std::isdigit;
using std::cerr;

int main()
{
    string name, phone;
    int level = 0;
    int invalidCount = 0;

    cout << endl << "Input data of a person - \n-Name \n-Phone Number (10 digits) "
                    "\n-Rate 1 to 10 how close you with the person" << endl << endl;

    cout << "Name: ";
    getline(cin,name);
    cout << endl;

    cout << "Phone number: ";
    cin >> phone;
    cout << endl;

    cout << "Rate how close you to the person 1 out of 10:" << endl;
    cin >> level;
    cout << endl;

    if(phone.length() != 10)                                // Phone Number should have 10 digits only (U.S. system)
    {
        ++invalidCount;
    }

    for(size_t i = 0; i < phone.length(); ++i)
    {
        if(!isdigit(phone[i] ))                            // if there is alphabet then increment invalid counter
            ++invalidCount;
    }

    if(invalidCount > 0)
    {
        cerr << "[Data is invalid]" << endl;
        return -1;
    }else                                                   // if nothing wrong with data inputing
    {
        Person fPerson(name.c_str(),phone.c_str(),level);
        cout << fPerson.ToString() << endl;
        cout << fPerson.ToJson() << endl;
    }
    return 0;
}