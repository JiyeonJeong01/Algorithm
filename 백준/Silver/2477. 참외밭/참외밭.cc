#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int K, tmpDir, tmpLen;
    cin >> K;

    vector<int> count(5, 0);
    vector<pair<int, int>> v;
    for (int i = 0; i < 6; i++)
    {
        cin >> tmpDir >> tmpLen;
        v.push_back({tmpDir, tmpLen});
        count[tmpDir]++;
    }

    int total = 1, part = 1;
    for (int i = 0; i < 6; i++)
    {
        if (count[v[i].first] == 1)
        {
            total *= v[i].second;
            continue;
        }
        if (v[i].first == v[(i+2)%6].first)
            part *= v[(i+1)%6].second;
    }
    cout << K * (total - part);
}