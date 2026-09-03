#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<string> gWords;
vector<bool> gVisited;
string gTarget;

bool CanTransit(const string& from, const string& to)
{
    bool diff = false;
    for (int i = 0; i < from.size(); ++i)
    {
        if (from[i] != to[i])
        {
            if (diff)
                return false;
            diff = true;
        }
    }
    return true;
}

void DFS(const string& curStr, const int curCnt, int& minCnt)
{    
    if (curStr == gTarget)
    {
        minCnt = min(minCnt, curCnt);
        return;
    }
        
    for (int i = 0; i < gWords.size(); ++i)
    {
        if (gVisited[i])
            continue;
        
        if (!CanTransit(curStr, gWords[i]))
            continue;
        
        gVisited[i] = true;
        DFS(gWords[i], curCnt + 1, minCnt);
        gVisited[i] = false;
    }
}

int solution(string begin, string target, vector<string> words) {
    
    const auto& it = find(words.begin(), words.end(), target);
    if (it == words.end())
        return 0;
    
    gTarget = target;
    gWords = words;
    gVisited = vector<bool>(words.size(), false);
    
    int minCnt = INF;
    DFS(begin, 0, minCnt);
    
    minCnt = minCnt == INF ? 0 : minCnt;
    return minCnt;
}