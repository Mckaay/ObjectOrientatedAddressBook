#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person
{
    int userId;
    int id;
    string name;
    string surname;
    string phoneNumber;
    string emailAdress;
    string adress;

public:
    Person(int userID = 1,int ID = 1,string name = "Jan",string surname = "Kowalski",string phoneNumber = "12345678",string emailAdress  = "a@wp.pl",string = "ul. Jana")
    {
        this->userId = userId;
        this->id= ID;
        this->name = name;
        this->surname = surname;
        this->phoneNumber = phoneNumber;
        this->emailAdress = emailAdress;
        this->adress = adress;
    }

    void setID(int id);
    void setUserId(int userId);
    void setName(string name);
    void setSurname(string surname);
    void setPhoneNumber(string hhoneNumber);
    void setEmailAdress(string emailAdress);
    void setAdress(string adress);

    int getId();
    int getUserId();
    string getName();
    string getSurname();
    string getPhoneNumber();
    string getEmailAdress();
    string getAdress();

};


#endif
