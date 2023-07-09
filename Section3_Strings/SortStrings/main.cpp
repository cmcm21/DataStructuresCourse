#include "../Tokenization/TokenizationUtils.h"
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>


using namespace std;

vector<string> GetSortedStrings(vector<string> &inputs,int columnKey, bool reverse,bool numeric);
string ExtractKeyAt(string input, int key);
bool NumericCompare(pair<string,string> &pair1, pair<string,string> &pair2);
bool LexicoCompare(pair<string,string> &pair1, pair<string,string> &pair2);

class Comparator{
public:
    explicit Comparator(bool numeric):numeric(numeric){}
    bool numeric;
    bool operator()(pair<string,string> &pair1, pair<string,string> &pair2) const
    {
        if(numeric)
            return stoi(pair1.second) < stoi(pair2.second);
        else
            return pair1.second < pair2.second;
    }
};

int main()
{
    int n,column;
    vector<string> input, sortedStrings;
    string temp;
    bool reverse,numeric;

    cin >> n;
    cin.get(); // consume the extra \n

    for(int i = 0; i < n ; i++) {
        getline(cin,temp);
        input.push_back(temp);
    }

    cin >> column >> reverse >> numeric;

    sortedStrings = GetSortedStrings(input,column,reverse,numeric);

    for(const string& str: sortedStrings)
        cout << str << endl;
}

vector<string> GetSortedStrings(vector<string>& inputs,int columnKey, bool reverse,bool numeric)
{
    vector<pair<string,string>> stringXKey;
    vector<string> stringOrdered;

    stringXKey.reserve(inputs.size());
    for(int i = 0; i < inputs.size(); i++)
        stringXKey.emplace_back(inputs[i], ExtractKeyAt(inputs[i],columnKey));

    /*
    Comparator comparator(numeric);
    std::sort(stringXKey.begin(),stringXKey.end(),comparator);
    */
    if(numeric)
        std::sort(stringXKey.begin(),stringXKey.end(), NumericCompare);
    else
        std::sort(stringXKey.begin(),stringXKey.end(), LexicoCompare);

    stringOrdered.reserve(stringXKey.size());
    for(const auto& string_x_key : stringXKey)
        stringOrdered.push_back(string_x_key.first);

    if(reverse)
        std::reverse(stringOrdered.begin(),stringOrdered.end());

    return stringOrdered;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "performance-unnecessary-value-param"
string ExtractKeyAt(string input, int key)
{
    char *keyString = strtok((char *)input.c_str()," ");

    while(key > 1) {
        keyString = strtok(nullptr," ");
        key--;
    }

    return (string)keyString;
}
#pragma clang diagnostic pop

bool NumericCompare(pair<string,string> &pair1, pair<string,string> &pair2)
{
    return stoi(pair1.second) < stoi(pair2.second);
}

bool LexicoCompare(pair<string,string> &pair1, pair<string,string> &pair2)
{
    return pair1.second < pair2.second;
}
