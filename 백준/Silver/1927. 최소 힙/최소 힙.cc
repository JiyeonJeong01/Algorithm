#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; cin >> N;

	multiset<int> ms;

	while (N--)
	{
		int input; cin >> input;

		if (input == 0)
		{
			int res;
			if (ms.size() == 0)
			{
				res = 0;
			}
			else
			{
				res = *ms.begin();
				ms.erase(ms.begin());
			}

			cout << res << "\n";
		}
		else
		{
			ms.insert(input);
		}

	}



	return 0;
}