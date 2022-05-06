#ifndef USERSTEXTFILE_H
#define USERSTEXTFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>

#include "User.h"
#include "textFile.h"

using namespace std;

class UsersTextFile: public TextFile
{

public:
    UsersTextFile(string fileName): TextFile(fileName) {};
    void saveUsersToTextFile(vector<User> users);
    vector<User> loadUserDataFromTextFileToVector();

};


#endif
