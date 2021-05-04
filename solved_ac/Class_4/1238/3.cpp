// 76ms
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 1001

using namespace std;

int N, M, X;
struct Node
{
    int idx, time;
    bool operator<(const Node &b) const
    {
        return time > b.time;
    }
};
vector<Node> graph[MAX];
int dist[MAX], res[MAX];

void dijkstra(int start)
{
    priority_queue<Node> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty())
    {
        Node curr = pq.top();
        pq.pop();

        for (const auto &next : graph[curr.idx])
        {
            int nextTime = curr.time + next.time;
            if (dist[next.idx] > nextTime)
            {
                dist[next.idx] = nextTime;
                pq.push({next.idx, nextTime});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;
    int s, e, t;
    while (M--)
    {
        cin >> s >> e >> t;
        graph[s].push_back({e, t});
    }

    // 각 노드마다 X에 도착하는 최단거리 구하기
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            dist[j] = INF;
        dijkstra(i);
        res[i] = dist[X];
    }
    // 여기에 X에서 각 노드로 도착하는 최단거리 더하기
    for (int i = 1; i <= N; i++)
        dist[i] = INF;
    dijkstra(X);
    for (int i = 1; i <= N; i++)
        res[i] += dist[i];
    sort(res + 1, res + 1 + N);
    cout << res[N] << '\n';
    return 0;
}