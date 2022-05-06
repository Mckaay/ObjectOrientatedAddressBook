#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "UserManager.h"
#include "PersonManager.h"

using namespace std;

class AddressBook
{
    UserManager userManager;
    PersonManager personManager;


public:
    AddressBook(string usersFileName,string personsFileName): userManager(usersFileName), personManager(personsFileName,1){};
    void registration();
    void loggingIn();
    void changePassword();
    void logout();
    void displayWholeAddressBook();

};


#endif
