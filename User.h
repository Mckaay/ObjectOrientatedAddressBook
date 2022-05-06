#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

struct User
{
    int ID;
    string login;
    string password;

public:

    User(int ID = 1,string login = "admin",string password = "admin")
    {
        this->ID = ID;
        this->login = login;
        this->password = password;
    }
    void setId(int id);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getId();
    string getLogin();
    string getPassword();
};

#endif
