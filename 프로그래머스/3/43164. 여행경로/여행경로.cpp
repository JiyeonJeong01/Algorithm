#include "bits/stdc++.h"

using namespace std;

vector<vector<string>> gTickets;
vector<bool> gVisited;
vector<string> gAnswer;
int gTicketCount;

bool DFS(int count, const string& curr)
{
    if (count >= gTicketCount)
        return true;
    
    // 방문
    for (int i = 0; i < gTicketCount; ++i)
    {
        if (gVisited[i])
            continue;
        if (gTickets[i][0] != curr)
            continue;
        
        gVisited[i] = true;
        gAnswer.push_back(gTickets[i][1]);
        
        if (DFS(count + 1, gTickets[i][1]))
            return true;
        
        // 정답이 아닌 경우
        gVisited[i] = false;
        gAnswer.pop_back();
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    
    gTickets = tickets;
    gTicketCount = tickets.size();
    gVisited = vector<bool>(gTicketCount, false);
    
    sort(gTickets.begin(), gTickets.end());
    gAnswer.push_back("ICN");
    
    DFS(0, "ICN");
    
    return gAnswer;
}