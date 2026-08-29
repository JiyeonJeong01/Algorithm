#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
   
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0ll);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0ll);
    
    long long totalSum = sum1 + sum2;
    
    if (totalSum % 2 != 0)
        return -1;

    long long goal = totalSum / 2;
    
    int n = queue1.size();
    int size = n * 2;
    vector<int> queues;
    queues.reserve(size);
    
    for (int num : queue1)
        queues.push_back(num);
    for (int num : queue2)
        queues.push_back(num);
    
    int left = 0;
    int right = n;
    int cnt = 0;
    
    while (cnt <= size * 2 )
    {
        if (sum1 == goal)
            return cnt;
        
        if (sum1 > goal)
        {
            sum1 -= queues[left];
            left = (left + 1) % size;
        }
        else 
        {
            sum1 += queues[right];
            right = (right + 1) % size;
        }
        
        cnt++;
    }
    
    return -1;
}