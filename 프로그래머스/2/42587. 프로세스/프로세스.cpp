#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<int> cq;
    vector<int> sorted;
    
    for (int i = 0; i < priorities.size(); ++i)
        cq.push(i);
    
    while(!cq.empty())
    {
        int currIdx = cq.front();
        cq.pop();
        
        if (priorities[currIdx] 
           != *(max_element(priorities.begin(), priorities.end())))
        {
            cq.push(currIdx);
        }
        else 
        {
            // 프로세스 실행
            answer++;
            priorities[currIdx] = 0;
            
            if (currIdx == location)
                return answer;
        }
    }

    
    return answer;
}