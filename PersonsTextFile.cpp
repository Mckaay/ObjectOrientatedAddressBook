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
