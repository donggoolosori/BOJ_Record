#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> lab(8, vector<int>(8));
int ans;
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

int coutSafeZone(vector<vector<int>> &vec)
{
    int ret = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (vec[i][j] == 0)
                ret++;
    return ret;
}

void spreadVirus(vector<vector<int>> &vec, int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M || vec[ny][nx] != 0)
            continue;
        vec[ny][nx] = 2;
        spreadVirus(vec, ny, nx);
    }
}

void buildWall(int L)
{
    // 방화벽 3개를 모두 세움
    if (L == 3)
    {
        // 바이러스 퍼짐
        vector<vector<int>> vec(lab);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (vec[i][j] == 2)
                    spreadVirus(vec, i, j);
        // 안전구역 세기
        ans = max(ans, coutSafeZone(vec));

        return;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (lab[i][j] == 0)
            {
                lab[i][j] = 1;
                buildWall(L + 1);
                lab[i][j] = 0;
            }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> lab[i][j];

    buildWall(0);
    cout << ans << '\n';

    return 0;
}