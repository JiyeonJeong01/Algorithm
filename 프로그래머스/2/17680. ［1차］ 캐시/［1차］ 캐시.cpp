#include <bits/stdc++.h>

using namespace std;

struct Cache
{
    int size = 0;
    int newIdx = 0;
    list<string> cache;
    
    void Init(int s)
    {
        size = s;
    }
    bool Search(const string& item)
    {
        auto it = find(cache.begin(), cache.end(), item);

        if (it != cache.end())  
        {
            cache.erase(it);
            cache.push_front(item);
            return true;
        }

        cache.push_front(item);

        if (cache.size() > size)
            cache.pop_back();

        return false;
    }
};


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    Cache cache;
    cache.Init(cacheSize);
    
    for (auto city : cities)
    {
        transform(
            city.begin(), city.end(), city.begin(),
            [](char c) {
                return tolower(c);
            }
        );
        
        if (cache.Search(city))
            answer += 1;
        else 
            answer += 5;
    }
    
    return answer;
}