#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool Compare(const std::string& a, const std::string& b);
void Quicksort(std::vector<std::string> &strings, int start, int end);
void Swap(std::string &a, std::string &b);

int main()
{
    std::vector<std::string> input{"a", "ab", "aba"};

    Quicksort(input,0,input.size() - 1);
    std::for_each(input.begin(),input.end(),[&](const std::string& element){
        std::cout <<  element;
    });

    std::cout << std::endl;
    return 0;
}

bool Compare(const std::string& a, const std::string& b)
{
    return a + b < b + a;
}

void Quicksort(std::vector<std::string> &strings,int start, int end)
{
    if(start > end) return;
    int pivot = end;
    int i = start, j = start;

    while(i < end && j < end)
    {
        if(Compare(strings[j],strings[pivot]))
        {
            std::swap(strings[i],strings[j]);
            i++;
        }
        j++;
    }
    std::swap(strings[i],strings[pivot]);

    Quicksort(strings,start,i - 1);
    Quicksort(strings, i + 1, end);
}
