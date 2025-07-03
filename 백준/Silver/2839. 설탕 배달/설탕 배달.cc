#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n; cin >> n;

	vector<int> dp(n + 1, INT32_MAX);

	dp[3] = dp[5] = 1;

	for (int i = 6; i <= n; i++)
	{
		int cand = min(dp[i-3], dp[i-5]);

		if (cand == INT32_MAX)
			continue;
		dp[i] = cand + 1;
	}

	cout << (dp[n] != INT32_MAX ? dp[n] : -1);

	return 0;
}
