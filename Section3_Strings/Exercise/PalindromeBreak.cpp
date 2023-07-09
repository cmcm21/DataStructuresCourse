#include <iostream>
#include <string>

using namespace std;

string Reverse(string &str);
bool IsPalindrome(string &str);
string BreakPalindrome(string &str);

int main()
{
    string input;

    getline(cin, input);

    cout << BreakPalindrome(input) << endl;

    return 0;
}

string Reverse(string &str)
{
    string reverse;

    for(auto it = str.end() - 1; it >= str.begin(); it--)
        reverse += *it;

    return reverse;
}

bool IsPalindrome(string &str)
{
    return str == Reverse(str);
}

string BreakPalindrome(string &str)
{
    if(str.length() <= 1) return "";

    char minChar = 97;
    char maxChar = 122;

    for(char c = minChar; c <= maxChar; c++)
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] <= c && i < str.length() - 1) continue;
            string copy(str);

            copy[i] = c;
            if(!IsPalindrome(copy))
                return copy;
        }
    }

    return "";
}

