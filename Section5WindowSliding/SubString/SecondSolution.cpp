#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string UniqueSubString(string str);


int main()
{
    string input;
    cin >> input;
    cout << UniqueSubString(input) << endl;
    return 0;
}

string UniqueSubString(string str)
{
    int i = 0, j = 0;
    int window_len = 0,max_window_len = 0,start_window = -1;

    unordered_map<char,int> map;

    while(j < str.length())
    {
        char ch = str[j];

        //if the character is repeated inside the substring
        if(map.count(ch) && map[ch] >= i)
        {
            //we move the start index one place to the right of the repeated character index
            i = map[ch] + 1;
            window_len = j - i; // updated the window len excluding the current character
        }

        map[ch] = j; //update character index
        window_len++;
        j++;

        if(window_len > max_window_len)
        {
            max_window_len = window_len;
            start_window = i;
        }
    }

    return str.substr(start_window,max_window_len);
}