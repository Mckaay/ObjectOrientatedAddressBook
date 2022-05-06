#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "UserManager.h"
#include "PersonManager.h"

using namespace std;

class AddressBook
{
    UserManager userManager;
    PersonManager* personManager;
    const string PERSONS_TEXT_FILE_NAME;


public:
    AddressBook(string usersFileName,string personsFileName): userManager(usersFileName), PERSONS_TEXT_FILE_NAME(personsFileName)
    {
        personManager = NULL;
    };
    ~AddressBook()
    {
        delete personManager;
        personManager = NULL;
    }
    int getLoggedInUserId();
    void registration();
    void loggingIn();
    void changePassword();
    void logout();
    void displayWholeAddressBook();
    void addPersonToBook();
    void searchByName();
    void searchBySurname();
    void deletePerson();
    void editPerson();
    char mainMenu();
    void personMenu();
};


#endif
