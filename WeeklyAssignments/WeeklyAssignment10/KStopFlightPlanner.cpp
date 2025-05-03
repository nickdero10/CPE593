/*
Author: Nicholas DeRobertis
I Pledge my Honor that I have Abided by the Stevens Honor System
Weekly Assignment 10: Dijkstra's Algorithm
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findCheapestPrice(int n, vector<vector<int>> flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto flight : flights)
        {
            int u = flight[0], v = flight[1], w = flight[2];
            adj[u].push_back({v, w});
        }

        typedef tuple<int, int, int> T;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push(make_tuple(0, src, 0));

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty())
        {
            T current = pq.top();
            pq.pop();

            int cost = get<0>(current);
            int node = get<1>(current);
            int stops = get<2>(current);

            if (node == dst)
                return cost;

            if (stops > k)
                continue;

            for (auto& neighbor : adj[node])
            {
                int next = neighbor.first;
                int price = neighbor.second;
                int newCost = cost + price;

                if (newCost < dist[next][stops + 1])
                {
                    dist[next][stops + 1] = newCost;
                    pq.push(make_tuple(newCost, next, stops + 1));
                }
            }
        }

        return -1;
    }
};

int main()
{
    int n = 3, src = 0, dst = 2, k = 0;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 400}
    };

    Solution obj;
    int result = obj.findCheapestPrice(n, flights, src, dst, k);
    cout << result << endl;

    return 0;
}
