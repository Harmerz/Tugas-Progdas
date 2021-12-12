/**
 * Project Person Register Application
 */


#ifndef _CONTACT_H
#define _CONTACT_H
#include "Person.h"

class Contact
{
public:
    string upper(string up);
    void insertContact(Person p);
    void deleteContact(Person a, int ini, int tukar);
    void editContact(Person a,int ini);
    Person getAllContact(int b);
    Person getOneContact(int angka);
    void Sorting(int sort);
};

#endif //_REGISTER_H