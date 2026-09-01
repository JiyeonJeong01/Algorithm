#include <bits/stdc++.h>

using namespace std;

struct Time
{
    int hh;
    int mm;
    Time(int h, int m) : hh(h), mm(m) {}
    Time(const string& time)
    {
        hh = stoi(string(time.substr(0, 2)));
        mm = stoi(string(time.substr(3, 2)));
    }
    
    int GetLeftMinute(const Time& later)
    {
        int diffH = later.hh - this->hh;
        int diffM = later.mm - this->mm;
        if (diffM < 0)
        {
            diffM += 60;
            diffH--;
        }
        return diffH * 60 + diffM;
    }
};

vector<string> solution(vector<vector<string>> plans) {

    vector<string> done;
    stack<pair<string, int>> stop;
    
    // 시간순 정렬
    sort(plans.begin(), plans.end(), [](const vector<string>& planA, const vector<string>& planB) {
        return (planA[1] < planB[1]);
    });
    
    for (int i = 0; i < plans.size(); ++i)
        cout << plans[i][0] << " ";
    cout << endl;
    
    // 순회하며 각 과제 진행하다가 다음 과제 시간 되면 종료 후 스택에 삽입
    for (int i = 0; i < plans.size() - 1; ++i)
    {
        const string& name = plans[i][0];
        Time start(plans[i][1]);
        int playTime = stoi(plans[i][2]);
        
        int leftMinuteToNext = start.GetLeftMinute(Time(plans[i+1][1]));
        if (leftMinuteToNext < playTime)
        {
            stop.push({name, playTime - leftMinuteToNext});
            continue;
        }
        
        done.push_back(name);
        leftMinuteToNext -= playTime;
        
        while (!stop.empty() && leftMinuteToNext > 0)
        {
            auto latest = stop.top();
            stop.pop();
            
            if (leftMinuteToNext < latest.second)
            {
                stop.push({latest.first, latest.second - leftMinuteToNext});
                break;
            }
            leftMinuteToNext -= latest.second;
            done.push_back(latest.first);
        }
    }
    
    // 남은 거 처리
    done.push_back(plans[plans.size()-1][0]);
    
    while (!stop.empty())
    {
        done.push_back(stop.top().first);
        stop.pop();
    }
    
    return done;
}