#include<vector>
//
// Created by layca on 7/15/2023.
//

#ifndef SECTION7SEARCHING_BINARYSEARCH_H
#define SECTION7SEARCHING_BINARYSEARCH_H


class BinarySearchUtilities
{
private:
    static int LowerConcurrency(std::vector<int> &array,int index,int element);
    static int HigherConcurrency(std::vector<int> &array,int index,int element);
    static bool ValidateDistance(const std::vector<int> &places,int elements, int distance);
    static bool ValidateCoins(const std::vector<int> &coins, int subCoins,int friends);
    static std::pair<bool,int> GetLowerBound(std::vector<int> &array, int element);
    static std::pair<bool,int> GetHigherBound(std::vector<int> &array, int element);
    static int GetRest(std::pair<int,int> pair);
public:
    static int BinarySearch(std::vector<int> &array, int element);
    static int FrequencyCount(std::vector<int> &array, int element);
    static int RotatedSearch(std::vector<int> &array, int element);
    static float SquareRoot(int number, int places);
    static int MaxDistanceBetween(const std::vector<int>& places, int elements);
    static std::pair<int,int> GetMinPair(std::vector<int> &arr_1, std::vector<int> &arr_2);
    static int GetCoins(std::vector<int> &coins, int friends);
};


#endif //SECTION7SEARCHING_BINARYSEARCH_H
