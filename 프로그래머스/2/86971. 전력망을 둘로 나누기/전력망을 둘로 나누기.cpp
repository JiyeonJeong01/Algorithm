#include <bits/stdc++.h>

#define INT_MAX_V 99999

using namespace std;

vector<vector<int>> gWires;

int Search(
    vector<bool>& visited, 
    const pair<int, int>& cut, 
    int cur)
{
    visited[cur] = true;
    int cnt = 1;
    // 내 노드와 연결된 노드 전부 방문 시도
    for (auto next : gWires[cur])
    {
        // 이미 방문했으면 방문하지 않는다.
        if (visited[next])
            continue;
        
        if ((cut.first == cur && cut.second == next)
           || cut.first == next && cut.second == cur)
            continue;
        
        cnt += Search(visited, cut, next);
    }
    
    // 현재까지의 깊이를 반환한다.
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {

    gWires = vector<vector<int>>(n + 1);
    
    for (int i = 0; i < wires.size(); ++i)
    {
        gWires[wires[i][0]].push_back(wires[i][1]);
        gWires[wires[i][1]].push_back(wires[i][0]);
    }
    
    // 전선을 하나씩 끊어보며 전부 확인해야 한다.
    int mn = INT_MAX_V;
    for (int i = 0; i < wires.size(); ++i)
    {
        vector<bool> visited(n + 1, false);
        // 끊는다.
        int area = Search(visited, {wires[i][0], wires[i][1]}, 1);
        
        int diff = abs(2 * area - n);
        mn = min(diff, mn);
    }
    
    return mn;
}