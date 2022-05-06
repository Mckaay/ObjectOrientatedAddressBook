#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt","Persons.txt");

    addressBook.displayWholeAddressBook();

    system("pause");
    system("cls");

    addressBook.deletePerson();

    system("pause");
    system("cls");

    addressBook.addPersonToBook();
    addressBook.displayWholeAddressBook();

    return 0;
}
