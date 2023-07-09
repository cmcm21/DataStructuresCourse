#ifndef SECTION2_UTILS_H
#define SECTION2_UTILS_H
#include <vector>
#include <string>


class Utils
{
    public:
        static std::vector<std::string> fizzbuzz(int n);
        static std::vector<int> Pair(const std::vector<int>& arr, int sum);
        static std::vector<int> PairWithPointers(const std::vector<int> &arr, int sum);
        static std::vector<std::vector<int>> Triplets(const std::vector<int> &arr,int sum);
        static std::vector<int> LongestBand(const std::vector<int> &arr);
        static int RainTrapped(const std::vector<int> &arr);
        static std::vector<int> SubarraySorted(const std::vector<int> &arr);
        static int MinSwaps(const std::vector<int> &arr);
        static std::pair<int,int> MinimumDifference(std::vector<int> &a, std::vector<int> &b);
        static std::vector<int> ArrayProduct(const std::vector<int> &arr);
        static int BusyLife(const std::vector<std::pair<int,int>> &activities);
        static int MaxSumInSubArray(const std::vector<int> &arr);
        static void PrintArray(const std::vector<int>& arr);
};


#endif
