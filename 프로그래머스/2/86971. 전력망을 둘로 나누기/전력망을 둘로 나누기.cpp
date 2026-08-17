#include <bits/stdc++.h>

using namespace std;

const int MAX_INT = 99999;
    
vector<vector<int>> gWires;
vector<bool> gVisited;

int DFS(int cur, int cutA, int cutB)
{
    gVisited[cur] = true;
    
    int cnt = 1;
    for (int next : gWires[cur])
    {
        if (gVisited[next])
            continue;
        
        // 끊긴 간선, 양방향 고려
        if ((cur == cutA && next == cutB)
           || (cur == cutB && next == cutA))
            continue;
        
        cnt += DFS(next, cutA, cutB);
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    
    gWires = vector<vector<int>>(n + 1);
    
    // 인접리스트 만들기
    for (const auto& wire : wires)
    {
        gWires[wire[0]].push_back(wire[1]);
        gWires[wire[1]].push_back(wire[0]);
    }
    
    int mn = MAX_INT;
    
    // wires[0]부터 전부 끊어보면서 최소 diff 찾기
    for (int i = 0; i < wires.size(); ++i)
    {
        gVisited = vector<bool>(n + 1, false);
        
        int area = DFS(1, wires[i][0], wires[i][1]);
        
        int diff = abs(2 * area - n);
        
        mn = min(diff, mn);
    }
    
    return mn;
}