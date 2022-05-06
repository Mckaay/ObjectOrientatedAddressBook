#include <iostream>
#include "UserManager.h"

using namespace std;

int main()
{
    UserManager userManager("Users.txt");

    userManager.displayUsers();

    userManager.loggingIn();

    return 0;
}
