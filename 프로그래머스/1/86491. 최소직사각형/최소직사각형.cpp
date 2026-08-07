#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    
    // 각 인덱스의 최대값
    int max0 = 0;
    int max1 = 0;
    
    // 가장 큰 수가 있는 index를 0이라고 하고, 모든 벡터의 좌우 중 큰 수를 index 0에 넣는다.
    for (int i = 0; i < sizes.size(); ++i)
    {
        sort(sizes[i].begin(), sizes[i].end(), greater<int>());
        
        max0 = max(max0, sizes[i][0]);
        max1 = max(max1, sizes[i][1]);
    }
    
    return max0 * max1;
}