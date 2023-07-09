#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

string SmallestWindow(string str);
vector<int> MaxInWindow(vector<int> input, int windowRange);
int CountSubArrays(vector<int> arr,int k);

int main()
{
    vector<int> input;
    vector<int> result;
    int sum,temp;
    string string;

    cin >> sum;

    while(cin >> temp)
        input.emplace_back(temp);


    cout << CountSubArrays(input,sum) << endl;
    return 0;
}

string SmallestWindow(string str)
{
    int idxStart = 0 , idxEnd= 0;
    unordered_set<char> distinctCh;
    string smallestWindow;
    int distinctCharacters = 0;

    for(char const &character : str)
        if(distinctCh.find(character) == distinctCh.end())
            distinctCharacters++;


    while(idxEnd < str.length())
    {
        char currentCh = str[idxEnd];
        if(distinctCh.find(currentCh) != distinctCh.end()) // if character exists in set
        {
            int subStringLen =  (int)distinctCh.size();
            if(smallestWindow.empty() && subStringLen >= distinctCharacters
                || smallestWindow.length() > subStringLen && subStringLen >= distinctCharacters){
                smallestWindow = str.substr(idxStart,subStringLen);
            }
            idxStart++;
            idxEnd = idxStart + 1;
            distinctCh.clear();
            distinctCh.emplace(str[idxStart]);
        }
        else
        {
            distinctCh.emplace(currentCh);
            idxEnd++;
        }
    }
    return smallestWindow;
}

vector<int> MaxInWindow(vector<int> input, int windowRange)
{
    vector<int> maxWindows;
    int i = 0, j = 0;
    int max;

    for(;i < input.size() && j < input.size(); i++)
    {
        max = INT_MIN;
        for(j = i; j < i + windowRange && j < input.size(); j++)
            if(input[j] > max)
                max = input[j];

        maxWindows.emplace_back(max);
    }
    return maxWindows;
}


int CountSubArrays(vector<int> arr,int k)
{
    int counter = 0, sum  = 0, start = 0 , j = 0,rest;
    unordered_set<int> inputSet;
    vector<vector<int>> sets;
    vector<int> tempSet;
    for_each(arr.begin(),arr.end(),[&inputSet](int &element)mutable{
        if(inputSet.find(element) == inputSet.end())
            inputSet.insert(element);
    });

    for(; start < arr.size() ; start++)
    {
        sum = 0;
        rest = k - arr[start];
        tempSet.clear();
        tempSet.emplace_back(arr[start]);

        if(inputSet.find(rest) != inputSet.end())
        {
            counter++;
            sets.emplace_back(tempSet);
        }
        else
        {
            for(int k = start; k < arr.size(); k++)
            {
                sum += rest;
                rest = k - rest;
                if(inputSet.find(rest) != inputSet.end())
                {
                    counter++;
                    break;
                }
            }
        }
        sum = 0;

        for(j = start; j < arr.size(); j++)
        {
            sum += arr[j];
            if(sum == k)
            {
                counter++;
                break;
            }
        }
}
    return counter;
}