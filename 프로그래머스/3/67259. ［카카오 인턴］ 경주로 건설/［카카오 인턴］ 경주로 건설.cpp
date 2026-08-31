#include <bits/stdc++.h>

using namespace std;
using Cell = pair<int, int>;

const int EMPTY = 0;
const int WALL = 1;

const int dr[4] = { 1, -1, 0, 0 };
const int dc[4] = { 0, 0, -1, 1 };
    
const int INF = numeric_limits<int>::max();

vector<vector<int>> board;
vector<vector<vector<int>>> minCosts;
Cell goal;
int boardSize;

void DFS(
    const int prevDir,
    const int curCost,
    const Cell cur,
    int& minCost)
{
    if (cur == goal)
    {
        minCost = min(curCost, minCost);
        return;
    }
    
    for (int i = 0; i < 4; ++i)
    {
        int nrow = cur.first + dr[i];
        int ncol = cur.second + dc[i];
        
        if (nrow < 0 || ncol < 0 || nrow >= boardSize || ncol >= boardSize)
            continue;
        
        if (board[nrow][ncol] == WALL)
            continue;
        
        int nextCost = curCost + 100;
        if (i != prevDir)
            nextCost += 500;
        
        if (minCosts[nrow][ncol][i] <= nextCost || nextCost >= minCost)
            continue;
        
        minCosts[nrow][ncol][i] = nextCost;
        DFS(i, nextCost, {nrow, ncol}, minCost);
    }
}

int solution(vector<vector<int>> b)
{
    board = b;
    boardSize = board.size();
    
    // 3차원 벡터. row, cell, prevDir
    minCosts = vector<vector<vector<int>>> (
        boardSize,
        vector<vector<int>>(boardSize, vector<int>(4, INF))
    );
    goal = { boardSize - 1, boardSize - 1 };
    
    int minCost = INF;
    
    for (int i = 0; i < 4; ++i)
    {
        int nrow = dr[i];
        int ncol = dc[i];
        
        if (nrow < 0 || ncol < 0 || nrow >= boardSize || ncol >= boardSize)
            continue;
        
        if (board[nrow][ncol] == WALL)
            continue;
        minCosts[nrow][ncol][i] = 100;
        DFS(i, 100, {nrow, ncol}, minCost);
    }

    return minCost;
}