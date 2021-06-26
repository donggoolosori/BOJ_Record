#include <iostream>
#include <vector>

#define MAX_SIZE 1000 + 1

using namespace std;

vector<vector<int>> graph(MAX_SIZE);
vector<bool> visited(MAX_SIZE, false);

void dfs(int s)
{
    visited[s] = true;
    for (int i = 0; i < graph[s].size(); i++)
    {
        int next = graph[s][i];
        if (!visited[next])
            dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;

    return 0;
}