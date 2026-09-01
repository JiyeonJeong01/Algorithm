#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_set<int> s1(topping.begin(), topping.begin() + 1);
    unordered_set<int> s2(topping.begin() + 1, topping.end());
    
    if (s1.size() == s2.size())
        answer++;
        
    for (int i = 1; i < topping.size(); ++i)
    {
        int num = topping[i];
        
        s1.insert(num);
        
        const auto& it = find(topping.begin() + i + 1, topping.end(), num);
        if (it == topping.end())
            s2.erase(num);
        
        if (s1.size() == s2.size())
            answer++;
    }
    
    return answer;
}