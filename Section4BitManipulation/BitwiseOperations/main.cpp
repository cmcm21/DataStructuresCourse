#include <iostream>
#include <cmath>
#include <chrono>
#include <bitset>
#include <vector>

using namespace std::chrono;

int Negation(int a);
int LeftShift(int a, int b);
int RightShift(int a, int b);
bool IsEven(int a);
int GetNBit(int number, int nBit);
void TurnOnNBit(int &number, int nBit);
void TurnOffNBit(int &number, int nBit);
void UpdateNBit(int &number, int nBit, int newValue);
void ClearLastIBits(int &number, int lastBit);
void ReplaceBits(int &firstNumber, int &secondNumber, int startBit, int endBit);
void CleanBitsInRange(int &number, int startBit, int endBit);
int CountOnBits(int number);
int CountOnBitsHack(int number);
int FastExponentiation(int number, int exponent);
int FromDecimalToBinary(int number);

int main()
{
    int number;

    std::cin >> number;
    std::cout << FromDecimalToBinary(number) << std::endl;

    return 0;
}

int Negation(int a) {
    return ~a;
}

int LeftShift(int a, int b) {
    return a << b;
}

int RightShift(int a, int b) {
    return a >> b;
}

bool IsEven(int a) {
    return !(a & 1);
}

int GetNBit(int number, int nBit) {
    int mask = 1 << (nBit - 1);
    return (number & mask) > 0 ? 1 : 0;
}

void TurnOnNBit(int &number, int nBit) {
    int mask = 1 << (nBit - 1);
    number |= mask;
}

void TurnOffNBit(int &number, int nBit) {
    int mask = ~(1 << (nBit - 1));
    number &= mask;
}

void UpdateNBit(int &number, int nBit, int newValue) {
    TurnOffNBit(number, nBit);
    int mask = newValue << (nBit - 1);
    number |= mask;
}

void ClearLastIBits(int &number, int lastBit)
{
    int mask = ~0;
    mask <<= (lastBit - 1);

    number &= mask;
}

void ReplaceBits(int &firstNumber, int &secondNumber, int startBit, int endBit)
{
    std::cout << std::bitset<32>(firstNumber) << std::endl;
    CleanBitsInRange(firstNumber, startBit, endBit);

    std::cout << std::bitset<32>(secondNumber) << std::endl;
    secondNumber <<= startBit;
    std::cout << std::bitset<32>(secondNumber) << std::endl;

    firstNumber |= secondNumber;
}

void CleanBitsInRange(int &number, int startBit, int endBit)
{
    int mask1 = ~0 << (endBit + 1);
    int mask2 = ~0 << startBit;
    mask2 = ~mask2;

    std::cout << std::bitset<32>(mask1) << std::endl;
    std::cout << std::bitset<32>(mask2) << std::endl;

    mask1 |= mask2;

    std::cout << std::bitset<32>(mask1) << std::endl;
    number &= mask1;
    std::cout << std::bitset<32>(number) << std::endl;
}

int CountOnBits(int number)
{
    int counter = 0;

    while(number > 0)
    {
        counter += (number & 1);
        number >>= 1;
    }

    return counter;
}

int CountOnBitsHack(int number)
{
    int counter = 0;
    while(number > 0)
    {
        //we remove the last 1 digit
        number = number & (number - 1);
        counter++;
    }
    return counter;
}

int FastExponentiation(int number, int exponent)
{
    int result = 1;
    while(exponent > 0)
    {
        if(exponent & 1)
           result *= number;

        number *= number;
        exponent >>= 1;
    }
    return result;
}

int FromDecimalToBinary(int number)
{
    std::vector<bool> values;
    int result = 0;
    while(number > 0)
    {
        values.emplace_back(number % 2);
        number /= 2;
    }

    for(int i = 0 ; i < values.size(); i++)
        if(values[i]) result += FastExponentiation(10,i);

    return result;
}
