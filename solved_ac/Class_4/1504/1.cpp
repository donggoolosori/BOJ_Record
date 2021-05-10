#include <iostream>
#include <vector>
#include <queue>
#define ll long long

using namespace std;

const int INF = 987654321;
int N, E, v1, v2;
struct Node
{
    int idx, dist;
    bool operator<(const Node &b) const
    {
        return dist > b.dist;
    }
};
vector<Node> graph[801];
int cache[801];

void dijkstra(int start)
{
    for (int i = 1; i <= N; i++)
        cache[i] = INF;
    cache[start] = 0;
    priority_queue<Node> pq;
    pq.push({start, 0});

    while (!pq.empty())
    {
        Node curr = pq.top();
        int idx = curr.idx, dist = curr.dist;
        pq.pop();

        for (const auto &next : graph[idx])
        {
            int nextIdx = next.idx, nextDist = next.dist + dist;
            if (cache[nextIdx] > nextDist)
            {
                cache[nextIdx] = nextDist;
                pq.push({nextIdx, nextDist});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> E;
    int a, b, c;
    while (E--)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    // cand1. 1->v1->v2->N
    // cand2. 1->v2->v1->N
    dijkstra(1);
    ll cand1 = cache[v1], cand2 = cache[v2];
    dijkstra(v1);
    cand1 += cache[v2];
    cand2 += cache[N];
    dijkstra(v2);
    cand1 += cache[N];
    cand2 += cache[v1];

    ll ans = cand1 < cand2 ? cand1 : cand2;
    ans = ans >= INF ? -1 : ans;

    cout << ans << '\n';

    return 0;
}