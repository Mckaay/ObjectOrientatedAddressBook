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
