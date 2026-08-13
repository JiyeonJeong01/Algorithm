#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int left = 0, right = people.size() - 1, cnt = 0;
    
    while (left <= right)
    {
        cnt++;
        if (left == right)
            return cnt;
        
        if (people[right] + people[left] <= limit)
            left++;
        
        right--; 
    }
    
    
    return cnt;
}