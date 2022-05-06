#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <windows.h>
#include <conio.h>
#include <algorithm>
#include <cstdio>

using namespace std;

class Methods
{
public:
    static bool isNameOrSurnameValid(string word);
    static string changeFirstLetterToUpperCaseRestToLowerCase(string word);
    static bool isEmailAdressValid(string emailAdress);
    static string loadLine();
    static bool isChar(char c);
    static void pauseProgram();



};
