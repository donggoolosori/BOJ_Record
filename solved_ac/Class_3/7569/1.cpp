#include <iostream>
#include <queue>

using namespace std;

int dz[] = {-1, 0, 0, 0, 0, 1};
int dy[] = {0, -1, 0, 0, 1, 0};
int dx[] = {0, 0, -1, 1, 0, 0};
int box[100][100][100];
int N, M, H;
struct Tomato
{
    int z, y, x;
};
queue<Tomato> q;

int getMinDay()
{
    int ret = 0;

    while (!q.empty())
    {
        Tomato curr = q.front();
        int z = curr.z, y = curr.y, x = curr.x;
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nz = z + dz[i], ny = y + dy[i], nx = x + dx[i];
            if (nz < 0 || ny < 0 || nx < 0 || nz >= H || ny >= N || nx >= M)
                continue;
            if (box[nz][ny][nx] != 0)
                continue;
            box[nz][ny][nx] = box[z][y][x] + 1;
            ret = max(ret, box[nz][ny][nx]);
            q.push({nz, ny, nx});
        }
    }
    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
                if (box[i][j][k] == 0)
                    return -1;
    return ret == 0 ? 0 : ret - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
            {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1)
                    q.push({i, j, k});
            }
    cout << getMinDay() << '\n';

    return 0;
}