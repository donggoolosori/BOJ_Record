#include <iostream>
#include <cstring>

using namespace std;

int N;
char picture[100][100];
bool visit[100][100];
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

void countRegion(const int &check, int y, int x)
{
    visit[y][x] = true;
    char color = picture[y][x];

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N || visit[ny][nx])
            continue;
        char nextColor = picture[ny][nx];

        if (color != nextColor)
        {
            if (!check || color == 'B' || nextColor == 'B')
                continue;
            countRegion(check, ny, nx);
        }
        else
            countRegion(check, ny, nx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> picture[i][j];

    // 적록색약 구역 카운트
    int cnt1 = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (visit[i][j])
                continue;
            cnt1++;
            countRegion(1, i, j);
        }

    memset(visit, 0, sizeof(visit));
    // 정상 구역 카운트
    int cnt2 = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (visit[i][j])
                continue;
            cnt2++;
            countRegion(0, i, j);
        }

    cout << cnt2 << ' ' << cnt1 << '\n';

    return 0;
}