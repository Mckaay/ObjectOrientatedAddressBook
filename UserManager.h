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

public:

    UserManager(string usersFileName): usersTextFile(usersFileName)
    {
        loggedInUserId = 0;
        users = usersTextFile.loadUserDataFromTextFileToVector();
    };
    void displayUsers();
    void registration();


};



#endif
