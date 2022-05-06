#ifndef USERSTEXTFILE_H
#define USERSTEXTFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>

#include "User.h"

using namespace std;

class UsersTextFile
{
    const string USERS_FILE_NAME;

public:
    UsersTextFile(string fileName): USERS_FILE_NAME(fileName) {};
    void saveUsersToTextFile(vector<User> users);
    vector<User> loadUserDataFromTextFileToVector();

};


#endif
