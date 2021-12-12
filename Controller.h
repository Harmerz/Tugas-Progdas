#ifndef _CONTROLLER_H
#define _CONTROLLER_H

class Controller
{
    public:
    void commandLoop();
    void addContact();
    void viewContact();
    void viewThisContact(int ganti);
    void editThisContact(int ganti);
    void deleteThisContact(int ganti);
};

#endif
