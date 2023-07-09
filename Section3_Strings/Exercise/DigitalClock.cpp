#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

void ReplaceCharacter(string &str,char character);
string ConvertToDigitalTime(int minutes);

int main()
{
   int minutes;
   cin >> minutes;
   cout << ConvertToDigitalTime(minutes);
   return 0;
}

void ReplaceCharacter(string &str,char character, char newCharacter)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == character)
        {
            str[i] = newCharacter;
            return;
        }
    }
}

string ConvertToDigitalTime(int minutes)
{
    //complete this function
    float rawHours = (float)minutes / 60;

    float hours = (float)(round((fmod(rawHours * 100, 100) * 60)/100) / 100) + (int)rawHours;
    stringstream digitalTime;
    digitalTime << fixed << setprecision(2)  << hours;
    string time = digitalTime.str();
    ReplaceCharacter(time,'.',':');
    return time;
}