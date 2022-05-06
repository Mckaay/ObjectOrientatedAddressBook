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
    person.setID(personsTextFile.getLastPersonId()+1);

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

void PersonManager::searchBySurname ()
{
    bool exist = false;
    string searchedSurname;

    cout << "Podaj wyszukiwane nazwisko: " ;
    cin >> searchedSurname;
    cout << endl;

    cout << "Wyniki dla wyszukiwanego nazwiska: " << endl;
    cout <<"-----------------------------------------------" << endl;

    for(auto it1 = persons.begin(); it1 != persons.end(); it1++)
    {
        if (searchedSurname == it1->getSurname())
        {
            exist = true;
            printPersonData(*it1);
        }
    }
    if(!exist) cout << "Niestety nie posiadasz kontaktu o podanym nazwisku" << endl;
}

bool PersonManager::checkIfPersonExistsInAdressBook(int checkedID)
{
    for(auto it1 = persons.begin(); it1 != persons.end(); it1++ )
    {
        if (it1 -> getId() == checkedID)  return true;
    }
    return false;
}

void PersonManager::deletePerson()
{
    int personID;
    char prove;
    char repeat;

    cout << "Podaj ID osoby do usuniecia: " << endl;
    cin >> personID;
    if(checkIfPersonExistsInAdressBook(personID))
    {
        for(auto it1 = persons.begin(); it1 <= persons.end(); it1++)
        {
            if (it1 -> getId() == personID)
            {
                cout<<"Czy na pewno usunac osobe z ksiazki adresowej t/n: ";
                cin>> prove;

                if(prove == 't')
                {
                    persons.erase(it1);
                    cout<<"Osoba zostala pomyslnie usunieta z ksiazki adresowej!" << endl;

                    personsTextFile.rewriteTextFileAfterDeletion(personID);
                    break;
                }
                else  break;
            }
        }
    }
    else
    {
        cout << "Nie ma osoby o podanym ID w ksiazce adresowej" << endl;
        cout << "Wybierz m jesli chcesz powrocic do menu, d jesli chcesz sprobowac ponownie: " << endl;
        cin >> repeat;

        if(repeat == 'm') cout << "Powrot do MENU" << endl;
        else deletePerson();
    }
}

void PersonManager::displayEditMenu()
{
    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
}

void PersonManager::editPersonData()
{
    int editingPersonID;
    int userChoice;
    string editedData;

    cout << "Wprowadz ID adresata ktorego chcesz edytowac " << endl;
    cin >> editingPersonID;

    if(checkIfPersonExistsInAdressBook(editingPersonID))
    {
        displayEditMenu();

        cin >> userChoice;
        cin.sync();

        if(userChoice < 6)
        {
            for(auto it1 = persons.begin(); it1 != persons.end(); it1++)
            {
                if (it1 -> getId() == editingPersonID)
                {
                    switch(userChoice)
                    {
                    case 1:
                        cout << "Wprowadz nowe imie: ";
                        it1 -> setName(Methods::loadLine());
                        break;
                    case 2:
                        cout << "Wprowadz nowe nazwisko: ";
                        it1 -> setSurname(Methods::loadLine());
                        break;
                    case 3:
                        cout << "Wprowadz nowy numer telefonu: ";
                        it1 -> setPhoneNumber(Methods::loadLine());
                        break;
                    case 4:
                        cout << "Wprowadz nowy adres email: ";
                        it1 -> setEmailAdress(Methods::loadLine());
                        break;
                    case 5:
                        cout << "Wprowadz nowy adres: ";
                        it1 -> setAdress(Methods::loadLine());
                        break;
                    default:
                        break;
                    }
                    personsTextFile.rewriteTextFileAfterEdition(editingPersonID,*it1);

                    cout<<"Kontakt po edycji: "<<endl;
                    cout <<"-----------------------------------------------" << endl;

                    printPersonData(*it1);
                    Methods::pauseProgram();
                }
            }
        }
    }
    else
    {
        cout << "Nie ma osoby o podanym ID w ksiazce adresowej" << endl;
        Methods::pauseProgram();
    }
}
