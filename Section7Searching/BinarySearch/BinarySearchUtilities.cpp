//
// Created by layca on 7/15/2023.
//

#include "BinarySearchUtilities.h"
#include <cmath>
#include <algorithm>
#include <iostream>

int BinarySearchUtilities::BinarySearch(std::vector<int> &array, int element)
{
    int start = 0, end = array.size() - 1;
    while(start <= end)
    {
        int mid = (start + end) /2;

        if(array[mid] == element)
            return mid;
        else if (array[mid] > element)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int BinarySearchUtilities::FrequencyCount(std::vector<int> &array, int element)
{
    int index = BinarySearch(array,element);
    if (index == -1) return -1;

    int lowCo = LowerConcurrency(array, index, element);
    int highCo = HigherConcurrency(array,index, element);

    return (highCo - lowCo) + 1;
}

int BinarySearchUtilities::LowerConcurrency(std::vector<int> &array,int index, int element)
{
    int start = 0;
    int end = index - 1;
    while(start <= end)
    {
        int mid = (start + end) / 2;
        if(array[mid] == element)
        {
            index = mid;
            end = mid - 1;
        }
        else if (array[mid] > element)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return index;
}

int BinarySearchUtilities::HigherConcurrency(std::vector<int> &array,int index, int element)
{
    int end = array.size() - 1;
    int start = index + 1;
    while(start <= end)
    {
        int mid = (start + end) / 2;
        if(array[mid] == element)
        {
            index = mid;
            start = mid + 1;
        }
        else if (array[mid] > element)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return index;
}

int BinarySearchUtilities::RotatedSearch(std::vector<int> &array, int element)
{
    int start = 0;
    int end = array.size() - 1;
    while(start <= end)
    {
        int mid = (start + end) / 2;
        if(array[mid] == element)
            return mid;

        if (array[start] <= array[mid]) //left line
        {
           if(element <= array[mid] and element >= array[start]) // element is in left side
               end = mid - 1;
           else
               start = mid + 1;
        }
        else // right line
        {
            if(element <= array[end] and element >= array[mid]) // element is in right side
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}

float BinarySearchUtilities::SquareRoot(int number, int places)
{
    float answer = 0;
    float tmpAnswer = 0;

    int start = 0;
    int end = number;
    while(start <= end)
    {
        int mid = ((end - start) / 2) + start;
        if(pow(mid,2) <= number)
        {
            answer = (float)mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    for(int i = 0; i < places; i++)
    {
        for(int j = 0; j <= 9 <= number; j++)
        {
            tmpAnswer = answer + float(0.1f/pow(10,i));
            if(pow(tmpAnswer,2) <= number)
                answer = tmpAnswer;
            else
                break;
        }
    }
    return answer;
}

int BinarySearchUtilities::MaxDistanceBetween(const std::vector<int>& places, int elements)
{
    int answer = 0;
    int maxDistance = places[places.size() - 1] - places[0];
    int minDistance = places[0];
    while(minDistance <= maxDistance)
    {
        int mid = (maxDistance - minDistance) / 2 + minDistance;
        if(ValidateDistance(places,elements,mid)) //go right
        {
            answer = mid;
            minDistance = mid + 1;
        }
        else //go left
            maxDistance = mid - 1;
    }

    return answer;
}

bool BinarySearchUtilities::ValidateDistance(const std::vector<int> &places, int elements, int distance)
{
    //set first element
    int currentPosition = *places.begin();
    elements--;

    //set all other elements each distance
    for(int place: places)
    {
        if((place - currentPosition) >= distance)
        {
            currentPosition = place;
            elements--;
        }
    }

    return elements <= 0;
}

std::pair<int, int> BinarySearchUtilities::GetMinPair(std::vector<int> &arr_1,std::vector<int> &arr_2)
{
    std::sort(arr_1.begin(),arr_1.end());
    std::pair<int,int> answer = { 0,0};
    std::pair<bool,int> tempBound;
    std::pair<int,int> tempAnswer;
    bool solved = false;

    for(int element : arr_2)
    {
        tempBound = GetLowerBound(arr_1, element);
        if(tempBound.first)
        {
            tempAnswer = std::make_pair(tempBound.second,element);
            if(!solved || GetRest(answer) >= GetRest(tempAnswer))
            {
                answer = tempAnswer;
                solved = true;
            }
        }

        tempBound = GetHigherBound(arr_1,element);
        if(tempBound.first)
        {
            tempAnswer = std::make_pair(tempBound.second,element);
            if(!solved || GetRest(answer) >= GetRest(tempAnswer))
            {
                answer = tempAnswer;
                solved = true;
            }
        }
    }
    return answer;
}

std::pair<bool,int> BinarySearchUtilities::GetLowerBound(std::vector<int> &array, int element)
{
    int start = 0;
    int end = array.size() - 1;
    int answer = 0;
    bool solved = false;

    while(start <= end)
    {
        int mid = (end - start)/ 2 + start;
        if(array[mid] <= element) //right
        {
            start = mid + 1;
            answer = array[mid];
            solved = true;
        }
        else //left
        {
            end = mid - 1;
        }
    }

    return std::make_pair(solved,answer);
}

std::pair<bool,int> BinarySearchUtilities::GetHigherBound(std::vector<int> &array, int element)
{
    int start = 0;
    int end = array.size() - 1;
    int answer = 0;
    bool solved = false;

    while(start <= end)
    {
        int mid = (end - start) / 2 + start;
        if(array[mid] >= element) // left
        {
            end = mid - 1;
            answer = array[mid];
            solved = true;
        }
        else //right
        {
            start = mid + 1;
        }
    }

    return std::make_pair(solved,answer);
}

int BinarySearchUtilities::GetRest(std::pair<int, int> pair)
{
   return abs(pair.first - pair.second);
}



bool BinarySearchUtilities::ValidateCoins(const std::vector<int> &coins, int subCoins, int friends)
{
    int counter = 0;
    int sum = 0;

    for(int coin : coins)
    {
        sum += coin;
        if(sum >= subCoins)
        {
            counter++;
            sum = 0;
        }
    }

    return counter >= friends;
}

int BinarySearchUtilities::GetCoins(std::vector<int> &coins, int friends)
{

    int min = INT_MAX;
    int max = 0;

    std::for_each(coins.begin(),coins.end(),[&](int coin) -> void {
         if(coin < min)
             min = coin;

         max += coin;
    });

    int start = min;
    int end = max;
    int mid = 0;
    int answer = 0;

    while(start <= end)
    {
        mid = (end - start) / 2 + start;
        if(ValidateCoins(coins,mid,friends))
        {
            answer = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return answer;
}

int BinarySearchUtilities::GetMinPages(std::vector<int> &books, int students)
{
    auto booksCopy = books;
    std::sort(booksCopy.begin(), booksCopy.end());

    int minPages = booksCopy[0];
    int maxPages = 0;
    int counter = 0;
    int middle = 0;
    std::pair<bool, int> checkResult = std::make_pair(false, 0);
    int result;
    std::for_each(booksCopy.begin(), booksCopy.end(), [&](int element){
        counter++;
        if(counter >= students - 1)
            maxPages += element;
    });

    while(minPages <= maxPages)
    {
        middle = ((maxPages - minPages) / 2) + minPages;
        checkResult = CheckDistributionOfPages(books, middle, students);
        if(checkResult.first)
        {
            minPages = middle + 1;
            result = checkResult.second;
        }
        else
            maxPages = middle - 1;
    }

    return result;
}

std::pair<bool, int> BinarySearchUtilities::CheckDistributionOfPages(std::vector<int> &books, int pages, int students)
{
    int biggest = 0;
    int counter = 0;
    int tempAmount = 0;
    std::vector<int> subSets;
    for(int bookPages : books)
    {
       if(tempAmount + bookPages > pages  && tempAmount != 0)
       {
           counter++;
           if(tempAmount > biggest)
               biggest = tempAmount;
           tempAmount = bookPages;
           continue;
       }
       else if(tempAmount + bookPages >= pages)
       {
           tempAmount += bookPages;
           counter++;
           if(tempAmount > biggest)
               biggest = tempAmount;
           tempAmount = 0;
       }
       else
            tempAmount+=bookPages;
    }
    if(tempAmount != 0 && counter < students && tempAmount <= pages && biggest == pages)
        counter++;

    return std::make_pair((counter == students), biggest);
}


