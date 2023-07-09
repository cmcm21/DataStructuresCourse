#include <iostream>
#include <vector>

using namespace std;

pair<int,int> search(int m, int n, vector<vector<int>> v, int k);

int main()
{
    vector<vector<int>> input;
    vector<int> tempInput;

    int m,n,k,temp;
    cin >> m >> n;

    for(int i = 0; i < m; i++)
    {
        tempInput.clear();
        for(int j = 0; j < n; j++)
        {
            cin >> temp;
            tempInput.emplace_back(temp);
        }
        input.emplace_back(tempInput);
    }
    cin >> k;

    auto result = search(m,n,input,k);
    cout << "( " <<result.first << " " << result.second << " )" << endl;
    return 0;
}

pair<int,int> search(int m, int n, vector<vector<int>> v, int k)
{
    for(int i = 0 ; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(v[i][j] == k)
                return make_pair(i,j);
        }
    }

    return make_pair(-1,-1);
}