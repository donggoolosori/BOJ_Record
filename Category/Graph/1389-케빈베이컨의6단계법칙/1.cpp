#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int n, m;

int bfs(vector<vector<int>> graph, int fr, int to)
{
    queue<pair<int, int>> q; // 사람번호, 거리
    q.push({fr, 0});
    while (!q.empty())
    {
        int cur = q.front().first;
        int L = q.front().second;
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            if (graph[cur][i] == to)
                return L;
            q.push({graph[cur][i], L + 1});
        }
    }
}
int main()
{
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;
    int min_kevin = 100;
    for (int i = 1; i < n + 1; i++)
    {
        int kevin = 0;
        for (int j = 1; j < n + 1; j++)
        {
            if (i == j)
                continue;
            kevin += bfs(graph, i, j);
        }
        if (kevin < min_kevin)
        {
            ans = i;
            min_kevin = kevin;
        }
    }

    cout << ans;
    return 0;
}