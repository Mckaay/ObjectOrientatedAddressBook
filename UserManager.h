#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

#include "User.h"

using namespace std;

class UserManager
{

    int loggedInUserId;
    vector <User> users;
    bool checkIfUserAlreadyExists(string checkedUserLogin);

    int getNewUserId();

public:

    UserManager()
    {
        loggedInUserId = 0;
    }
    void displayUsers();
    void registration();


};



#endif
