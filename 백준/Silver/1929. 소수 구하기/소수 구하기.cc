#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m; cin >> n >> m;

	vector<bool> decimal(m+1, true);

	decimal[1] = false;

	for (int i = 2; i <= m; ++i)
	{
		if (!decimal[i]) continue;

		for (int j = i * 2; j <= m; j += i)
		{
			decimal[j] = false;
		}
	}

	for (int i = n; i <= m; ++i)
	{
		if (decimal[i]) cout << i << "\n";
		// /*if (decimal[i])*/ cout << decimal[i] << "\n";
	}
	return 0;
}
