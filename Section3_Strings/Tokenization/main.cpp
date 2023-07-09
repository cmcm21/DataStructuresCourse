#include <iostream>
#include <cstring>
#include "TokenizationUtils.h"

using namespace std;

int main()
{
    string input;
    getline(cin,input);

    vector<string> tokens;
    tokens = TokenizationUtils::GetSeparateTokens_SS(input, ' ');

    cout << "Stream String" << endl;
    for(string token: tokens)
        cout << token << ",";

    vector<char *> tokens_strtok;
    tokens_strtok = TokenizationUtils::GetSeparateTokens( const_cast<char *>(input.c_str()), ' ' );

    cout << endl;
    cout << "Strtok function" << endl;
    for(auto token : tokens_strtok)
        cout << token << ",";
}
