//
// Created by layca on 7/15/2023.
//

#include "BinarySearchUtilities.h"

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