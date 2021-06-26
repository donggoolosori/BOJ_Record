#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};
vector<vector<int>> map(8, vector<int>(8));
int n, m;
int max_cnt = 0;

void spreadVirus(vector<vector<int>> &temp, int r, int c)
{
    int nr, nc;
    for (int i = 0; i < 4; i++)
    {
        nr = r + dr[i];
        nc = c + dc[i];
        if (0 <= nr && nr < n && 0 <= nc && nc < m && temp[nr][nc] == 0)
        {
            temp[nr][nc] = 2;
            spreadVirus(temp, nr, nc);
        }
    }
}

void countSafeArea()
{
    vector<vector<int>> temp(map);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] == 2)
            {
                spreadVirus(temp, i, j);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] == 0)
                cnt++;
        }
    }
    max_cnt = max(max_cnt, cnt);
}

void set_wall(int L)
{
    if (L == 3)
    {
        countSafeArea();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = 1;
                set_wall(L + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    set_wall(0);

    cout << max_cnt;

    return 0;
}