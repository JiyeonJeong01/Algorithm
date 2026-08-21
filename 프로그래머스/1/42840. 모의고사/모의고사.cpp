#include <bits/stdc++.h>

using namespace std;

vector<int> gAnswers;

int CountAnswer(const vector<int>& answer)
{
    int count = 0;
    
    for (int i = 0; i < gAnswers.size(); ++i)
        if (gAnswers[i] == answer[i % answer.size()])
            count++;
    return  count;
}

vector<int> solution(vector<int> answers) {    
    gAnswers = answers;
    
    const vector<int> one = { 1, 2, 3, 4, 5 };
    const vector<int> two = { 2, 1, 2, 3, 2, 4, 2, 5 };
    const vector<int> three = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
    int first = CountAnswer(one);
    int second = CountAnswer(two);
    int third = CountAnswer(three);
    
    int mx = max({first, second, third});
    
    vector<int> result;

    if (first == mx)
        result.push_back(1);

    if (second == mx)
        result.push_back(2);

    if (third == mx)
        result.push_back(3);

    return result;
}