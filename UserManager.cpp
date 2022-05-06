#include "UserManager.h"

bool UserManager::checkIfUserAlreadyExists(string checkedUserLogin)
{
    for(auto it1 = users.begin(); it1 != users.end() ; it1++ )
    {
        if(it1->login == checkedUserLogin) return true;
    }
    return false;
}

void UserManager::displayUsers()
{
    if(users.empty()) cout << "Nie ma uzytkownikow" << endl;

    for(auto it1 = users.begin(); it1 != users.end() ; it1++ )
    {
        cout << it1->getId() << endl;
        cout << it1->getLogin() << endl;
        cout << it1->getPassword() << endl;
    }
}

int UserManager::getNewUserId()
{
    if(users.empty()) return 1;
    else return users.back().ID +1;
}

void UserManager::registration()
{
    string login;
    string password;

    cout << "Podaj nazwe uzytkownika: ";
    cin >> login;

    while(checkIfUserAlreadyExists(login))
    {
        cout << "Nazwa uzytkownika jest juz zajeta" << endl;
        cout << "Sprobuj jeszcze raz" << endl;
        cin >> login;
    }
    cout << "Podaj haslo: ";
    cin >> password;

    User user(getNewUserId(),login,password);
    users.push_back(user);

    usersTextFile.saveUsersToTextFile(users);
    cout << "Pomyslnie zarejestrowano uzytkownika!" << endl;
}

int UserManager::checkIfCorrectPassword(string login, string password)
{
    for(auto it1 = users.begin() ; it1 != users.end(); it1++)
    {
        if(it1->login == login)
        {
            if(it1->password == password) return it1->ID;
            else return 0;
        }
    }
    return 0;
}

void UserManager::loggingIn()
{
    string login;
    string password;

    cout << "Podaj login: ";
    cin >> login;

    int number;

    if(checkIfUserAlreadyExists(login))
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            cout << "Podaj haslo: ";
            cin >> password;
            number = checkIfCorrectPassword(login,password);
            if(number)
            {
                cout << "Pomyslnie zalogowano." << endl;
                loggedInUserId = number;
                return ;
            }
            else
            {
                cout << "Zle haslo. Pozostalo ci " << 2 - i << " proby. " << endl;
            }
        }
    }
    else cout << "Nie ma takiego uzytkownika!" << endl;
}

void UserManager::changePassword()
{
    string newPassword;

    cout << "Podaj nowe haslo: ";
    cin >> newPassword;

    for(auto it1 = users.begin(); it1 != users.end(); it1++ )
    {
        if (it1 -> getId() == loggedInUserId)
        {
            it1 -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione pomyslnie." << endl;
        }
    }
    usersTextFile.saveUsersToTextFile(users);
}

void UserManager::logout()
{
    loggedInUserId = 0;
    users.clear();
}

