#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void TestBadness();
void TestSortBalls();
void TestSubArray();
int Badness(vector<pair<string,int>> &teams);
void MergeSort(vector<pair<string,int>> &teams, int start, int end);
void Merge(vector<pair<string,int>> &teams, int start, int end);
vector<int> SortBalls(vector<int> balls);
pair<int,int> SmallestSubArray(vector<int> array);
int Distance(pair<int,int> pair);

int main()
{
    TestSubArray();
    return 0;
}


int Badness(vector<pair<string,int>> &teams)
{
    unordered_set<int> positions;
    unordered_set<int> leftovers;
    int rankListStart, rankListEnd;
    int badness = 0;

    sort(teams.begin(),teams.end(),[&](pair<string,int> team1, pair<string,int> team2)-> bool {
       return team2.second > team1.second;
    });

    rankListStart = teams.begin()->second;
    rankListEnd = (teams.end() - 1)->second;

    for(int i = rankListStart; i <= rankListEnd; i++)
        positions.insert(i);

    for(auto & team : teams)
    {
       if(positions.contains(team.second))
           positions.erase(positions.find(team.second));
       else
           leftovers.insert(team.second);
    }

    for(auto &leftover : leftovers)
    {
        int min = INT16_MAX;
        int positionSelected;
        for(auto &position : positions)
        {
            int newMin = leftover > position ? leftover - position : position - leftover;
            if(newMin < min)
            {
                min = newMin;
                positionSelected = position;
            }
        }

        positions.erase(positions.find(positionSelected));
        badness += min;
    }

    return badness;
}


void MergeSort(vector<pair<string,int>> &teams, int start, int end)
{
   if(start >= end) return;
   int middle = start + (end - start) / 2;

    MergeSort(teams, start, middle);
    MergeSort(teams, middle + 1, end);
    Merge(teams, start, end);
}

void Merge(vector<pair<string,int>> &teams, int start, int end)
{
    int middle = start + (end - start) / 2;
    int firstStart = start;
    int secondStart = middle + 1;
    vector<pair<string, int>> merged;

    while(firstStart <= middle || secondStart <= end)
    {
        if(secondStart > end || firstStart <= middle && teams[firstStart].second < teams[secondStart].second)
            merged.emplace_back(teams[firstStart++]);
        else
            merged.emplace_back(teams[secondStart++]);
    }

    for(int i = 0; i < merged.size(); i++)
        teams[start + i] = merged[i];
}

vector<int> SortBalls(vector<int> balls)
{
    int low = 0, mid = 0, high = balls.size() - 1;

    while(mid < high)
    {
        if(balls[mid] == 0)
        {
            if(mid != low) swap(balls[mid],balls[low]);
            mid++;
            low++;
        }
        else if(balls[mid] == 1)
        {
            mid++;
        }
        else if(balls[mid] == 2)
        {
            swap(balls[mid],balls[high]);
            high--;
        }
    }
    return balls;
}

pair<int,int> SmallestSubArray(vector<int> array)
{
    int low, high, subIndexLow,subIndexHigh;
    pair<int,int> subArray = {-1,-1};
    pair<int,int> tempSubArray;

    for(int i = 0; i < array.size() - 1; i++)
    {
        if(array[i] > array[i + 1])
        {
            subIndexLow = i;
            subIndexHigh = i + 1;

            while(subIndexLow >= 0 && array[subIndexLow] > array[i + 1])
                subIndexLow--;

            while(subIndexHigh < array.size() && array[i] > array[subIndexHigh])
                subIndexHigh++;

            low = subIndexLow + 1, high = subIndexHigh - 1;
            tempSubArray = make_pair(low,high);

            if (Distance(subArray) == 0 || Distance(subArray) > Distance(tempSubArray))
                subArray = tempSubArray;
        }
    }
    return subArray;
}

int Distance(pair<int,int> pair)
{
    return pair.second - pair.second;
}
/////////////////////////////////TEST FUNCTIONS AREA/////////////////

void TestBadness()
{
    vector<pair<string, int>> teams = {
            {"WOB",1},
            {"BOD", 2},
            {"WHK",2},
            {"BHCH",1},
            {"DCEC",5},
            {"SC",7},
            {"WHk",7}
    };

    cout << Badness(teams) << endl;
}

void TestSortBalls()
{
    vector<int> input = {0,0,1,2,0,1,2,0};
    auto result = SortBalls(input);

    cout << "\n[ ";
    for_each(result.begin(),result.end(),[&](int value){ cout << value; });
    cout << " ]" <<endl;
}

void TestSubArray()
{
    vector<int> input = {0,2,4,7,10,11,7,12,13,14,16,19,29};
    vector<int> input2 = {1,2,3,4,5,8,6,7,9,10,11,};
    auto result = SmallestSubArray(input);

    printf("[%d, %d]", result.first, result.second);
}
///////////////////////////////TEST FUNCTIONS AREA END///////////////////