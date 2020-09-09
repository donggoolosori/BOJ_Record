#include <iostream>
#include <vector>

using namespace std;

int w, h;
int dr[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dc[] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool checkRange(int nr, int nc)
{
    return (0 <= nr && nr < h && 0 <= nc && nc < w);
}
void dfs(vector<vector<int>> &map, int r, int c)
{
    map[r][c] = 0;
    int nr, nc;
    for (int i = 0; i < 8; i++)
    {
        nr = r + dr[i];
        nc = c + dc[i];
        if (checkRange(nr, nc) && map[nr][nc] == 1)
        {
            dfs(map, nr, nc);
        }
    }
}
int main()
{
    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        int cnt = 0;
        vector<vector<int>> map(h, vector<int>(w));

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
            }
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (map[i][j] == 1)
                {
                    cnt++;
                    dfs(map, i, j);
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}