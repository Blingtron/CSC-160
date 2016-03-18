#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;
namespace Authenticate
{
    void inputUserName();
        // prompts user to enter username and stores it. Must be 8 or more characters.
    string getUserName();
        // returns user name.
}

#endif // USER_H
