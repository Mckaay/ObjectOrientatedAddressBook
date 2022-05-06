#ifndef PERSONSTEXTFILE_H
#define PERSONSTEXTFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <windows.h>
#include <algorithm>
#include <cstdio>

#include "Person.h"
#include "textFile.h"

using namespace std;

class PersonsTextFile: public TextFile
{
    int lastPersonId;

public:
    PersonsTextFile(string personsTextFileName): TextFile(personsTextFileName)
    {
        lastPersonId = 0;
    };
    vector<Person> loadPersonDataFromTextFileToVector(int loggedInUserID);
    int getLastPersonId();
    void savePersonToTextFile(Person person);
    void rewriteTextFileAfterDeletion(int deletingId);
    void rewriteTextFileAfterEdition(int editedID,Person person);
};

#endif
