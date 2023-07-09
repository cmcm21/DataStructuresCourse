//
// Created by layca on 11/19/2022.
//

#include "CheckSubsetApp.h"
#include <iostream>

void CheckSubsetApp::Run(bool performance)
{
    GetInput();
    if(!performance)
        Resolve();
    else
       ResolvePerformance();
    std::cout << (isSubset ? "Yes":"No") << std::endl;
}

void CheckSubsetApp::GetInput()
{
    std::getline(std::cin,source);
    std::getline(std::cin, target);
}

void CheckSubsetApp::Resolve()
{
    isSubset = true;
    std::map<char,int> charCurrency = GetSourceMap();

    for(char &character: target)
    {
        if(charCurrency.find(character) != charCurrency.end())
        {
            if(charCurrency[character] > 0)
                charCurrency[character]--;
            else
                isSubset = false;
        }
        else
            isSubset = false;
    }
}

std::map<char, int> CheckSubsetApp::GetSourceMap()
{
    std::map<char,int> charactersCurrency;
    for(char &character: source)
    {
        if(charactersCurrency.find(character) == charactersCurrency.end())
            charactersCurrency[character] = 1;
        else
            charactersCurrency[character]++;
    }
    return charactersCurrency;
}

void CheckSubsetApp::ResolvePerformance()
{
    int i = (int)source.length() - 1;
    int j = (int)target.length() - 1;

    for(;i >= 0 && j >= 0;)
    {
        if(target[j] == source[i])
        {
            i--;
            j--;
        }
        else
            i--;
    }

    isSubset = j < 0;
}

