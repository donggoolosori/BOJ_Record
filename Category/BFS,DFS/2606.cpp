#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &network, int n)
{
    int cnt = 0;
    vector<bool> visit(n + 1, false);
    visit[1] = true;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 1; i < network.size(); i++)
        {
            if (network[cur][i] == 1 && !visit[i])
            {
                visit[i] = true;
                cnt++;
                q.push(i);
            }
        }
    }
    cout << cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> network(n + 1, vector<int>(n + 1, 0));

    int fr, to;
    for (int i = 0; i < k; i++)
    {
        cin >> fr >> to;
        network[fr][to] = 1;
        network[to][fr] = 1;
    }

    bfs(network, n);

    return 0;
}