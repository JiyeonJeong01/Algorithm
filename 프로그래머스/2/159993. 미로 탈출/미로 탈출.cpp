#include <bits/stdc++.h>

#define NOT_VISITED -1

using namespace std;
using Cell = pair<int, int>;

const int dr[4] = { -1, 1, 0, 0 };
const int dc[4] = { 0, 0, -1, 1 };

int BFS(const vector<string>& maps, const Cell& start, const Cell& end)
{
    int rows = maps.size();
    int cols = maps[0].size();
    
    queue<Cell> q;
    vector<vector<int>> dist(rows, vector<int>(cols, NOT_VISITED));
    
    q.push(start);
    dist[start.first][start.second] = 0;
    
    while (!q.empty())
    {
        auto [row, col] = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; ++dir)
        {
            int nr = row + dr[dir];
            int nc = col + dc[dir];
            
            // 이동 가능 여부 확인
            if (nr < 0 || nc < 0 || nr >= rows || nc >= cols)
                continue;
            
            if (dist[nr][nc] != NOT_VISITED || maps[nr][nc] == 'X')
                continue;
            
            q.push({nr, nc});
            dist[nr][nc] = dist[row][col] + 1;
            
            // 현재 목적지 도착 확인
            if (nr == end.first && nc == end.second)
            {
                return dist[nr][nc];
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    Cell start, lever, end;
    
    // 시작점, 출구, 레버의 위치를 먼저 구한다.
    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].size(); ++j)
        {
            char c = maps[i][j];
            if (c == 'S')
                start = {i, j};
            else if (c == 'L')
                lever = {i, j};
            else if (c == 'E')
                end = { i, j};
        }
    }
    
    int toRever = BFS(maps, start, lever);
    if (toRever != -1)
    {
        int toEnd = BFS(maps, lever, end);

        if (toEnd != -1)
            return toRever + toEnd;
    }

    return -1;
}