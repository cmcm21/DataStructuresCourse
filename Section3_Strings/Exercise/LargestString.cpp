#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "..\Tokenization\TokenizationUtils.h"

using namespace std;

string Concatenate(vector<int> numbers);
bool CompareStrings(string &a, string &b);
bool CompareDecimals(int a ,int b);

int main()
{
    vector<int> inputs;
    string input;

    getline(cin,input);
    for(string &str : TokenizationUtils::GetSeparateTokens_SS(input,','))
        inputs.push_back(stoi(str));

    cout << Concatenate(inputs) << endl;
    return 0;
}

string Concatenate(vector<int> numbers)
{
    vector<string> numberStr;
    string concatenatedStr;

    //sort(numbers.begin(),numbers.end(), CompareDecimals);

    for (int const &number: numbers)
        numberStr.push_back(to_string(number));

    sort(numberStr.begin(),numberStr.end(), CompareStrings);

    for(string const &number: numberStr)
        concatenatedStr += number;

    return concatenatedStr;
}

bool CompareStrings(string &a, string &b)
{
    string ab = a+b;
    string ba = b+a;
    return ab > ba;
}

bool CompareDecimals(int a ,int b)
{
    int modA = a % 10;
    int modB = b % 10;

    if(modA != a && modB != b)
        return a > b;
    else
        return modA > modB;
}
