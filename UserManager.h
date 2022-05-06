#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

#include "User.h"
#include "UsersTextFile.h"

using namespace std;

class UserManager
{

    int loggedInUserId;
    vector <User> users;
    UsersTextFile usersTextFile;

    bool checkIfUserAlreadyExists(string checkedUserLogin);
    int getNewUserId();
    int checkIfCorrectPassword(string login,string password);

public:

    UserManager(string usersFileName): usersTextFile(usersFileName)
    {
        loggedInUserId = 0;
        users = usersTextFile.loadUserDataFromTextFileToVector();
    };
    int getLoggedinUserId();
    void displayUsers();
    void registration();
    void loggingIn();
    void changePassword();
    void logout();

};



#endif
