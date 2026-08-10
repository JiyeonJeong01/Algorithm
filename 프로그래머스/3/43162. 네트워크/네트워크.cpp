#include <bits/stdc++.h>

using namespace std;

void DFS(int idx, int n, const vector<vector<int>>& computers, vector<bool>& visited)
{
    visited[idx] = true;
    
    for (int next = 0; next < n; ++next)
    {
        if (!computers[idx][next])
            continue;
        
        if (visited[next])
            continue;
        
        DFS(next, n, computers, visited);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visited(n, false);
    
    for (int idx = 0; idx < n; ++idx)
    {
        if (visited[idx])
            continue;
        
        ++answer;
        DFS(idx, n, computers, visited);
    }
    
    
    return answer;
}