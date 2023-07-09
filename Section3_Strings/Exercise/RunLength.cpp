#include <iostream>
#include <string>
#include <map>

using namespace std;

string Compress(const string &str);
string JoinMap(map<char,int> &charCounter);

int main()
{
    string input;

    getline(cin,input);

    cout << Compress(input) << endl;
    return 0;
}

string Compress(const string &str)
{
    map<char,int> characterCounter;
    string compress;
    char temp = ' ';

    for(char character: str)
    {
        if(characterCounter.find(character) != characterCounter.end())
            characterCounter[character]++;
        else
            characterCounter[character] = 1;
    }

    for(char character: str)
    {
        if(temp != character)
        {
            compress += (character + to_string(characterCounter[character]));
            temp = character;
        }
    }

    //compress = JoinMap(characterCounter);
    return compress.length() < str.length()? compress : str;
}

string JoinMap(map<char,int> &charCounter)
{
    string join;
    for(auto &pair : charCounter)
        join += pair.first + to_string(pair.second);

    return join;
}
