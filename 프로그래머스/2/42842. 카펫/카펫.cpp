#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> factors;
    
    const int total = brown + yellow;
    
    for (int i = total; i >= 1; --i)
        if (total %  i == 0)
           factors.push_back(i);
    
    for (int i = 0; i < factors.size() - 1; ++i)
    {
        for (int j = i; j < factors.size(); ++j)
        {
            int num = total / factors[i];
            if (2 * factors[i] + 2 * num - 4 == brown)
                return {factors[i], num};
        }
    }
    
    return answer;
}