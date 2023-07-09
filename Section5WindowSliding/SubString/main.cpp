/**
 * this program solve the problem of get the largest substring of a string, and this
 * substring needs to have all its elements different from each other
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

class MyUnorderedSet{
private:
    string setString;
    unordered_set<char> unorderedSet;
public :
    void Insert(char character)
    {
        unorderedSet.insert(character);
        setString += character;
    }

    bool Find(char character) { return unorderedSet.find(character) != unorderedSet.end(); }
    string GetString() { return setString;}
    size_t GetSize() { return unorderedSet.size(); }
    bool Empty() { return unorderedSet.empty();}

    void Clear()
    {
        setString.clear();
        unorderedSet.clear();
    }
};


string GetMaxDiffSubstring(string someString);
void PrintSet(vector<MyUnorderedSet> strings);

int main()
{
    string input;
    getline(cin, input);

    cout << GetMaxDiffSubstring(input) << endl;
    return 0;
}

string GetMaxDiffSubstring(string someString)
{
    vector<MyUnorderedSet> subStrings;
    MyUnorderedSet subString;

    for(int i = 0; i < someString.size(); i++)
    {
        char character = someString[i];
        subString.Insert(character);

        for(int j = i + 1; j < someString.size() && !subString.Find(someString[j]); j++)
        {
            character = someString[j];
            subString.Insert(character);
        }

        subStrings.emplace_back(subString);
        subString.Clear();
   }

    if(!subString.Empty())
        subStrings.emplace_back(subString);

    auto larger_string = max_element(subStrings.begin(), subStrings.end(),
             [](MyUnorderedSet set1,MyUnorderedSet set2 ) {return set1.GetSize() < set2.GetSize(); });

    return larger_string->GetString();
}

void PrintSet(vector<MyUnorderedSet> strings)
{
    for_each(strings.begin(),strings.end(),[](MyUnorderedSet set) {cout << set.GetString() << endl; });
}
