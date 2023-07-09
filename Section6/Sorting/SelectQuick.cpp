#include <iostream>
#include <vector>

int SelectQuickSort(std::vector<int> &arr, int start, int end, int k);

int main()
{
    std::vector<int> input = {4,5,3,1,56,7,6,7,8,4,3,7};
    int k = 0;
    std::cout << SelectQuickSort(input,0, input.size() - 1,k) << std::endl;
    return 0;
}

int SelectQuickSort(std::vector<int> &arr, int start, int end, int k)
{
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

    if(k == i)
        return arr[k];
    else if(k > i)
        SelectQuickSort(arr,i + 1, end,k);
    else
        SelectQuickSort(arr,start, i - 1,k);
}
