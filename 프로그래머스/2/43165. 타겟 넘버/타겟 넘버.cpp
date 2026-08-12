#include <bits/stdc++.h>

using namespace std;

int CheckSum(const vector<int>& numbers, int target, int sum, int idx)
{
    if (idx == numbers.size())
        return sum == target;
    
    return CheckSum(numbers, target, sum + numbers[idx], idx + 1)
        + CheckSum(numbers, target, sum - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {
    int sum = 0;
    
    return CheckSum(numbers, target, sum, 0);
}