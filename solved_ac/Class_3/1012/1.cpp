#include <iostream>
#include <vector>

using namespace std;

int M, N;
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

void dfs(vector<vector<int>> &land, int y, int x)
{
    land[y][x] = 0;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if (land[ny][nx] == 0)
            continue;

        dfs(land, ny, nx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, K;
    cin >> T;

    while (T--)
    {
        cin >> M >> N >> K;
        int x, y;
        vector<vector<int>> land(N, vector<int>(M));

        while (K--)
        {
            cin >> x >> y;
            land[y][x] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (land[i][j] == 0)
                    continue;
                cnt++;
                dfs(land, i, j);
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}