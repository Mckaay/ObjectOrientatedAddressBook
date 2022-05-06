#include "Person.h"

void Person::setID(int id)
{
    this->id = id;
}

void Person::setUserId(int userId)
{
    this->userId = userId;
}
void Person::setName(string name)
{
    this->name = name;
}

void Person::setSurname(string surname)
{
    this->surname = surname;
}

void Person::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Person::setEmailAdress(string emailAdress)
{

    this->emailAdress = emailAdress;
}

void Person::setAdress(string adress)
{
    this->adress = adress;
}

int Person::getId()
{
    return this->id;
}
int Person::getUserId()
{
    return this->userId;
}
string Person::getName()
{
    return this->name;
}
string Person::getSurname()
{
    return this->surname;
}
string Person::getPhoneNumber()
{
    return this->phoneNumber;
}
string Person::getEmailAdress()
{
    return this->emailAdress;
}
string Person::getAdress()
{
    return this->adress;
}
