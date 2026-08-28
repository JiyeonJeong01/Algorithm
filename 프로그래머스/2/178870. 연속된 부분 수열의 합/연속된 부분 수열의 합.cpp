#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int sum = 0;
    int i = 0, j = 0;
    int left = 0;
    bool found = false;

    for (int right = 0; right < sequence.size(); ++right)
    {
        sum += sequence[right];

        while (sum > k)
        {
            sum -= sequence[left];
            ++left;
        }

        if (sum == k)
        {
            int best = j - i;
            int now = right - left;

            if (!found  || now < best)
            {
                i = left;
                j = right;
                found = true;
            }
        }
    }

    return { i, j };
}