#include <iostream>
#include "BinarySearch/BinarySearchUtilities.h"

using namespace std;

void TestFrequencyCounter();
void TestRotatedSearch();
void TestSquareRoot();
void TestAngryBirds();
void TestMinPair();

int main()
{
    TestMinPair();
    return 0;
}

void TestFrequencyCounter()
{
    vector<int> input = {0,1,1,1,1,2,2,2,3,4,4,5,10};
    cout << BinarySearchUtilities::FrequencyCount(input,2) << endl;
}

void TestRotatedSearch()
{
    vector<int> input {4,5,6,7,0,1,2,3};
    int key;
    cin >> key;
    cout << BinarySearchUtilities::RotatedSearch(input,key) << endl;
}

void TestSquareRoot()
{
    int number = 0, places = 0;
    cin >> number >> places;

    cout << BinarySearchUtilities::SquareRoot(number,places) << endl;
}
void TestAngryBirds()
{
    vector<int> input = {1,2,4,8,9};
    int birds = 3;

    cout << BinarySearchUtilities::MaxDistanceBetween(input,birds) << endl;
}

void TestMinPair()
{
    vector<int> input1 = {-1,5,10,20,3};
    vector<int> input2 = {26,134,135,15,17};

    auto answer = BinarySearchUtilities::GetMinPair(input1,input2);
    printf("[ %d, %d ]",answer.first,answer.second);
}
