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

void PersonManager::addPersonToBook()
{
    Person person;
    person.setUserId(LOGGEDIN_USER_ID);
    person.setID(personsTextFile.getLastPersonId());

    cout << "DODAWANIE NOWEGO ADRESATA" << endl;

    cout << "PODAJ IMIE: ";
    person.setName(Methods::loadLine());

    while(!Methods::isNameOrSurnameValid(person.getName()))
    {
        cout<<"Niepoprawne imie " << endl;
        cout<< "Podaj imie ponownie: ";
        person.setName(Methods::loadLine());
    }
    person.setName(Methods::changeFirstLetterToUpperCaseRestToLowerCase(person.getName()));

    cout << "PODAJ NAZWISKO: ";
    person.setSurname(Methods::loadLine());

    while(!Methods::isNameOrSurnameValid(person.getSurname()))
    {
        cout<<"Niepoprawne nazwisko " << endl;
        cout<< "Podaj nazwisko ponownie: ";
        person.setSurname(Methods::loadLine());
    }
    person.setSurname(Methods::changeFirstLetterToUpperCaseRestToLowerCase(person.getSurname()));

    cout << "PODAJ NUMER TELEFONU: ";
    person.setPhoneNumber(Methods::loadLine());


    cout << "PODAJ ADRES EMAIL: " ;
    person.setEmailAdress(Methods::loadLine());

    while(!Methods::isEmailAdressValid(person.getEmailAdress()))
    {
        cout<<"Niepoprawnie wpisany adres email. Przyklad: jan.kowalski@wp.pl" <<endl;
        cout<<"Podaj adres email ponownie: ";
        person.setEmailAdress(Methods::loadLine());
    }

    cout << "PODAJ ADRES: ";
    person.setAdress(Methods::loadLine());

    persons.push_back(person);
    personsTextFile.savePersonToTextFile(person);

    cout << "Dodawanie przebieglo pomyslnie" << endl;
}

void PersonManager::searchByName ()
{
    bool exist = false;
    string searchedName;

    cout << "Podaj wyszukiwane imie: " ;
    cin >> searchedName;
    cout << endl;

    cout << "Wyniki dla wyszukiwanego imienia: " << endl;
    cout <<"-----------------------------------------------" << endl;

    for(auto it1 = persons.begin(); it1 != persons.end(); it1++)
    {
        if (searchedName == it1->getName())
        {
            exist = true;
            printPersonData(*it1);
        }
    }
    if(!exist) cout << "Niestety nie posiadasz kontaktu o podanym imieniu" << endl;
}
