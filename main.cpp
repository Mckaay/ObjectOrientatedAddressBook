#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt","Persons.txt");

    addressBook.displayWholeAddressBook();

    system("pause");
    system("cls");

    addressBook.editPerson();

    system("pause");
    system("cls");


    return 0;
}
