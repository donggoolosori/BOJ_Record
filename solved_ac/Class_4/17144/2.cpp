#include <iostream>
#include <vector>

using namespace std;

int r, c, t;
int up_y, down_y;
int room[50][50];
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

void spreadDust()
{
    vector<vector<int>> sum(r, vector<int>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (room[i][j] == 0 || room[i][j] == -1)
                continue;
            for (int k = 0; k < 4; k++)
            {
                int ny = i + dy[k], nx = j + dx[k];
                if (ny < 0 || nx < 0 || ny >= r || nx >= c)
                    continue;
                if (room[ny][nx] == -1)
                    continue;
                sum[i][j] -= room[i][j] / 5;
                sum[ny][nx] += room[i][j] / 5;
            }
        }
    }
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            room[i][j] += sum[i][j];
}

void cycleAir()
{
    // 윗 부분 반시계방향 순환
    for (int i = up_y - 1; i > 0; i--)
        room[i][0] = room[i - 1][0];
    for (int i = 0; i < c - 1; i++)
        room[0][i] = room[0][i + 1];
    for (int i = 0; i < up_y; i++)
        room[i][c - 1] = room[i + 1][c - 1];
    for (int i = c - 1; i > 1; i--)
        room[up_y][i] = room[up_y][i - 1];
    room[up_y][1] = 0;
    // 아랫 부분 시계방향 순환
    for (int i = down_y + 1; i < r - 1; i++)
        room[i][0] = room[i + 1][0];
    for (int i = 0; i < c - 1; i++)
        room[r - 1][i] = room[r - 1][i + 1];
    for (int i = r - 1; i > down_y; i--)
        room[i][c - 1] = room[i - 1][c - 1];
    for (int i = c - 1; i > 1; i--)
        room[down_y][i] = room[down_y][i - 1];
    room[down_y][1] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> t;

    bool flag = false;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> room[i][j];
            if (!flag && room[i][j] == -1)
            {
                up_y = i, down_y = i + 1;
                flag = true;
            }
        }
    }

    while (t--)
    {
        // 미세먼지 확산
        spreadDust();
        // 공기순환
        cycleAir();
    }
    int amount = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (room[i][j] == -1)
                continue;
            amount += room[i][j];
        }
    }
    cout << amount << '\n';

    return 0;
}