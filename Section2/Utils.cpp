#include "Utils.h"
#include <unordered_set>
#include <map>
#include <iostream>
#include <algorithm>


std::vector<std::string> Utils::fizzbuzz(int n)
{
    std::vector<std::string> result ;
    for(int i = 1; i <= n; i++)
    {
        if(i % 3 == 0 && i % 5 == 0)
            result.emplace_back("FizzBuzz");
        else if(i % 3 == 0)
            result.emplace_back("Fizz");
        else if(i % 5 == 0)
            result.emplace_back("Buzz");
        else
            result.emplace_back(std::to_string(i));
    }
    return result;
}

std::vector<int> Utils::Pair(const std::vector<int>& arr, int sum)
{
   std::vector<int> results;
   std::unordered_set<int> set;
   for(auto element : arr)
   {
      int pair = sum - element;
      if(set.find(pair) != set.end())
      {
         results.emplace_back(element);
         results.emplace_back(pair);
         return results;
      }
      set.emplace(element);
   }
   return {};
}

std::vector<std::vector<int>> Utils::Triplets(const std::vector<int> &arr, int target)
{
    std::vector<std::vector<int>> result;
    std::vector<int> temp;
    int first,start,end;
    for(int i = 0; i < arr.size() - 3; i++)
    {
        first = arr[i];
        start = i + 1;
        end = arr.size() - 1;
        int subTarget = target - first;
        while(start < end)
        {
            int sum = arr[start] + arr[end];
            if(sum == subTarget)
            {
                result.push_back( {arr[i], arr[start], arr[end]});
                start++;
                end--;
            }
            else if(sum > subTarget)
                end--;
            else if(sum < subTarget)
                start++;
        }
    }
    return result;
}

std::vector<int> Utils::PairWithPointers(const std::vector<int> &arr, int target)
{
    std::vector<int> result;
    auto start = arr.begin();
    auto end = arr.end();
    int sum;
    while(start != end)
    {
        sum = *start + *end;
        if(sum > target)
            end--;
        else if(sum < target)
            start++;
        else if(sum == target)
        {
            result.emplace_back(*start);
            result.emplace_back(*end);
            return result;
        }
    }
    return result;
}

void Utils::PrintArray(const std::vector<int>& arr)
{
    std::cout << "[";
    for(const auto& element: arr)
        std::cout << " " << element;
    std::cout << " ]" << std::endl;
}

std::vector<int> Utils::LongestBand(const std::vector<int> &arr)
{
    std::unordered_set<int> hashTable;
    std::vector<int> bestBand;
    for(auto &element: arr)
        hashTable.emplace(element);

    for(auto &element: hashTable)
    {
        if(hashTable.find(element - 1) == hashTable.end())
        {
            std::vector<int> band = {element};
            int nextNumber = element + 1;
            while(hashTable.find(nextNumber) != hashTable.end())
            {
                band.emplace_back(nextNumber);
                nextNumber++;
            }
            if(band.size() > bestBand.size())
                bestBand = band;
        }
    }
    return bestBand;
}

int Utils::RainTrapped(const std::vector<int> &arr)
{
    int elements = arr.size();
    if(elements <= 2) return 0;

    std::vector<int> leftHighs(elements,0);
    std::vector<int> rightHighs(elements,0);
    int maxHigh = 0;
    int rainAmount = 0;
    //fill left Highs
    for(int i = 0; i < elements; i++)
    {
        maxHigh = std::max(arr[i],maxHigh);
        leftHighs[i] = maxHigh;
    }
    maxHigh = 0;
    //fill right highs
    for(int i = elements - 1; i >= 0; i--)
    {
       maxHigh = std::max(arr[i],maxHigh);
       rightHighs[i] = maxHigh;
    }

    for(int i = 0; i < elements; i++)
        rainAmount += std::min(leftHighs[i], rightHighs[i]) - arr[i];

    return rainAmount;
}

std::vector<int> Utils::SubarraySorted(const std::vector<int> &arr)
{
    int arrSize = arr.size();
    std::vector<int> result;
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int start = 0 , end = arrSize - 1;

    for(int i = 1; i < arrSize - 1; i++)
        if(arr[i] < arr[i - 1] || arr[i] > arr[i + 1]) // if element is unsorted
        {
            smallest = std::min(arr[i],smallest);
            largest = std::max(arr[i],largest);
        }

    while(start < arrSize)
    {
      if(arr[start] > smallest)
      {
          result.emplace_back(start);
          break;
      }
      start++;
    }

    while(end >= 0)
    {
       if(arr[end] < largest)
       {
           result.emplace_back(end);
           break;
       }
       end--;
    }

    if(result.empty())
       return std::vector<int> {-1,1};
    else
        return result;
}

