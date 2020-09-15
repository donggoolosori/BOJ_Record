#include <iostream>
#include <vector>

using namespace std;
int n;
int t1, t2, m;

void dfs(vector<vector<int>> &family, vector<int> &visit, int L, int start)
{
    for (int i = 1; i < n + 1; i++)
    {
        if (family[start][i] == 1 && !visit[i])
        {
            visit[i] = visit[start] + 1;
            dfs(family, visit, L + 1, i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> n >> t1 >> t2 >> m;
    vector<vector<int>> family(n + 1, vector<int>(n + 1, 0));
    vector<int> visit(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        family[a][b] = 1;
        family[b][a] = 1;
    }

    dfs(family, visit, 0, t1);
    int res = visit[t2] == 0 ? -1 : visit[t2];
    cout << res;

    return 0;
}