#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt","Persons.txt");

    addressBook.displayWholeAddressBook();

    addressBook.searchByName();

    return 0;
}
