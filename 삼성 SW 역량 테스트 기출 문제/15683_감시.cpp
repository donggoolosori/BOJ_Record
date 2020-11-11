#include <iostream>
#include <vector>
#define min(a, b) a < b ? a : b

using namespace std;

struct Node
{
    int r, c, num;
};
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int n, m;
vector<vector<int>> office(8, vector<int>(8));
vector<Node> cctv;
int ans = 100; // 사각지대의 최소 개수

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
            cin >> office[i][j];
            if (office[i][j] >= 1 && office[i][j] <= 5)
                cctv.push_back({i, j, office[i][j]});
        }
    }
}

int getBlindSpots(vector<vector<int>> v)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

vector<vector<int>> setWatchSpots(vector<vector<int>> temp, int d, int r, int c)
{
    // 북쪽
    if (d == 0)
    {
        for (int i = r; i >= 0; i--)
        {
            if (temp[i][c] == 6)
                break;
            else if (temp[i][c] == 0)
            {
                temp[i][c] = -1;
            }
        }
    }
    // 동쪽
    if (d == 1)
    {
        for (int i = c; i < m; i++)
        {
            if (temp[r][i] == 6)
                break;
            else if (temp[r][i] == 0)
            {
                temp[r][i] = -1;
            }
        }
    }
    // 남쪽
    if (d == 2)
    {
        for (int i = r; i < n; i++)
        {
            if (temp[i][c] == 6)
                break;
            else if (temp[i][c] == 0)
            {
                temp[i][c] = -1;
            }
        }
    }
    // 서쪽
    if (d == 3)
    {
        for (int i = c; i >= 0; i--)
        {
            if (temp[r][i] == 6)
                break;
            else if (temp[r][i] == 0)
            {
                temp[r][i] = -1;
            }
        }
    }
    return temp;
}

void dfs(int L, vector<vector<int>> office)
{
    if (L == cctv.size())
    {
        ans = min(ans, getBlindSpots(office));
        return;
    }

    vector<vector<int>> temp;

    if (cctv[L].num == 1)
    {
        for (int i = 0; i < 4; i++)
            dfs(L + 1, setWatchSpots(office, i, cctv[L].r, cctv[L].c));
    }
    else if (cctv[L].num == 2)
    {
        temp = setWatchSpots(office, 0, cctv[L].r, cctv[L].c);
        temp = setWatchSpots(temp, 2, cctv[L].r, cctv[L].c);
        dfs(L + 1, temp);
        temp = setWatchSpots(office, 1, cctv[L].r, cctv[L].c);
        temp = setWatchSpots(temp, 3, cctv[L].r, cctv[L].c);
        dfs(L + 1, temp);
    }
    else if (cctv[L].num == 3)
    {
        for (int i = 0; i < 4; i++)
        {
            temp = office;
            if (i == 3)
            {
                temp = setWatchSpots(temp, 0, cctv[L].r, cctv[L].c);
                temp = setWatchSpots(temp, 3, cctv[L].r, cctv[L].c);
                dfs(L + 1, temp);
            }
            else
            {
                temp = setWatchSpots(temp, i, cctv[L].r, cctv[L].c);
                temp = setWatchSpots(temp, i + 1, cctv[L].r, cctv[L].c);
                dfs(L + 1, temp);
            }
        }
    }
    else if (cctv[L].num == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            temp = office;
            for (int j = 0; j < 4; j++)
            {
                if (i == j)
                    continue;
                temp = setWatchSpots(temp, j, cctv[L].r, cctv[L].c);
            }
            dfs(L + 1, temp);
        }
    }
    else if (cctv[L].num == 5)
    {
        temp = office;
        for (int i = 0; i < 4; i++)
            temp = setWatchSpots(temp, i, cctv[L].r, cctv[L].c);
        dfs(L + 1, temp);
    }
}

void solve()
{
    dfs(0, office);
    cout << ans << '\n';
}

int main()
{
    input();
    solve();

    return 0;
}