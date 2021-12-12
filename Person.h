/**
 * Project Person Register Application
 */


#ifndef _PERSON_H
#define _PERSON_H
 
#include <string>

using namespace std;

class Person
{
public:
    void print() const;
       //Function to output the first name and last name
       //in the form firstName lastName.
    void cetak() const;
        //mencetak salah satu kontak
    void setName(string first, string last);
      //Function to set firstName and lastName according 
      //to the parameters.
      //Postcondition: firstName = first; lastName = last

    string getFirstName() const;
      //Function to return the first name.
      //Postcondition: The value of firstName is returned.

    string getLastName() const;
      //Function to return the last name.
      //Postcondition: The value of lastName is returned.

    string getCity() const;
      //function to return city

    Person(string nama = "", string nomor = "", string email = "");
      //Constructor
      //Sets firstName and lastName according to the parameters.
      //The default values of the parameters are null strings.
      //Postcondition: firstName = first; lastName = last  

 private:
    string firstName; //variable to store the first name
    string isinomor;
    string isiemail;
    
};

#endif //_PERSON_H

