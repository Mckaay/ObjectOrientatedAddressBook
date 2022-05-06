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

using namespace std;

class PersonsTextFile
{
    const string PERSONS_TEXT_FILE_NAME;
    int lastPersonId;

public:
    PersonsTextFile(string personsTextFileName): PERSONS_TEXT_FILE_NAME(personsTextFileName)
    {
        lastPersonId = 0;
    };
    vector<Person> loadPersonDataFromTextFileToVector(int loggedInUserID);
    int getLastPersonId();
    void savePersonToTextFile(Person person);


};

#endif
