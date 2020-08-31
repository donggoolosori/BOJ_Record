#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> make_grid(int n, vector<pair<int, int>> &pos)
{
    vector<vector<int>> pos_grid(n + 2, vector<int>(n + 2, 0));
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            if (i == j)
                continue;
            int dist = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
            if (dist <= 20 * 50)
            {
                pos_grid[i][j] = 1;
                pos_grid[j][i] = 1;
            }
        }
    }
    return pos_grid;
}
void dfs(int cur, vector<vector<int>> pos_grid, vector<bool> &visit, int n)
{
    visit[cur] = true;
    for (int i = 0; i < n + 2; i++)
    {
        if (pos_grid[cur][i] == 1 && !visit[i])
            dfs(i, pos_grid, visit, n);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<pair<int, int>> pos(n + 2);
        vector<bool> visit(n + 2, false);

        for (int i = 0; i < n + 2; i++)
        {
            cin >> pos[i].first >> pos[i].second;
        }

        vector<vector<int>> pos_grid = make_grid(n, pos);
        dfs(0, pos_grid, visit, n);

        if (visit[n + 1])
            cout << "happy" << '\n';
        else
            cout << "sad" << '\n';
    }

    return 0;
}