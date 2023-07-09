#include <iostream>
#include "MountainAlgorithm.h"
#include "Utils.h"
using namespace std;

void TestFizzBuzz();
void TestPair();
void TestTriplets();
void TestMountainAlgorithm();
void TestBestBand();
void TestRainTrapped();
void TestSubarraySorted();
void TestMinSwap();
void TestMaxSumInSubArray();
void TestMinDifference();
void TestArrayProduct();
void TestBusyLife();

int main()
{
    TestBusyLife();
    return 0;
}

void TestFizzBuzz()
{
    auto result = Utils::fizzbuzz(15);
    for(const auto& element: result)
        cout << element << endl;
}

void TestPair()
{
    vector<int> arr = {10,5,2,3,11,-6,9};
    int sum = 4;
    cout << "Sum : " << sum << " Array" << endl;
    Utils::PrintArray(arr);

    auto result = Utils::PairWithPointers(arr,sum);
    cout << "Result" << endl;
    Utils::PrintArray(result);
}

void TestTriplets()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,15};
    int sum = 18;
    cout << "sum : " << sum << " Array "  << endl;
    Utils::PrintArray(arr);

    auto result = Utils::Triplets(arr,sum);
    cout << "Result:  " << endl;
    for(auto &vector: result)
    {
        cout << "[ ";
        for(auto &element: vector)
            cout << element << " ";
        cout << "]" << endl;
    }
}

void TestMountainAlgorithm()
{
    vector<int> intput = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,3,3,3,3,3,3,-2,-4,4};
    int result = MountainAlgorithm::Resolve(intput);

    cout << "Array : " ;
    Utils::PrintArray(intput);
    cout << "Max Mountain sum: " << result;
}

void TestBestBand()
{
    vector<int> input = {1,9,3,0,18,5,2,4,10,7,12,6};
    auto result = Utils::LongestBand(input);

    cout<< "Input: ";
    Utils::PrintArray(input);
    cout << "Result: ";
    Utils::PrintArray(result);
}

void TestRainTrapped()
{
    vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
    Utils::PrintArray(input);
    cout << "water Trapped " << Utils::RainTrapped(input) << endl;
}

void TestSubarraySorted()
{
    vector<int> input = {1,2,3,4,5,8,6,7,9,10,11};
    Utils::PrintArray(input);
    auto result = Utils::SubarraySorted(input);
    cout << "Unsorted segment indexes : ";
    Utils::PrintArray(result);
}

void TestMinSwap()
{
    vector<int> input = {10,11,5,4,3,2,1};
    Utils::PrintArray(input);
    cout << "Min Swaps: " << Utils::MinSwaps(input) << endl;
}
void TestMaxSumInSubArray()
{
    vector<int> input = {0,1,-3,-2,10,1,-3,10,5,-4};
    Utils::PrintArray(input);
    int result = Utils::MaxSumInSubArray(input);
    cout << "Result: " << result << endl;
}

void TestMinDifference()
{
    vector<int> input1 = {23,5,10,17,30};
    vector<int> input2 = {26,134,135,14,19};
    auto result = Utils::MinimumDifference(input1,input2);
    cout << "Result: ( " << result.first << ", " << result.second << " )" << endl;
}

void TestArrayProduct()
{
    vector<int> input = {1,2,3,4,5};
    auto result = Utils::ArrayProduct(input);
    Utils::PrintArray(input);
    cout << "Result : " << endl;
    Utils::PrintArray(result);
}
void TestBusyLife()
{
   vector<pair<int,int>> activities = {{7,9},{0,10},{4,5},{8,9},{4,10},{5,7}};
   auto result = Utils::BusyLife(activities);
   cout << "Result: " << result << endl;
}
