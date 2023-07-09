#include <iostream>
#include <string>
#include <unordered_map>

std::string GetSmallestSubstring(std::string string, const std::string& pattern);
void FillPatternFrequency(const std::string& pattern,std::unordered_map<char,int> &patternFrequency);

int main()
{
    std::string string;
    std::string pattern;

    std::getline(std::cin,string);
    std::getline(std::cin,pattern);

    std::cout << GetSmallestSubstring(string,pattern) << std::endl;
    return 0;
}

std::string GetSmallestSubstring(std::string string, const std::string& pattern)
{
    int start = 0, j = 0;
    int subStringLen = 0;
    int counter = 0;
    char ch;

    std::unordered_map<char,int> patternFrequency;
    std::unordered_map<char,int> window;
    FillPatternFrequency(pattern,patternFrequency);

    while(j < string.length())
    {
        if(counter < pattern.length())
        {
            ch = string[j];
            window[ch] = window.count(ch) ? window[ch] + 1 : 1;
            if(patternFrequency.count(ch) && window[ch] <= patternFrequency[ch])
                counter++;

            if(counter != pattern.length())
                j++;
        }
        else
        {
            ch = string[start];
            window[ch]--;
            if(!patternFrequency.count(ch) || window[ch] >= patternFrequency[ch])
                start++;
            else
                break;
        }
    }

    subStringLen = j - start + 1;
    return string.substr(start, subStringLen);
}

void FillPatternFrequency(const std::string& pattern,std::unordered_map<char,int> &patternFrequency)
{
    for(char character: pattern)
    {
        if(patternFrequency.count(character))
            patternFrequency[character]++;
        else
            patternFrequency[character] = 1;
    }
}
