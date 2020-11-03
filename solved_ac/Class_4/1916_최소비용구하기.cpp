#include <queue>
#include <vector>
#include <iostream>
#define INF 987654321

using namespace std;

struct node
{
    int to;
    int cost;
};
int n, m, start, goal;
vector<node> city[1001];

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int fr, to, cost;
    while (m--)
    {
        cin >> fr >> to >> cost;
        city[fr].push_back({to, cost});
    }
    cin >> start >> goal;
}

int dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> d(n + 1, INF);
    d[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();
        int cost = cur.first;
        int index = cur.second;
        if (d[index] < cost)
            continue;

        for (const auto &i : city[index])
        {
            int next_cost = cost + i.cost;
            int next_index = i.to;
            if (d[next_index] > next_cost)
            {
                d[next_index] = next_cost;
                pq.push({next_cost, next_index});
            }
        }
    }
    return d[goal];
}

int main()
{
    input();
    cout << dijkstra();
    return 0;
}