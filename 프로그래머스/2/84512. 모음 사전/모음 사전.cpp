#include <bits/stdc++.h>

using namespace std;

const string g_string = "AAAAAEEEEEIIIIIOOOOOUUUUU";
string g_target = "";

int Search(unordered_set<string>& total,
            vector<bool> visited,
            string& cur,
            int& cnt)
{
    cout << cnt << " : " << cur << endl;
    
    if (cur == g_target)
        return cnt;
    
    if (cur.size() == 5)
        return -1;
    
    for (int i = 0; i < g_string.size(); ++i)
    {
        if (visited[i])
            continue;                
        if (total.find(cur + g_string[i]) != total.end())
            continue;
        
        visited[i] = true;
        cur.push_back(g_string[i]);
        total.insert(cur);
        
        int answer = Search(total, visited, cur, ++cnt);
        if (answer != -1)
            return answer;
        
        cur.pop_back();
        visited[i] = false;
    }
    
    return -1;
}
    
int solution(string word) {
    g_target = word;
    vector<bool> visited(g_string.size(), false);
    
    unordered_set<string> total;
    string str = "";
    int cnt = 0;
    
    return Search(total, visited, str, cnt);
}