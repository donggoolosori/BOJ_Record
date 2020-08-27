#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};

void bfs(int r, int c, vector<vector<int>> &iceMap, vector<vector<int>> &visit)
{
    int cr, cc;
    int nr, nc;
    queue<pair<int, int>> q;
    q.push({r, c});
    visit[r][c] = 1;
    while (!q.empty())
    {
        cr = q.front().first;
        cc = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            nr = cr + dr[i];
            nc = cc + dc[i];
            if (iceMap[nr][nc] != 0 && !visit[nr][nc])
            {
                visit[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }
}
int countIce(int n, int m, vector<vector<int>> &iceMap)
{
    int cnt = 0;
    vector<vector<int>> visit(n, vector<int>(m, 0));

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (iceMap[i][j] != 0 && !visit[i][j])
            {
                cnt++;
                bfs(i, j, iceMap, visit);
            }
        }
    }
    return cnt;
}
int checkAround(int r, int c, vector<vector<int>> &iceMap)
{
    int cnt = 0;
    int nr, nc;
    for (int i = 0; i < 4; i++)
    {
        nr = r + dr[i];
        nc = c + dc[i];
        if (iceMap[nr][nc] == 0)
            cnt++;
    }
    return cnt;
}
void iceMelting(int n, int m, vector<vector<int>> &iceMap)
{
    queue<pair<int, pair<int, int>>> melt_q;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            // 빙산일 경우 녹는 정도 큐에 저장
            if (iceMap[i][j] != 0)
                melt_q.push({checkAround(i, j, iceMap), {i, j}});
        }
    }
    int mr, mc, melt;
    while (!melt_q.empty())
    {
        melt = melt_q.front().first;
        mr = melt_q.front().second.first;
        mc = melt_q.front().second.second;
        melt_q.pop();
        iceMap[mr][mc] -= melt;
        iceMap[mr][mc] = iceMap[mr][mc] < 0 ? 0 : iceMap[mr][mc];
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> iceMap(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> iceMap[i][j];
        }
    }
    int cnt;
    int year = 0;
    while (true)
    {
        cnt = countIce(n, m, iceMap);
        if (cnt >= 2)
        {
            cout << year;
            return 0;
        }
        if (cnt == 0)
        {
            cout << 0;
            return 0;
        }
        iceMelting(n, m, iceMap);
        year++;
    }

    return 0;
}