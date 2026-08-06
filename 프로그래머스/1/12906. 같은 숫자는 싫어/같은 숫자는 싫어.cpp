#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    stack<int> stk;
    stk.push(arr[arr.size()-1]);
    
    for (int i = arr.size() - 2; i >= 0; --i)
    {
        if (stk.top() != arr[i])
            stk.push(arr[i]);
    }

    while (stk.empty() == false)
    {
        answer.push_back(stk.top());
        stk.pop();
    }
    
    return answer;
}