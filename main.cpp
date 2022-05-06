#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{

    AddressBook addressBook("Users.txt","Persons.txt");
    while(!addressBook.getLoggedInUserId())
    {
        char decision;
        decision = addressBook.mainMenu();
        switch(decision)
        {
        case '1':
            addressBook.registration();
            Methods::pauseProgram();
            break;
        case '2':
            addressBook.loggingIn();
            Methods::pauseProgram();
            break;
        case '9':
            exit(0);
        default:
            cout << "Cos poszlo nie tak!" << endl;
            exit(0);
        }
        while(addressBook.getLoggedInUserId())
        {
            system("cls");
            addressBook.personMenu();

            cin >> decision;

            switch(decision)
            {
            case '1':
                system("cls");
                addressBook.addPersonToBook();
                Methods::pauseProgram();
                break;
            case '2':
                system("cls");
                addressBook.searchByName();
                Methods::pauseProgram();
                break;
            case '3':
                system("cls");
                addressBook.searchBySurname();
                Methods::pauseProgram();
                break;
            case '4':
                system("cls");
                addressBook.displayWholeAddressBook();
                Methods::pauseProgram();
                break;
            case '5':
                system("cls");
                addressBook.deletePerson();
                Methods::pauseProgram();
                break;
            case '6':
                system("cls");
                addressBook.editPerson();
                break;
            case '7':
                system("cls");
                addressBook.changePassword();
                Methods::pauseProgram();
                break;
            case '8':
                addressBook.logout();
                Methods::pauseProgram();
                break;
            default:
                cout << "Cos poszlo nie tak! Zly wybor" << endl;
                break;
            }
        }
    }
    return 0;
}
