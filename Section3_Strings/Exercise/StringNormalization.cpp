#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include  <bits/stdc++.h>


using namespace std;

string Normalize(const string &sentence);

int main()
{
    string input;
    getline(cin, input);

    cout << Normalize(input) << endl;
    return 0;
}

string Normalize(const string &sentence)
{
    string copy(sentence);

    for(int i = 0; i < sentence.length();)
    {
        while(i < sentence.length() && sentence[i] == ' ')
            i++;

        while(i < sentence.length() && sentence[i] != ' ')
        {
            if(i == 0 || (i > 0 && sentence[i - 1] == ' '))
                copy[i] = toupper(copy[i]);
            else
                copy[i] = tolower(copy[i]);
            i++;
        }
    }
    return copy;
}
