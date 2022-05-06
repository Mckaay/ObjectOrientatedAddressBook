#include <iostream>
#include "UserManager.h"

using namespace std;

int main()
{
    UserManager userManager;

    userManager.registration();
    userManager.displayUsers();

    return 0;
}
