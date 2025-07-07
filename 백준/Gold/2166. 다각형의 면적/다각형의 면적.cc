#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define X first
#define Y second

using namespace std;

int main(void)
{
	int n;
	double tmp1, tmp2;
	pair<double, double> op;
	vector<pair<double, double>> vp;

	cin >> n;
	cin >> op.first >> op.second;
	vp.push_back(op);

	for (int i = 1; i < n; i++)
	{
		cin >> tmp1 >> tmp2;
		vp.push_back({tmp1, tmp2});
	}

	double total = 0.0;
	pair<int, int> p1, p2;
	for (int i = 1; i < n - 1; i++)
	{
		p1 = vp[i];
		p2 = vp[i + 1];
		total += (op.X * (p1.Y - p2.Y) + p1.X * (p2.Y - op.Y) + p2.X * (op.Y - p1.Y)) / 2.0;
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(total);

	return 0;
}
