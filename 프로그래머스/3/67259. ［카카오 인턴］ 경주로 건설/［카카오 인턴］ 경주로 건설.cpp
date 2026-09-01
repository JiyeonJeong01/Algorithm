#include <bits/stdc++.h>

#define EMPTY 0
#define WALL 1

using namespace std;
using Cell = pair<int, int>;

const int INF = numeric_limits<int>::max();
const int dr[4] = { -1, 1, 0, 0 };
const int dc[4] = { 0, 0, -1, 1 };

int gSize;
Cell gGoal;
vector<vector<int>> gBoard;
vector<vector<vector<int>>> gMinCost;   // row, col, prevDir

void Visit(
    const int prevDir,
    const Cell& curCell,
    const int curCost,
    int& minCost)
{
    // 현재 경로의 종료 조건.
    if (curCell == gGoal)
    {
        minCost = min(minCost, curCost);
        return;
    }
        
    // 네 방향 탐색
    for (int dir = 0; dir < 4; ++dir)
    {
        int nrow = curCell.first + dr[dir];
        int ncol = curCell.second + dc[dir];
        
        if (nrow < 0 || ncol < 0 || nrow >= gSize || ncol >= gSize)
            continue;
        
        if (gBoard[nrow][ncol] == WALL)
            continue;
        
        int nextCost = curCost + 100;
        if (prevDir != dir)
            nextCost += 500; // 코너 비용
        
        if (gMinCost[nrow][ncol][dir] <= nextCost)
            continue;
        
        gMinCost[nrow][ncol][dir] = nextCost;
        Visit(dir, {nrow, ncol}, nextCost, minCost);
    }   
}

int solution(vector<vector<int>> board)
{   
    gSize = board.size();
    gGoal = { gSize - 1, gSize - 1 };
    gBoard = board;
    gMinCost = vector<vector<vector<int>>>(
            gSize, 
            vector<vector<int>>(
                gSize, vector<int>(4, INF)));
    
    int minCost = INF;
    
    for (int dir = 0; dir < 4; ++dir)
    {
        int nrow = dr[dir];
        int ncol = dc[dir];
        
        if (nrow < 0 || ncol < 0 || nrow >= gSize || ncol >= gSize)
            continue;
        
        if (gBoard[nrow][ncol] == WALL)
            continue;
        
        int nextCost = 100;
        gMinCost[nrow][ncol][dir] = nextCost;
        Visit(dir, {nrow, ncol}, nextCost, minCost);
    }  
    
    return minCost;
}