#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> graph[1001];

void dfs(int idx, vector<bool> &visit)
{
    cout << idx << ' ';
    visit[idx] = true;

    for (const auto &next : graph[idx])
    {
        if (visit[next])
            continue;
        dfs(next, visit);
    }
}

void bfs(int idx, vector<bool> &visit)
{
    queue<int> q;
    q.push(idx);
    visit[idx] = true;

    while (!q.empty())
    {
        int curr = q.front();
        cout << curr << ' ';
        q.pop();

        for (const auto &next : graph[curr])
        {
            if (visit[next])
                continue;
            visit[next] = true;
            q.push(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;
    int fr, to;
    for (int i = 0; i < M; i++)
    {
        cin >> fr >> to;
        graph[fr].push_back(to);
        graph[to].push_back(fr);
    }

    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    vector<bool> visit(N + 1);

    dfs(V, visit);
    visit.assign(N + 1, 0);
    cout << '\n';
    bfs(V, visit);
    return 0;
}