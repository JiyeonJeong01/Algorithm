#include <bits/stdc++.h>

using namespace std;

void DFS(
    const string& numbers,
    vector<bool>& used,
    set<int>& primeCandidates,
    string& curNumber)
{
    // 현재까지 만든 curNumber를 처리
    if (!curNumber.empty())
        primeCandidates.insert(stoi(curNumber));
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (used[i])
            continue;
        
        used[i] = true;
        curNumber.push_back(numbers[i]);
        
        DFS(numbers, used, primeCandidates, curNumber);
        
        curNumber.pop_back();
        used[i] = false;
    }
}

bool IsPrime(int candidate)
{
    if (candidate < 2)
        return false;
    
    for (int i = 2; i * i <= candidate; ++i)
        if (candidate % i == 0)
            return false;
    
    return true;
}

int solution(string numbers) {    
    vector<bool> used(numbers.size(), false);
    set<int> primeCandidates;
    
    string str = "";
    DFS(numbers, used, primeCandidates, str);
    
    int answer = 0;

    for (int candidate : primeCandidates)
    {
        if (IsPrime(candidate))
            answer++;
    }

    return answer;
}