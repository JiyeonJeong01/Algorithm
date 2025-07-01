#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int t, n, m;
	long long ll;
	scanf("%d", &t);

	while (t--)
	{
		ll = 1;
		scanf("%d %d", &n, &m);

		n = min(n, m - n);

		for (int i = 0; i < n; ++i) ll *= (m--);
		for (int i = n; i > 1; --i) ll /= i;
		printf("%lld\n", ll);
	}
	return 0;
}
