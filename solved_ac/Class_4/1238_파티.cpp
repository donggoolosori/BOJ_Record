#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001
#define INF 987654321
#define max(a, b) a > b ? a : b

using namespace std;

struct node
{
    int index, time;
};
int n, m, x;
vector<node> graph[MAX];
int ans;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> x;
    int fr, to, time;
    while (m--)
    {
        cin >> fr >> to >> time;
        graph[fr].push_back({to, time});
    }
}

int dijkstra(int start, int destination)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> d(n + 1, INF);
    d[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();
        int cur_time = cur.first;
        int cur_index = cur.second;
        if (d[cur_index] < cur_time)
            continue;

        for (const auto &i : graph[cur_index])
        {
            int next_time = cur_time + i.time;
            int next_index = i.index;
            if (d[next_index] > next_time)
            {
                d[next_index] = next_time;
                pq.push({next_time, next_index});
            }
        }
    }
    return d[destination];
}

void solve()
{
    for (int start = 1; start <= n; start++)
    {
        int temp = dijkstra(start, x) + dijkstra(x, start);
        ans = max(ans, temp);
    }
    cout << ans << '\n';
}

int main()
{
    input();
    solve();

    return 0;
}