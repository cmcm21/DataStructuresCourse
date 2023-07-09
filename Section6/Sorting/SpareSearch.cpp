#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int Search(std::vector<std::string> &strings, std::string searchedString);

int main()
{
    std::vector<std::string> input {"ai","","","bat","","","car","","","dog",""};

    std::cout << Search(input,"dog") << std::endl;

    return 0;
}

int Search(std::vector<std::string> &strings, std::string searchedString)
{
    int mid,start = 0, end = strings.size() - 1;
    int i,j;
    std::string notEmptyStr;

    while(start <= end)
    {
        mid = start + (end - start)/ 2 ;

        if(strings[mid].empty())
        {
            i = mid - 1;
            j = mid + 1;

            while(strings[i].empty() && strings[j].empty() && i <= end && j <= end) { i++; j++; }

            if(!strings[i].empty())
                notEmptyStr = strings[i];
            else if(!strings[j].empty())
                notEmptyStr = strings[j];
            if(notEmptyStr.empty())
                return -1;

            if(notEmptyStr > searchedString)
                end = mid - 1;
            else
                start = mid + 1;
        }
        else if(strings[mid] == searchedString)
            return mid;
        else if(strings[mid] > searchedString)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}
