#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {    
    // 남은 작업 기간을 구한다.
    vector<int> days(progresses.size());
    for (int i = 0; i < progresses.size(); ++i)
    {
        // 의문 :         days[i] = ((100 - progresses[i] + speeds[i]) / speeds[i]) - 1;
        // 이거 왜 안 될까? 작업도와 속도가 가 30인 경우에 안 맞네.
        days[i] = ((100 - progresses[i]) / speeds[i]); 
        if ((100 - progresses[i]) % speeds[i])
            days[i]++;
    }
    
    // 0번 작업부터 순회하며, days[j] -= days[i]
    vector<int> cnts;
    for (int i = 0; i < days.size(); )
    {
        if (days[i] == 0)
            continue;
        int cnt = 0;
        
        cout << days[i] << " : ";
        
        for (int j = i; j < days.size(); ++j)
        {
            if (days[j] <= 0) 
                continue;
            
            // 0보다 작거나 같으면 cnt에 계산한다.   
            int day = days[j] - days[i];
            cout << "(day : " << day << ") ";
            if (day <= 0)
            {
                cnt++;
            }
            else 
            {
                break;
            }
            cout << days[j] << ", ";
        }
        i += cnt;
        cout << " => " << cnt << endl;
        cnts.push_back(cnt);
    }
    
    return cnts;
}