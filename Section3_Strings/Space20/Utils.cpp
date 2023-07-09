//
// Created by layca on 3/5/2022.
//

#include "Utils.h"
#include <iostream>
#include <vector>

std::vector<int> Utils::SearchAllOccurrences(std::string bigString, std::string smallString)
{
    std::vector<int> occurrences;
    int stringIndex;
    stringIndex = bigString.find(smallString);

    while(stringIndex != -1)
    {
        occurrences.emplace_back(stringIndex);
        stringIndex = bigString.find(smallString,stringIndex + 1);
    }

    return occurrences;
}

std::vector<int> Utils::SearchAllOccurrences(std::string bigString, char character)
{
    std::vector<int> output;

    for(int i = 0; bigString[i] != '\0'; i++)
        if(bigString[i] == character)
            output.emplace_back(i);

    return output;
}

std::string Utils::Space20(std::string source, std::string word,char character)
{
    std::string output;
    output.resize(source.size());
    std::vector<int> occurrences = SearchAllOccurrences(source,character);
    int occEnd = occurrences.size() - 1;
    int occCounter = occurrences.size() * (word.size() - 1);

    for(int i = source.find('\0') - 1; i >= 0; i--)
    {
        if(occEnd >= 0 && i == occurrences[occEnd])
        {
            for(int j = 0; j < word.size(); j++)
            {
                int rest = (word.size()-1) - j;
                output[i + occCounter - rest] = word[j];
            }
            occCounter -= word.size() - 1;
            occEnd--;
        }
        else
            output[occCounter + i] = source[i];
    }

    return output;
}

void Utils::PrintVector(const std::vector<int> &arr)
{
    std::cout << "[ ";

    for(auto element : arr)
        std::cout << element << " ";

    std:: cout << "] " << std::endl;
}