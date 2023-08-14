#include <algorithm>
#include "../BinarySearch/BinarySearchUtilities.h"
#include <unordered_set>
#include <iostream>


using namespace std;

int GetCoins(vector<int> coinsArr,int friends);

int main()
{
    cout  << GetCoins(vector<int>{1,2,3,4,5},3) << endl;
}

int GetCoins(vector<int> coinsArr,int friends)
{
    unordered_set<int> usedCoins;

    sort(coinsArr.begin(),coinsArr.end());

    int totalSum = 0;
    for_each(coinsArr.begin(),coinsArr.end(), [&](int coins) -> void {
        totalSum += coins;
    });

    int div = totalSum / friends;
    int minSubArray = 0;
    int tempSum = 0, termSearched = 0, searchedIndex = 0;

    for(int i = coinsArr.size() - 1; i >= 0; i--)
    {
        if(usedCoins.find(coinsArr[i]) != usedCoins.end()) continue;

        tempSum = coinsArr[i];
        usedCoins.emplace(tempSum);
        termSearched = div - tempSum;
        if(termSearched > 0)
        {
            searchedIndex = BinarySearchUtilities::BinarySearch(coinsArr,termSearched);

            while(i < coinsArr.size() && (searchedIndex == -1 || usedCoins.find(coinsArr[searchedIndex]) != usedCoins.end()))
            {
                tempSum += coinsArr[--i];
                termSearched = div - tempSum;
                usedCoins.emplace(coinsArr[i]);
                searchedIndex = BinarySearchUtilities::BinarySearch(coinsArr,termSearched);
            }

            if(searchedIndex != -1)
                tempSum += coinsArr[searchedIndex];

            usedCoins.emplace(coinsArr[searchedIndex]);
        }

        if(tempSum <= minSubArray || minSubArray == 0)
            minSubArray = tempSum;

    }

    return minSubArray;
}
