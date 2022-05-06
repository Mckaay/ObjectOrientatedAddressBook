#include "Methods.h"

string Methods::loadLine()
{
    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}

bool Methods::isChar(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
    else return false;
}

bool Methods::isNameOrSurnameValid(string word)
{
    for(int i = 0 ; i < word.length(); i++)
    {
        if(!Methods::isChar(word[i])) return false;
    }
    return true;
}

string Methods::changeFirstLetterToUpperCaseRestToLowerCase(string word)
{
    if (!word.empty())
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word[0] = toupper(word[0]);
    }
    return word;
}

bool Methods::isEmailAdressValid(string emailAdress)
{
    int atIndex = -1;
    int lastDotIndex = -1;

    if(!isChar(emailAdress[0])) return false;
    else if(!isChar(emailAdress[emailAdress.length()-1])) return false;

    for(int i = 0 ; i < emailAdress.length(); i++)
    {
        if(emailAdress[i] == '@') atIndex = i;
        else if(emailAdress[i] == '.') lastDotIndex = i;
    }
    if(atIndex == -1 || lastDotIndex == -1) return false;
    else if(lastDotIndex < atIndex) return false;

    return true;
}

void Methods::pauseProgram()
{
    cout << "Nacisnij dowolny przycisk by powrocic do Menu Glownego" << endl;
    getch();
    system("cls");
}

