#include <iostream>
#include <string.h>
#include "Contact.h"
#include "Person.h"

using namespace std;
int isi=0;
Person contactList[2000];
string Contact::upper(string up){
    int panjang = up.length();
    for (int i=0; i < panjang; i++)
    {
        if ((int)up[i]>96 && (int)up[i]<123){
            /*  Converting lowercase characters to uppercase  */
            up[i] = up[i] - 32;
        }
    }
    return up;
}
void Contact::insertContact(Person a){
    contactList[isi] = a;
    isi++;
}
void Contact::deleteContact(Person a, int ini, int tukar){
    Person temp;
    temp = contactList[ini];
    contactList[ini] = contactList[tukar];
    contactList[tukar] = temp;
    contactList[tukar] = a;
    isi--;
}
void Contact::editContact(Person a,int ini){
    contactList[ini]=a;
}

Person Contact::getAllContact(int b){
    printf("%d. ", b+1);
    return contactList[b];
}
Person Contact::getOneContact(int angka){
    return contactList[angka];
}
void Contact::Sorting(int sort){
    Person temp;
    string satu,dua;
    for(int i=0;i<sort-1;i++){
        for(int j=i+1;j<sort;j++){
            satu = upper(contactList[i].getFirstName());
            dua = upper(contactList[j].getFirstName());
            // cout<<endl<<satu<<endl;
            if(satu>dua){
                temp = contactList[i];
                contactList[i] = contactList[j];
                contactList[j] = temp;
            }
        }
    }
}