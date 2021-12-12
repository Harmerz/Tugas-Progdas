#include "Controller.h"
#include "Contact.h"
#include "Person.h"
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


using namespace std;
Person contact;
Contact reg;
int counting=0;

void Controller::commandLoop(){
    char pilih;
    system("CLS");
    cout << "=============================================" << endl;
	cout << "**                                         **" << endl;
	cout << "**        PHONEBOOK APPLICATION            **" << endl;
	cout << "**                                         **" << endl;
	cout << "=============================================" << endl;
	cout << "||                                         ||" << endl;
	cout << "||  Fitur :                                ||" << endl;
	cout << "||  1. View Contact                        ||" << endl;
	cout << "||  2. Add Contact                         ||" << endl;
	cout << "||  3. Exit                                ||" << endl;
	cout << "||                                         ||" << endl;
	cout << "=============================================" << endl;
	cout << "\n";
    pilih = getch();
    switch (pilih)
    {
    case '1':
        viewContact();
        break;
    case '2':
        addContact();
        break;
    case '3':
        exit (0);
        break;
    default:commandLoop();
    } 
    system("PAUSE");
    getch();
}

void Controller::addContact()
{
    system("CLS");
    string nama, nomor, email,a;
    cout << "=============================================" << endl;
	cout << "**                                         **" << endl;
	cout << "**  	      Menambahkan Kontak            **" << endl;
	cout << "**                                         **" << endl;
	cout << "=============================================" << endl;
	cout << endl;
	cout << "\t*** Masukkan Nama: ***" << endl << "\t    ";
	cin >> nama;
	cout << "                                             " << endl;
	cout << "\t*** Masukkan Nomor: ***" << endl << "\t    ";
	cin >> nomor;
	cout << "                                             " << endl;
	cout << "\t*** Masukkan Email: ***" << endl << "\t    ";
	cin >> email;
	cout << "\n=============================================" << endl;
    //cin>>a;

    Person newperson(nama,nomor,email);
    reg.insertContact(newperson);
    counting++;
    Contact Sorting;
    Sorting.Sorting(counting);
    commandLoop();
}

void Controller::viewContact(){
    system("CLS");
    string pilih;
    string nama, nomor, email;
    int ganti=0;
    cout << "=============================================" << endl;
	cout << endl;
	cout << "          **** DAFTAR KONTAK ****            " << endl;
    cout << endl;
    cout << "=============================================" << endl;
    cout << "                                             " << endl;
	for(int i=0;i<counting;i++){
        contact = reg.getAllContact(i);
        contact.print();
    }
	cout << "                                             " << endl;
	cout << "=============================================" << endl;
    printf("0. Kembali\n");
    cout << "=============================================" << endl;
    printf("Pilih untuk melihat kontak atau kembali : ");
    cin>>pilih;
    int panjang = pilih.length();
    for(int i=0;i<panjang;i++){
        ganti = ganti*10 + (int)pilih[i] -48;
    }
    ganti--;

    if(ganti == -1){
        commandLoop();
    }else if(ganti>=0 && ganti<counting){
        viewThisContact(ganti);
    };
}
void Controller::viewThisContact(int ganti){
    system("CLS");
    contact = reg.getOneContact(ganti);
    contact.cetak();
    printf("1. Edit Contact");
    printf("\n2. Delete Contact");
    printf("\n0. Kembali\n");
    cout << "=============================================" << endl;
    char memilih=getch();
    if(memilih == '0')viewContact();
    else if(memilih == '1')editThisContact(ganti);        
    else if(memilih == '2')deleteThisContact(ganti);
    else viewThisContact(ganti);
}

void Controller::editThisContact(int ganti){
    system("CLS");
    contact = reg.getOneContact(ganti);
    contact.cetak();
    string nama,nomor,email;
    cout << "=============================================" << endl;
	cout << endl;
	cout << "\t*** Ganti Nama Menjadi: ***" << endl <<"\t\t";
	cin >> nama;
	cout << "                                             " << endl;
	cout << "\t*** Ganti Nomor Menjadi: ***" << endl<<"\t\t";
	cin >> nomor;
	cout << "                                             " << endl;
	cout << "\t*** Ganti Email Menjadi: ***" << endl<<"\t\t";
	cin >> email;
	cout << "=============================================" << endl;
    editing:
    system("CLR");
    contact = reg.getOneContact(ganti);
    contact.cetak();
    cout<<endl;
    cout << "=============================================" << endl;
    cout << "**             Yang ada Ganti :            **"<<endl;
    cout << "=============================================" << endl;
    cout << endl;
    cout << " Nama : "<<nama<<endl;
    cout << " Nomor : "<<nomor<<endl;
    cout << " Email : "<<email<<endl;
    cout << endl;
    cout << "=============================================" << endl;
	cout << "**                                         **" << endl;
	cout << "**   Yakin ingin Mengedit Kontak?(Y/N)     **" << endl;
	cout << "**                                         **" << endl;
	cout << "=============================================" << endl;
    char edit=getch();
    if(edit == 'y' || edit == 'Y'){
        Person newperson(nama,nomor,email);
        reg.editContact(newperson, ganti);
        commandLoop();
    }else if(edit == 'n' || edit == 'N'){
        viewContact();
    }else{
        goto editing;
    }
}

void Controller::deleteThisContact(int ganti){

    cout << "=============================================" << endl;
	cout << "**                                         **" << endl;
	cout << "**   Yakin ingin Menghapus Kontak?(Y/N)    **" << endl;
	cout << "**                                         **" << endl;
	cout << "=============================================" << endl;
    char deleting=getch();
    string nama="", nomor="", email="";
    if(deleting == 'y' || deleting == 'Y'){
        Person newperson(nama,nomor,email);
        int pengganti=counting-1;
        reg.deleteContact(newperson, ganti, pengganti);
        counting--;
        // Contact Sorting;
        // Sorting.Sorting(counting);
        commandLoop();
    }else if(deleting == 'n' || deleting == 'N'){
        cout<<endl<<endl;
        viewThisContact(ganti);
    }else{
        viewThisContact(ganti);
    }
}