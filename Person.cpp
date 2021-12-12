#include <iostream>
#include <string>
#include "Person.h"
#include <stdlib.h>

using namespace std;

void Person::print() const
{
    cout << firstName << endl;
}
void Person::cetak() const{
    system("CLS");
    cout << "=============================================" << endl;
	cout <<  endl;	
	cout << "\tNama\t: " << firstName << endl;
	cout << "\tNomor\t: " << isinomor << endl;
	cout << "\tEmail\t: " << isiemail << endl;
	cout <<  endl;	
	cout << "=============================================" << endl;
}
string Person::getFirstName() const
{
    return firstName;
}

    //constructor
Person::Person(string nama, string nomor, string email) 
{ 
    firstName = nama;
    isinomor = nomor;
    isiemail = email;
}