#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

struct Params
{
    int N, M, K, X;
};

void bfs(const vector<list<int>>& vec, const Params& p)
{
    int n = p.N, k = p.K, x = p.X;

    queue<int> q;
    vector<int> visited(n+1, -1);
    
    q.push(x);
    visited[x] = 0;

    while (!q.empty())
    {
        int cur = q.front(); q.pop();

        for (int nx : vec[cur])
        {
            if (visited[nx] != -1) continue;

            visited[nx] = visited[cur] + 1;
            q.push(nx);
        }
    }

    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == k)
        {
            flag = true;
            cout << i << "\n";
        }
    }
    if (!flag) cout << -1;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int N, M, K, X; cin >> N >> M >> K >> X;
    Params p { N, M, K, X };

    vector<list<int>> vec(N + 1);

    for (int m = 0; m < M; m++)
    {
        int s, e; cin >> s >> e;
        vec[s].push_back(e);
    }

    bfs(vec, p);
}