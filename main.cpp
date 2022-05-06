#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt","Persons.txt");

    addressBook.loggingIn();

    addressBook.displayWholeAddressBook();
    return 0;
}
