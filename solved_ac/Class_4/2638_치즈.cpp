#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

struct pos
{
    int y, x;
};
int paper[101][101];
bool visit[101][101];
int outAir[101][101];
int n, m;
int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> paper[i][j];
        }
    }
}

void spreadAir()
{
    queue<pos> q;
    q.push({0, 0});

    while (!q.empty())
    {
        pos cur = q.front();
        int y = cur.y;
        int x = cur.x;
        q.pop();
        if (visit[y][x])
            continue;
        visit[y][x] = true;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (paper[ny][nx] == 1)
                outAir[ny][nx]++;
            else if (!visit[ny][nx])
                q.push({ny, nx});
        }
    }
}

bool melt()
{
    bool isMelted = false;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (outAir[i][j] >= 2)
            {
                paper[i][j] = 0;
                isMelted = true;
            }
        }
    }
    return isMelted;
}

void solve()
{
    int t = 0;
    while (true)
    {
        memset(visit, 0, sizeof(visit));
        memset(outAir, 0, sizeof(outAir));

        spreadAir();
        bool isMelted = melt();
        if (isMelted)
            t++;
        else
            break;
    }
    cout << t << '\n';
}

int main()
{
    input();
    solve();

    return 0;
}