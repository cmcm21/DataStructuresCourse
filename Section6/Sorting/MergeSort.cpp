#include <iostream>
#include <vector>
#include <algorithm>


void MergeSort(std::vector<int> &arr,int start, int end);
void Merge(std::vector<int> &arr, int start,int end);

int main()
{
    std::vector<int> sample = {3,4,1,3,5,6,78,9,0,9, 33, 22, 3, 222, 3};
    MergeSort(sample,0,sample.size() - 1);
    std::for_each(sample.begin(),sample.end(),[&](int element){
        if(element == *sample.end())
            std::cout << element << " " << std::endl;
        else
            std::cout << element << " ";
    }) ;
}

void MergeSort(std::vector<int> &arr, int start, int end)
{
    if(start >= end) return;

    int half = ((end - start) / 2) + start;

    MergeSort(arr,start, half);
    MergeSort(arr, half + 1,end);
    Merge(arr,start,end);
}

void Merge(std::vector<int> &arr, int start, int end)
{
    int half = ((end - start) / 2) + start;
    int secondStart = half + 1;
    int tempStart = start;
    std::vector<int> merged;

    for(int i = start; i <= end ; i++)
    {
        if(secondStart > end || tempStart <= half && arr[tempStart] < arr[secondStart])
        {
            merged.emplace_back(arr[tempStart]);
            tempStart++;
        }
        else
        {
            merged.emplace_back(arr[secondStart]);
            secondStart++;
        }
    }

    for(int i = 0; i < merged.size(); i++)
        arr[start + i] = merged[i];
}
