#include<bits/stdc++.h>

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

#define WALL 0

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int rows = maps.size();
    int cols = maps[0].size();
    
    // 0 - 방문 전
    vector<vector<int>> dist(rows, vector<int>(cols, 0));
    
    queue<pair<int, int>> q;
    
    // 첫 번째 칸 방문
    q.push({0, 0});
    dist[0][0] = 1;
    
    while(!q.empty())
    {
        auto [row, col] = q.front();
        q.pop();
        
        if (row == rows - 1 && col == cols - 1)
            return dist[row][col];
        
        for (int dir = 0; dir < 4; ++dir)
        {
            int nr = row + dr[dir];
            int nc = col + dc[dir];
            
            if (nr < 0 || nc < 0 || nr >= rows || nc >= cols)
                continue;
            
            if (dist[nr][nc] != 0 || maps[nr][nc] == WALL)
                continue;
            
            q.push({nr, nc});
            dist[nr][nc] = dist[row][col] + 1;
        }
    }
    
    return -1;
}