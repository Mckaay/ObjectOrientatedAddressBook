#include "AddressBook.h"

void AddressBook::registration()
{
    userManager.registration();
}

void AddressBook::loggingIn()
{
    userManager.loggingIn();
    if(userManager.getLoggedinUserId())
    {
        personManager = new PersonManager(PERSONS_TEXT_FILE_NAME,userManager.getLoggedinUserId());
    }
}

void AddressBook::changePassword()
{
    userManager.changePassword();
}

void AddressBook::logout()
{
    personManager->cleanVector();
    userManager.logout();
}

void AddressBook::displayWholeAddressBook()
{
    personManager->displayWholeAdressBook();
}

void AddressBook::addPersonToBook()
{
    personManager->addPersonToBook();
}

void AddressBook::searchByName()
{
    personManager->searchByName();
}

void AddressBook::searchBySurname()
{
    personManager->searchBySurname();
}

void AddressBook::deletePerson()
{
    personManager->deletePerson();
}

void AddressBook::editPerson()
{
    personManager->editPersonData();
}

int AddressBook::getLoggedInUserId()
{
    return userManager.getLoggedinUserId();
}

char AddressBook::mainMenu()
{
    char decision;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    cin >> decision;
    return decision;
}

void AddressBook::personMenu()
{
    cout << "MENU UZYTKOWNIKA" << endl;
    cout << "--------------------" << endl;
    cout << "1. Dodaj osobe" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl wszystkich adresatow" << endl;
    cout << "5. Usun osobe" << endl;
    cout << "6. Edytuj osobe" << endl;
    cout << "--------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "--------------------" << endl;
    cout << "Twoj wybor: ";
}

