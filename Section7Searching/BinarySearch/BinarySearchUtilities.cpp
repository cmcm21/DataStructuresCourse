//
// Created by layca on 7/15/2023.
//

#include "BinarySearchUtilities.h"
#include <cmath>

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
        if(ValidateDistance(places,elements,mid))
        {
            answer = mid;
            minDistance = mid + 1;
        }
        else
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
