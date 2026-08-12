#include <bits/stdc++.h>

using namespace std;

int DFS(const vector<vector<int>>& dungeons, vector<bool>& visited, int cur, int k, int cnt)
{
    visited[cur] = true;
    k -= dungeons[cur][1];
    ++cnt;
        
    int maxCnt = cnt;
    for (int next = 0; next < visited.size(); ++next)
    {
        if (visited[next])
            continue;
        
        if (k < dungeons[next][0])
            continue;
        
        maxCnt = max(maxCnt, DFS(dungeons, visited, next, k, cnt));
    }
    visited[cur] = false;
    
    return maxCnt;
}
    
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    for (int i = 0; i < dungeons.size(); ++i)
    {
        if (k < dungeons[i][0])
            continue;
        
        vector<bool> visited(dungeons.size(), false);
        answer = max(DFS(dungeons, visited, i, k, 0), answer);
    }        
    
    return answer;
}