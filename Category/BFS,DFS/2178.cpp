#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};

void bfs(vector<string> &maze, int n, int m)
{
    vector<vector<int>> cntMtx(n, vector<int>(m, 0));
    cntMtx[0][0] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        int c_row = q.front().first;
        int c_col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int n_row = c_row + dr[i];
            int n_col = c_col + dc[i];
            if ((0 <= n_row && n_row < n) && (0 <= n_col && n_col < m))
            {
                if (maze[n_row][n_col] == '1' && cntMtx[n_row][n_col] == 0)
                {
                    cntMtx[n_row][n_col] = cntMtx[c_row][c_col] + 1;
                    q.push(make_pair(n_row, n_col));
                }
            }
        }
    }
    cout << cntMtx[n - 1][m - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> maze(n);
    for (int i = 0; i < n; i++)
        cin >> maze[i];
    bfs(maze, n, m);
    return 0;
}