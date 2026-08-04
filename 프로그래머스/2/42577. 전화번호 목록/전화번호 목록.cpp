#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    
    set<string> s;
    
    for (const auto& num : phone_book)
        s.insert(num);
        
    for (auto iter = s.begin(); iter != prev(s.end());)
    {
        const int len = iter->size();
        const string curr = *iter;
        const string next = string(*(++iter), 0, len);
                
        if (curr == next)
            return false;
    }

    return true;
}