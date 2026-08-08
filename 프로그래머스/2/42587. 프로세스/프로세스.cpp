#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    // 우선순위, 인덱스
    queue<pair<int, int>> q;

    for (int i = 0; i < priorities.size(); ++i)
    {
        q.push({ priorities[i], i });
    }

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        
        // 1. q 안에 curr보다 우선순위 높은 것이 있는지 찾기
        bool hasHigher = false;
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            auto temp = q.front();
            q.pop();
            
            if (temp.first > curr.first)
                hasHigher = true;
            
            q.push(temp);
        }

        // 2. 있다면 curr를 q 뒤에 다시 넣기
        if (hasHigher)
        {
            q.push(curr);
        }

        // 3. 없다면 실행 처리
        else 
        {
            answer++;
            if (location == curr.second)
                return answer;
        }

        // 4. 실행된 프로세스의 index가 location이면 return

    }
    
    return answer;
}