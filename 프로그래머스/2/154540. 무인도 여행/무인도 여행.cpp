#include <bits/stdc++.h>

using namespace std;
using Cell = pair<int, int>;

const int WALL = (int)'X';
const int BASE = 48;

const int dr[] = { -1, 1, 0, 0 };
const int dc[] = { 0, 0, -1, 1 };

int BFS(const vector<string>& maps,
        vector<vector<bool>>& visited,
        const Cell start,
        const Cell end)
{
    queue<Cell> q;
    q.push(start);

    int total = (int)(maps[start.first][start.second]) - BASE;
    
    //cout << "START(" << start.first << ", " << start.second << "): ";
        
    while (!q.empty())
    {
        const Cell& cur = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; ++dir)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            
            if (nr < 0 || nc < 0 || nr >= end.first || nc >= end.second)
                continue;
            
            if (maps[nr][nc] == WALL || visited[nr][nc])
                continue;
            
            visited[nr][nc] = true;
            total += ((int)(maps[nr][nc]) - BASE);
            //cout << " + "<< maps[nr][nc] << " (=" << total << "), ";
            
            q.push({nr, nc});
            
        }
    }
    //cout << " => TOTAL : " << total << endl;
    return total;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    Cell end = { maps.size(), maps[0].size() };
    vector<vector<bool>> visited(end.first, vector<bool>(end.second, false));
    
    for (int i = 0; i < end.first; ++i)
    {
        for (int j = 0; j < end.second; ++j)
        {
            if (visited[i][j])
                continue;
            
            if (maps[i][j] == WALL)
                continue;
            
            visited[i][j] = true;
            
            if (int res = BFS(maps, visited, { i, j }, end))
                answer.push_back(res);
        }
    }
    
    sort(answer.begin(), answer.end());
    if (answer.empty())
        answer.push_back(-1);
    return answer;
}