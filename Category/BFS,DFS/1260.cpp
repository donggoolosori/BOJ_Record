#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &mtx, vector<bool> &visit, int start)
{
    visit[start] = true;
    cout << start << ' ';
    for (int i = 1; i < mtx[start].size(); i++)
    {
        if (!visit[i] && mtx[start][i] == 1)
            dfs(mtx, visit, i);
    }
}

void bfs(vector<vector<int>> &mtx, int n, int start)
{
    vector<bool> visit(n + 1, false);
    queue<int> q;
    q.push(start);
    visit[start] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int i = 1; i < n + 1; i++)
        {
            if (!visit[i] && mtx[cur][i] == 1)
            {
                q.push(i);
                visit[i] = true;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<int>> mtx(n + 1, vector<int>(n + 1, 0));
    vector<bool> visit(n + 1, false);

    int fr, to;
    for (int i = 0; i < m; i++)
    {
        cin >> fr >> to;
        mtx[fr][to] = 1;
        mtx[to][fr] = 1;
    }
    dfs(mtx, visit, v);
    cout << '\n';
    bfs(mtx, n, v);
    return 0;
}