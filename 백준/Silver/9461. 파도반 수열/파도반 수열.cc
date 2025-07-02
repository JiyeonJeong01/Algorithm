#include <bits/stdc++.h>
using namespace std;

int T, N;
long long int d[102];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;

    d[1] = d[2] = d[3] = 1l;
    d[4] = d[5] = 2l;
    for(int i = 6; i < 101; i++)
        d[i] = d[i-5] + d[i-1];

    int tmp;
    while(T--) {
        cin >> tmp;
        cout << d[tmp] << '\n';
    }
}