int Utils::MinSwaps(const std::vector<int> &arr)
{
    std::map<int,int> elementToIndex;
    std::vector<bool> visited(arr.size(),false);
    std::vector<int> sortedArr(arr);
    int swaps = 0;
    int cycles = 0;

    std::sort(sortedArr.begin(),sortedArr.end());

    //fill map
    for(int i = 0; i < sortedArr.size(); i++)
       elementToIndex.emplace(sortedArr[i],i);

    for(int i = 0; i < arr.size(); i++)
    {
        // element at incorrect position and is not in the ordered elements
        if(i != elementToIndex.at(arr[i]) && !visited[i])
        {
            cycles = 0;
            int element = arr[i];
            int correctPosition = i;
            while(!visited[correctPosition])
            {
                visited[correctPosition] = true;
                correctPosition = elementToIndex.at(element);
                element = arr[correctPosition];
                cycles++;
            }
            swaps += cycles - 1;
        }
    }

    return swaps;
}

int Utils::MaxSumInSubArray(const std::vector<int> &arr)
{
    int n = arr.size();
    int maxSum = 0;
    int currentSum = 0;
    bool inSubArray = false;

    for(int i = 0; i < n - 1; i++ )
    {
        if(!inSubArray)
        {
           if(arr[i] >= 0)
           {
              inSubArray = true;
              currentSum += arr[i];
           }
        }
        else
        {
            if(arr[i] < 0)
            {
                int absVal = arr[i] * -1;
                if( absVal > arr[i - 1] && absVal > arr[i + 1] || i + 1 == n - 1 && arr[i+1] <= 0)
                {
                    inSubArray = false;
                    if(currentSum > maxSum)
                        maxSum = currentSum;
                    currentSum = 0;
                }
                else
                    currentSum += arr[i];
            }
            else
                currentSum += arr[i];
        }
    }
    if(currentSum > maxSum)
        maxSum = currentSum;

    return maxSum;
}

std::pair<int, int> Utils::MinimumDifference(std::vector<int> &a, std::vector<int> &b)
{
    std::pair<int,int> minPair;
    int minDifference = INT_MAX;
    int currentMinDiff,j;

    for(int firstElement : a)
    {
        for(int secondElement : b)
        {
            currentMinDiff = std::abs(firstElement - secondElement);
            if(currentMinDiff < minDifference)
            {
                minDifference = currentMinDiff;
                minPair.first = firstElement;
                minPair.second = secondElement;
            }
       }
    }

    return minPair;
}

std::vector<int> Utils::ArrayProduct(const std::vector<int> &arr)
{
    int n = arr.size();
    std::vector<int> output(n,1);
    std::vector<int> backProduct(n, 1);
    std::vector<int> frontProduct(n,1);

    backProduct[0] = arr[0];

    for(int i = 0; i < n ; i++)
    {
        if(i + 1 == n) continue;
        for(int j = i + 1; j < n; j++)
            frontProduct[i] *= arr[j];
        if(i > 0)
            backProduct[i] = backProduct[i - 1] * arr[i];
    }

    output[0] = frontProduct[0];

    for(int i = 1; i < n; i++)
        output[i] = frontProduct[i] * backProduct[i - 1];

    return output;
}

int Utils::BusyLife(const std::vector<std::pair<int, int>> &activities)
{
    int maxActivities = 0;
    int currentActivitiesCounter = 0;
    int lastActivityTime = 0;
    std::vector<int> startTimes;
    std::map<int,int> activitiesMap;

    for(auto activity: activities)
    {
        startTimes.emplace_back(activity.first);
        activitiesMap.emplace(activity.first,activity.second);
        lastActivityTime = std::max(lastActivityTime,activity.second);
    }
    std::sort(startTimes.begin(),startTimes.end());

    for(auto startActivityTime: startTimes)
    {
        currentActivitiesCounter = 0;
        for(int nextActivity = startActivityTime; nextActivity < lastActivityTime;)
        {
            if(activitiesMap.find(nextActivity) != activitiesMap.end())
            {
                nextActivity = activitiesMap.at(nextActivity);
                currentActivitiesCounter++;
            }
            else
                nextActivity++;
        }
        if(currentActivitiesCounter > maxActivities)
           maxActivities = currentActivitiesCounter;
    }

    return maxActivities;
}

