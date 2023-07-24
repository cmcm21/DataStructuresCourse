#include <iostream>
#include "BinarySearch/BinarySearchUtilities.h"

using namespace std;

void TestFrequencyCounter();
void TestRotatedSearch();
void TestSquareRoot();
void TestAngryBirds();

int main()
{
    TestAngryBirds();
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

