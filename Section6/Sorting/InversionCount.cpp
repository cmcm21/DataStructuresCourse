#include <iostream>
#include <vector>

int CountInversions(std::vector<int> &vector, int start, int end);
int CountMerge(std::vector<int> &vector, int start, int half, int end);

int main()
{
    std::vector<int> input {0,5,2,3,1};
    std::cout << CountInversions(input,0,input.size() - 1) << std::endl;
    return 0;
}

int CountInversions(std::vector<int> &vector,int start, int end)
{
   int inversions = 0;
   if(start >= end)
       return 0;

   int half = ((end - start) / 2) + start;

   inversions += CountInversions(vector,start,half);
   inversions += CountInversions(vector,half + 1, end);
   inversions += CountMerge(vector,start, half, end);

   return inversions;
}

int CountMerge(std::vector<int> &vector, int start, int half, int end)
{
    int inversions = 0, i = start, j = half + 1;
    std::vector<int> merged;

    for(int k = start; k <= end ; k++)
    {
        if(j > end || i <= half && vector[i] < vector[j])
        {
            merged.emplace_back(vector[i]);
            i++;
        }
        else
        {
            inversions += half - i + 1;
            merged.emplace_back(vector[j]);
            j++;
        }
    }

    for(int i = 0; i < merged.size(); i++)
        vector[start + i] = merged[i];

    return inversions;
}
