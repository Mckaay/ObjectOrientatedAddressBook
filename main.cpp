#include <iostream>
#include "UserManager.h"

using namespace std;

int main()
{
    UserManager userManager("Users.txt");

    userManager.registration();
    userManager.displayUsers();

    return 0;
}
