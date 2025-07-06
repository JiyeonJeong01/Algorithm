#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main(void)
{
	int N; cin >> N;
	map<int, int> mp; // value - cnt
	map<int, int>::iterator it;
	vector<int> v; // value

	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		int tmp; cin >> tmp;

		it = mp.find(tmp);
		if (it != mp.end())
			mp[tmp] = mp[tmp]+1;
		else 
			mp.insert({tmp, 1});
		v.push_back(tmp);

		sum +=  tmp;
	}

	// 산술평균
	int avg = round((float)sum / (float)N);
	cout << (avg == -0 ? 0 : avg) << "\n";
	
	sort(v.begin(), v.end());

	// 중앙값 
	int mid = (N - 1)/ 2;
	cout << v[mid] << "\n";

	int modeCnt = 0;
	for (it = mp.begin(); it != mp.end(); it++)
	{
		if (it->second > modeCnt)
			modeCnt = it->second;
	}

	bool isFirst = true;
	int mode; 
	for (it = mp.begin(); it != mp.end(); it++)
	{
		if (it->second == modeCnt)
		{
			if (isFirst)
            {
				isFirst = false;
				mode = it->first;
			}
			else
            {
				mode = it->first;
				break;
			}
		}
	}
	cout << mode << "\n";
	cout << v[N-1] - v[0] << "\n";

	return 0;
}
