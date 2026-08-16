#include <bits/stdc++.h>

using namespace std;

int DFS(const vector<vector<string>>& tickets, 
       vector<bool>& visited,
       vector<string>& answer, 
       const string& curr,
       int cnt)
{
    if (cnt == visited.size())
        return true;
    
    for (int i = 0; i < tickets.size(); ++i)
    {
        if (visited[i]) 
            continue;
        
        if (tickets[i][0] != curr) // 출발지가 현재 위치가 아니라면 continue
            continue;
        
        visited[i] = true;
        answer.push_back(tickets[i][1]);
        
        if (DFS(tickets, visited, answer, tickets[i][1], cnt + 1))
            return true;
        
        answer.pop_back();
        visited[i] = false;
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visited(tickets.size(), false);

    // 출발지 비교 후, 같다면 도착지 비교하여 오름차순 정렬
    sort(tickets.begin(), tickets.end());
    
    answer.push_back("ICN");
    DFS(tickets, visited, answer, "ICN", 0);
    
    return answer;
}