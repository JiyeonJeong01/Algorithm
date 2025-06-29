#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;             // 포도주 잔의 개수 
	int wine[10000];   // 포도주의 양 
	int drink[10000];  // 최대로 마실 수 있는 포도주의 양

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> wine[i];
	}

	drink[0] = wine[0];
	drink[1] = wine[0] + wine[1];
	drink[2] = max(drink[1], max(drink[0] + wine[2], wine[1] + wine[2]));

	for (int i = 3; i < n; i++) {
		drink[i] = max(drink[i - 1], 
		max(drink[i - 2] + wine[i], drink[i - 3] + wine[i - 1] + wine[i]));
	}

	cout << drink[n - 1];

	return 0;
}