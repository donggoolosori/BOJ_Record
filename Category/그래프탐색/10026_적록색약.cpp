#include <vector>
#include <iostream>

using namespace std;
int n;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};
void dfs(vector<vector<char>> &map, char color, int r, int c, bool rgb)
{
    int nr, nc;
    for (int i = 0; i < 4; i++)
    {
        nr = r + dr[i];
        nc = c + dc[i];

        if (0 <= nr && nr < n && 0 <= nc && nc < n && map[nr][nc] != 'v')
        {
            if (!rgb)
            {
                if (map[nr][nc] == color)
                {
                    map[nr][nc] = 'v';
                    dfs(map, color, nr, nc, rgb);
                }
            }
            else
            {
                if (color == 'R' || color == 'G')
                {
                    if (map[nr][nc] == 'R' || map[nr][nc] == 'G')
                    {
                        map[nr][nc] = 'v';
                        dfs(map, color, nr, nc, rgb);
                    }
                }
                else
                {
                    if (map[nr][nc] == color)
                    {
                        map[nr][nc] = 'v';
                        dfs(map, color, nr, nc, rgb);
                    }
                }
            }
        }
    }
}
int main()
{
    cin >> n;
    vector<vector<char>> origin(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> origin[i][j];
        }
    }
    vector<vector<char>> normal(origin);
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (normal[i][j] != 'v')
            {
                cnt1++;
                char color = normal[i][j];
                normal[i][j] = 'v';
                dfs(normal, color, i, j, false);
            }
        }
    }

    vector<vector<char>> rg(origin);
    int cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rg[i][j] != 'v')
            {
                cnt2++;
                char color = rg[i][j];
                rg[i][j] = 'v';
                dfs(rg, color, i, j, true);
            }
        }
    }
    cout << cnt1 << ' ' << cnt2 << '\n';

    return 0;
}