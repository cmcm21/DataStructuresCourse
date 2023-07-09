//
// Created by layca on 2/5/2022.
//

#include "MountainAlgorithm.h"

int MountainAlgorithm::Resolve(std::vector<int>& array)
{
    bool onMountain;
    int maxMountain = 0;
    int currentAmount = 0;
    for(int i = 1; i < array.size() - 1; i++)
    {
        int front = i+1;
        int back  = i-1;
        if(onMountain)
        {
            currentAmount++;
            if(array[i] < array[front])
            {
                onMountain = false;
                if(currentAmount > maxMountain)
                    maxMountain = currentAmount;
                currentAmount = 0;
            }
        }
       if(array[i] > array[back] and array[i] >= array[front]) //Check array[i] is a peak
       {
            onMountain = true;
            int backwards = i-1;
            currentAmount = 1;
            while(backwards >= 0 and array[backwards] <= array[backwards + 1])
            {
                currentAmount++;
                backwards--;
            }
       }
    }
    return maxMountain;
}
