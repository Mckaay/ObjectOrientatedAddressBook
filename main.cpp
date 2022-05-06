#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt","Persons.txt");

    addressBook.displayWholeAddressBook();

    system("cls");

    addressBook.searchByName();

    system("pause");
    system("cls");

    addressBook.searchBySurname();

    return 0;
}
