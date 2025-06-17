#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, d, from, to, dst;
    cin >> n >> d;
    vector<int> mndst(d+1, INT32_MAX);
    vector<pair<int, int>> paths[10001]; // st - dst 

    for (int i = 0; i < n; i++)
    {
        cin >> from >> to >> dst;
        paths[to].push_back({from, dst});
    }

    mndst[0] = 0, mndst[1] = 1;
    for(int i = 2; i <= d; i++)
    {
        if (paths[i].size() == 0) 
        {
            mndst[i] = mndst[i-1] + 1;
        }
        else 
        {
            for (auto v : paths[i])
            {
                mndst[i] = min(mndst[i], min(mndst[i-1]+1, mndst[v.first]+v.second));
            }
        }
    }
    cout << mndst[d];





    return 0; 

}