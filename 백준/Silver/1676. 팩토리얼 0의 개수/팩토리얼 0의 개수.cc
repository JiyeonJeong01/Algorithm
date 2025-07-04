#include <iostream>

using namespace std;

int main(void)
{
	int n; cin >> n;

	int res = (n / 5) + (n / 25) + (n / 125);
	cout << res;

	return 0;
}
