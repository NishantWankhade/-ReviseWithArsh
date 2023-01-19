#include <bits/stdc++.h>
using namespace std;

// Learning Reference https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/solutions/2700975/c-dijkstra-algorithm-easy-understanding/

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, int>> adj[n];

        // Creating a Graph
        for (auto x : roads)
        {

            adj[x[0]].push_back({x[1], x[2]});

            // Because its a undirected graph
            adj[x[1]].push_back({x[0], x[2]});
        }

        // Creating a priority queue for moving to other nodes accrodingly
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

        vector<long long> dist(n, 1e15), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        int mod = (int)(1e9 + 7);

        // Traversing in with starting the queue
        while (!pq.empty())
        {
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                // This is first time arriving with this short distance
                if ((dis + edW) < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (dis + edW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};