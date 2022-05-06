#include "UsersTextFile.h"

void UsersTextFile::saveUsersToTextFile(vector<User> users)
{
    fstream textFile;
    textFile.open(USERS_FILE_NAME,fstream::out);

    for(auto it1 = users.begin(); it1 != users.end(); it1++ )
    {
        textFile << it1->ID <<"|"<< it1->login <<"|"<< it1->password << "|" << endl;
    }
    textFile.close();
}

vector<User> UsersTextFile::loadUserDataFromTextFileToVector()
{
    vector<User> users;

    fstream textFile;
    textFile.open(USERS_FILE_NAME,fstream::in);


    string textFileLine;
    int startPosition;

    while(getline(textFile,textFileLine))
    {
        User user;
        startPosition = 0;
        user.setId(stoi(textFileLine.substr(startPosition,textFileLine.find("|",startPosition) - startPosition)));

        startPosition = textFileLine.find("|",startPosition)+1;
        user.setLogin(textFileLine.substr(startPosition,textFileLine.find("|",startPosition) - startPosition));

        startPosition = textFileLine.find("|",startPosition)+1;
        user.setPassword(textFileLine.substr(startPosition,textFileLine.find("|",startPosition) - startPosition));

        users.push_back(user);
    }
    return users;
}
