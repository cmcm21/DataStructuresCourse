#include <iostream>
#include <vector>
#include <algorithm>

void Quicksort(std::vector<int> &arr, int start, int end);


int main()
{
    std::vector<int> input = {4,5,3,1,56,7,6,7,8,4,3,7};
    Quicksort(input,0,input.size() - 1);

    std::for_each(input.begin(), input.end(),[&](int inputElement)  {
       std::cout << inputElement << " ";
    });
    std::cout << std::endl;
    return 0;
}

void Quicksort(std::vector<int> &arr, int start, int end)
{
    if(start >= end) return;
    int i = start, j = start, pivot = end;

    while(i < end && j < end)
    {
        if(arr[j] < arr[pivot])
        {
            std::swap(arr[i],arr[j]);
            i++;
        }
        j++;
    }

    std::swap(arr[i],arr[pivot]);

    Quicksort(arr,start,i - 1);
    Quicksort(arr, i + 1, end);
}
