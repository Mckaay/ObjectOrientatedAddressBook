#include "AddressBook.h"

void AddressBook::registration()
{
    userManager.registration();
}

void AddressBook::loggingIn()
{
    userManager.loggingIn();
}

void AddressBook::changePassword()
{
    userManager.changePassword();
}

void AddressBook::logout()
{
    userManager.logout();
}

void AddressBook::displayWholeAddressBook()
{
    personManager.displayWholeAdressBook();
}

void AddressBook::addPersonToBook()
{
    personManager.addPersonToBook();
}

void AddressBook::searchByName()
{
    personManager.searchByName();
}
