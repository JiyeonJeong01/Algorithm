#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    int totalNumber = number.size();
    
    // 일단 3중 for문으로 접근
    for (int i = 0; i < totalNumber - 2; ++i)
    {
        for (int j = i + 1; j < totalNumber - 1; ++j)
        {
            for (int k = j + 1; k < totalNumber; ++k)
            {
                if (number[i] + number[j] + number[k] == 0)
                    answer++;
            }
        }
    }
    
    return answer;
}