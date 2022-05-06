#include "PersonsTextFile.h"

vector<Person> PersonsTextFile::loadPersonDataFromTextFileToVector(int loggedInUserID)
{
    vector <Person> persons;

    fstream textFile;
    textFile.open(PERSONS_TEXT_FILE_NAME,fstream::in);

    string textLine;
    int startPosition;

    while(getline(textFile,textLine))
    {
        Person person;

        startPosition = 0;
        person.setID(stoi(textLine.substr(startPosition,textLine.find("|",startPosition) - startPosition)));
        lastPersonId = person.getId();

        startPosition = textLine.find("|",startPosition)+1;
        person.setUserId(stoi(textLine.substr(startPosition,textLine.find("|",startPosition) - startPosition)));

        if(person.getUserId() != loggedInUserID) continue;

        startPosition = textLine.find("|",startPosition)+1;
        person.setName(textLine.substr(startPosition,textLine.find("|",startPosition) - startPosition));

        startPosition = textLine.find("|",startPosition)+1;
        person.setSurname(textLine.substr(startPosition,textLine.find("|",startPosition) - startPosition));

        startPosition = textLine.find("|",startPosition)+1;
        person.setPhoneNumber(textLine.substr(startPosition,textLine.find("|",startPosition) - startPosition));

        startPosition = textLine.find("|",startPosition)+1;
        person.setEmailAdress(textLine.substr(startPosition,textLine.find("|",startPosition) - startPosition));

        startPosition = textLine.find("|",startPosition)+1;
        person.setAdress(textLine.substr(startPosition,textLine.find("|",startPosition) - startPosition));

        persons.push_back(person);
    }
    textFile.close();
    return persons;
}

int PersonsTextFile::getLastPersonId()
{
    return this->lastPersonId;
}

void PersonsTextFile::savePersonToTextFile(Person person)
{
    fstream textFile;
    textFile.open(PERSONS_TEXT_FILE_NAME,fstream::app);

    textFile << person.getId() <<"|" << person.getUserId() << "|" << person.getName() <<"|"<< person.getSurname() << "|" << person.getPhoneNumber() << "|";
    textFile << person.getEmailAdress() << "|" << person.getAdress() << "|" << endl;

    textFile.close();

    lastPersonId++;
}

void PersonsTextFile::rewriteTextFileAfterDeletion(int deletingId)
{
    fstream personsTextFile;
    personsTextFile.open(PERSONS_TEXT_FILE_NAME.c_str(),fstream::in);

    if (!personsTextFile.good())
    {
        cout << "Problem z plikiem ksiazka adresowa!";
        exit(0);
    }

    fstream temporaryTextFile;
    temporaryTextFile.open("tymczasowy.txt",fstream::out);

    if (!temporaryTextFile.good())
    {
        cout << "Problem z tymczasowym plikiem!";
        exit(0);
    }

    string textFileLine;
    int startPosition;
    int currentPersonID;

    while(getline(personsTextFile,textFileLine))
    {
        startPosition = 0;
        currentPersonID = stoi(textFileLine.substr(startPosition,textFileLine.find("|",startPosition) - startPosition));
        if((currentPersonID == deletingId) ) continue;
        else
        {
            lastPersonId = currentPersonID;
            temporaryTextFile << textFileLine << endl;
        }
    }
    personsTextFile.close();
    remove(PERSONS_TEXT_FILE_NAME.c_str());
    temporaryTextFile.close();
    rename("tymczasowy.txt",PERSONS_TEXT_FILE_NAME.c_str());
}

void PersonsTextFile::rewriteTextFileAfterEdition(int editedID,Person person)
{
    fstream personTextFile;
    personTextFile.open(PERSONS_TEXT_FILE_NAME,fstream::in);

    if (!personTextFile.good())
    {
        cout << "Problem z plikiem ksiazka adresowa!";
        exit(0);
    }

    fstream temporaryTextFile;
    temporaryTextFile.open("tymczasowy.txt",fstream::out);

    if (!temporaryTextFile.good())
    {
        cout << "Problem z tymczasoym plikiem!";
        exit(0);
    }

    string textFileLine;
    int startPosition;
    int currentPersonID;

    while(getline(personTextFile,textFileLine))
    {
        startPosition = 0;
        currentPersonID = stoi(textFileLine.substr(startPosition,textFileLine.find("|",startPosition) - startPosition));
        if(currentPersonID == editedID)
        {
            temporaryTextFile << person.getId() << "|" << person.getUserId() <<"|"<< person.getName() <<"|"<< person.getSurname() << "|" << person.getPhoneNumber() << "|";
            temporaryTextFile << person.getEmailAdress() << "|" << person.getAdress() << "|" << endl;
        }
        else
        {
            temporaryTextFile << textFileLine << endl;
        }
    }
    personTextFile.close();
    remove(PERSONS_TEXT_FILE_NAME.c_str());
    temporaryTextFile.close();
    rename("tymczasowy.txt",PERSONS_TEXT_FILE_NAME.c_str());
}
