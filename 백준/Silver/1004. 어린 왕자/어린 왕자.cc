#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define X first
#define Y second

using namespace std;

struct Planet
{
	int x, y, r;
	Planet(int x, int y, int r) : x(x), y(y), r(r) {}
};

int getDistance(int x1, int y1, int x2, int y2)
{
	int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	return dist;
}

int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	int sx, sy, ex, ey, cx, cy, r, n, cnt;

	vector<Planet> v;

	while (tc--)
	{
		cin >> sx >> sy >> ex >> ey >> n;
		cnt = 0;
		v.clear();
		for (int i = 0; i < n; ++i)
		{
			cin >> cx >> cy >> r;
			v.push_back({ cx, cy, r });
		}

		for (int i = 0; i < n; ++i)
		{
			int distToStart = getDistance(v[i].x, v[i].y, sx, sy);
			int distToEnd = getDistance(v[i].x, v[i].y, ex, ey);
			int rRange = v[i].r * v[i].r;

			if (distToStart < rRange && distToEnd < rRange)
			{
				continue;
			}
			if (distToStart < rRange)
			{
				cnt++;
			}
			if (distToEnd < rRange)
			{
				cnt++;
			}
		}
		cout << cnt << "\n";
	}


	return 0;
}
