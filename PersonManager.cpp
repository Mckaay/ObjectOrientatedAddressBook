#include "PersonManager.h"

void PersonManager::printPersonData(Person person)
{
    cout << "ID Adresata:      " << person.getId() << endl;
    cout << "Imie:            " << person.getName() << endl;
    cout << "Nazwisko:        " << person.getSurname() << endl;
    cout << "Numer telefonu:  " << person.getPhoneNumber() << endl;
    cout << "Ares Email:      " << person.getEmailAdress() << endl;
    cout << "Adres:           " << person.getAdress()<< endl;
    cout <<"-----------------------------------------------" << endl;
}


void PersonManager::displayWholeAdressBook()
{
    if(persons.empty()) cout<<"Ksiazka Adresowa jest pusta!Dodaj do niej kogos."<<endl;
    else
    {
        auto it1 = persons.begin();
        for(it1 ; it1 != persons.end(); it1++)
        {
            printPersonData(*it1);
        }
    }
}
