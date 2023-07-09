#include <iostream>
#include "Utils.h"

using namespace std;

void TestSearchOcc();
void TestSpace20();

int main()
{
    TestSpace20();
    return 0;
}

void TestSearchOcc()
{
    string bigString = "I liked the movie, acting in movie was great!";
    string smallString = "movie";
    auto result = Utils::SearchAllOccurrences(bigString,smallString);

    cout << "Big string: " << bigString << endl;
    cout << "Small string: " << smallString  << endl;
    cout << "Result :"<<  endl;

    Utils::PrintVector(result);
}

void TestSpace20()
{
    string input = "hello word,  how are you";
    string word = "%20";
    input.resize(50);
    auto result = Utils::Space20(input,word,' ');
    cout << "Input : " << input << endl;
    cout << "Word: " << word << endl;
    cout << "Result: " << result << endl;
}
