#include <bits/stdc++.h>

#define endl "\n";

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    // 벡터 -> umap 이동
    unordered_map<string, int> m;
    for (const auto& name : participant)
        m[name]++;
    
    // participant에서 completion 제외하기
    for (const auto& name : completion)
        m[name]--;
    
    // cnt 가 1인 key 찾기
    for (const auto& p : m)
    {
        if (p.second == 1)
            return p.first;
    }
    
    return "invalid case";
}