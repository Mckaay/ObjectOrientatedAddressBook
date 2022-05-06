#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "UserManager.h"

using namespace std;

class AddressBook
{
    UserManager userManager;

public:
    AddressBook(string usersFileName): userManager(usersFileName){};
    void registration();
    void loggingIn();
    void changePassword();
    void logout();



};


#endif
