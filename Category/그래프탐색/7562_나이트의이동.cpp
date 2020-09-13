#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dr[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int n;

int bfs(vector<vector<int>> &chess, int sr, int sc, int er, int ec)
{
    int cr, cc, nr, nc;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    chess[sr][sc] = 1;
    while (!q.empty())
    {
        cr = q.front().first;
        cc = q.front().second;
        if (cr == er && cc == ec)
        {
            return chess[cr][cc] - 1;
        }
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            nr = cr + dr[i];
            nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                continue;
            if (chess[nr][nc])
                continue;
            q.push({nr, nc});
            chess[nr][nc] = chess[cr][cc] + 1;
        }
    }
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<vector<int>> chess(n, vector<int>(n, 0));
        int fr_r, fr_c;
        int to_r, to_c;
        cin >> fr_r >> fr_c;
        cin >> to_r >> to_c;
        int res = bfs(chess, fr_r, fr_c, to_r, to_c);
        cout << res << '\n';
    }

    return 0;
}