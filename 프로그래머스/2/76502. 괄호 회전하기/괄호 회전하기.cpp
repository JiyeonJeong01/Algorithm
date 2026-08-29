#include <bits/stdc++.h>

using namespace std;

void Rotate(deque<char>& dq)
{
    char c = dq.front();
    dq.pop_front();
    dq.push_back(c);
}

bool Check(deque<char>& dq)
{
    stack<char> st;
    for (char c : dq)
    {
        if (c == '[')
            st.push(']');
        else if (c == '(')
            st.push(')');
        else if (c == '{')
            st.push('}');
        else if (c == ']' || c == ')' || c == '}')
        {
            if (!st.empty() && st.top() == c)
                st.pop();
            else 
                return false;
        }
    }
        
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    
    deque<char> dq;
    for (char c : s)
        dq.push_back(c);
    
    for (int i = 0; i < s.length(); ++i)
    {
        if(Check(dq))       
            answer++;
        
        Rotate(dq);
    }
    
    return answer;
}