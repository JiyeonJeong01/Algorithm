#include <bits/stdc++.h>

using namespace std;

void CheckSum(const vector<int>& numbers, int target, int sum, int idx, int& answer)
{
    if (idx == numbers.size())
    {
        if (sum == target)
            answer++;
        return;
    }
    
    CheckSum(numbers, target, sum + numbers[idx], idx + 1, answer);
    CheckSum(numbers, target, sum - numbers[idx], idx + 1, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int sum = 0;
    CheckSum(numbers, target, sum, 0, answer);
    
    return answer;
}