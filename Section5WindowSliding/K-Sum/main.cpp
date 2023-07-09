#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>

std::vector<std::pair<int,int>> Housing(std::vector<int> allNumbers, int totalSum);
//this one doesn't work with negative numbers
std::vector<std::pair<int,int>> HousingFaster(std::vector<int> allNumbers, int totalSum);
bool CompareSegmentsPairs(std::pair<int,int> pair1, std::pair<int,int> pair2);

int main()
{
    std::vector<int> input;
    std::string rawInput;
    int totalSum;

    std::getline(std::cin,rawInput);
    if(!rawInput.empty())
    {
        int number;
        std::stringstream ss(rawInput);
        while(ss >> number)
            input.push_back(number);
    }
    std::cin >> totalSum;

    auto result = Housing(input,totalSum);
    auto minElement = std::min_element(result.begin(),result.end(), CompareSegmentsPairs);

    std::cout << "Min range: " << minElement->first << ", " << minElement->second << std::endl;

    for(auto indicesPair : result)
        std::cout << indicesPair.first << "," << indicesPair.second << std::endl;

    result = HousingFaster(input,totalSum);
    minElement = std::min_element(result.begin(),result.end(), CompareSegmentsPairs);

    std::cout << "Min range: " << minElement->first << ", " << minElement->second << std::endl;
    for(auto indicesPair : result)
        std::cout << indicesPair.first << "," << indicesPair.second << std::endl;

    return 0;
}

std::vector<std::pair<int,int>> Housing(std::vector<int> allNumbers, int totalSum)
{
    std::vector<std::pair<int,int>> indices;
    for(int i = 0; i < allNumbers.size(); i++)
    {
        int counter = allNumbers[i];
        bool finished = false;
        for(int j = i+1; j < allNumbers.size() && !finished; j++)
        {
             counter += allNumbers[j];
             if(counter == totalSum)
             {
                 indices.emplace_back(std::make_pair(i,j));
                 finished = true;
             }
             else if(counter > totalSum)
                 finished = true;
        }
    }
   return indices;
}

std::vector<std::pair<int,int>> HousingFaster(std::vector<int> allNumbers, int totalSum)
{
    std::vector<std::pair<int,int>> pairs;
    int i = 0;
    int j = 0;
    int counter = 0;

    while(j < allNumbers.size())
    {
        //expand to the right
        counter += allNumbers[j];
        j++;

        //remove elements from the left while counter > totalSum and i < j
        while (counter > totalSum and i < j) {
            counter -= abs(allNumbers[i]);
            i++;
        }

        if(counter == totalSum)
            pairs.emplace_back(std::make_pair(i,j-1));
    }
    return pairs;
}

bool CompareSegmentsPairs(std::pair<int,int> pair1, std::pair<int,int> pair2)
{
    int first = pair1.second - pair1.first;
    int second = pair2.second  - pair2.first;
    return first < second;
}
