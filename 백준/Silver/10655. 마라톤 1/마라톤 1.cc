#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cx, cy;
    cin >> n >> cx >> cy;

    vector<pair<int, int>> arr;
    arr.emplace_back(cx, cy);

    int sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        int nx, ny;
        cin >> nx >> ny;
        arr.emplace_back(nx, ny);
        sum += abs(cx - nx) + abs(cy - ny);
        cx = nx;
        cy = ny;
    }

    int skip = 0;
    for (int i = 1; i < n - 1; ++i) {
        int a = abs(arr[i - 1].first - arr[i].first) + abs(arr[i - 1].second - arr[i].second);
        int b = abs(arr[i].first - arr[i + 1].first) + abs(arr[i].second - arr[i + 1].second);
        int c = abs(arr[i - 1].first - arr[i + 1].first) + abs(arr[i - 1].second - arr[i + 1].second);
        skip = max(skip, a + b - c);
    }

    cout << sum - skip;
}
