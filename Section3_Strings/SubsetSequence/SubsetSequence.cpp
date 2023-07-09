#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void GetSubsetSequence(std::string &input,int ptr,std::string subOutput,std::vector<std::string> &output);
bool CompareStrings(std::string str1, std::string str2);

int main()
{
    std::string input;
    std::vector<std::string> output;
    std::getline(std::cin,input);

    GetSubsetSequence(input,0,"",output);
    std::sort(output.begin(),output.end(), CompareStrings);

    for(std::string &subOutput: output)
        std::cout << subOutput << ", ";
    std::cout << std::endl;
    return 0;
}

void GetSubsetSequence(std::string &input,int ptr,std::string subOutput,std::vector<std::string> &output)
{
    if(input[ptr] == '\0')
    {
        output.push_back(subOutput);
        return;
    }

    GetSubsetSequence(input,ptr + 1,subOutput + input[ptr] ,output);
    GetSubsetSequence(input,ptr + 1, subOutput,output);
}

bool CompareStrings(std::string str1, std::string str2)
{
    if(str1.length() == str2.length())
        return str1 < str2;
    return str1.length() < str2.length();
}
