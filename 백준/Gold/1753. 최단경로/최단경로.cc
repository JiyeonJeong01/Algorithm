#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int V, E, k; cin >> V >> E >> k;

    vector<vector<pair<int, int>>> g(V+1); // g[u] = {v, w}
    vector<int> dist(V+1, INT32_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    dist[k] = 0;
    pq.push({0, k});

    while (!pq.empty())
    {
        int curDist = pq.top().first;
        int curNode = pq.top().second;

        pq.pop();

        if (dist[curNode] < curDist) continue;

        for (auto &edge : g[curNode])
        {
            int nextNode = edge.first;
            int weight = edge.second;
            int newDist = curDist + weight;

            if (newDist < dist[nextNode])
            {
                dist[nextNode] = newDist;
                pq.push({newDist, nextNode});
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INT32_MAX)
            cout<<"INF\n";
        else 
            cout << dist[i] << "\n";
    }
    return 0;
} 