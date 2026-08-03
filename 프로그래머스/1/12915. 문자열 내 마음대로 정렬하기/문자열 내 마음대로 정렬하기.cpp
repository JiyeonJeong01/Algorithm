#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    int totalCnt = strings.size();
    
    vector<vector<string>> v;
    v.resize(27);
    
    cout << "totalCnt : " << totalCnt << endl;
    
    for (int i = 0; i < totalCnt; ++i)
    {
        char c = strings[i][n];
        int idx = c - 'a';
        
       cout << "c : " << c << " idx : " << idx << endl;      
        
        v[idx].push_back(strings[i]);
    }
    
    for (int i = 0; i < 27; ++i)
    {
        sort(v[i].begin(), v[i].end());
    }
    
    for (int i = 0; i < 27; ++i)
    {
        cout << " === " << (char)(i + 'a') << "===" << endl;
        for (int j = 0; j < v[i].size(); ++j)
        {
            cout << v[i][j] << endl;
           answer.push_back(v[i][j]); 
        }
    }
    
    return answer;
}