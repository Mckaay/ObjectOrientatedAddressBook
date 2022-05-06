#include "User.h"

void User::setId(int id)
{
    ID = id;
}
void User::setLogin(string newLogin)
{
    login = newLogin;
}
void User::setPassword(string newPassword)
{
    password = newPassword;
}

int User::getId()
{
    return ID;
}
string User::getLogin()
{
    return login;
}
string User::getPassword()
{
    return password;
}
