#include <iostream>
#include <algorithm>

using namespace std;

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

int board[500][500], visit[500][500];
int MAX;
int N, M;

void findFuckShapeMax(int y, int x)
{
    // ㅜ
    if (y + 1 < N && x + 2 < M)
        MAX = max(MAX, board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y + 1][x + 1]);
    // ㅏ
    if (y + 2 < N && x + 1 < M)
        MAX = max(MAX, board[y][x] + board[y + 1][x] + board[y + 1][x + 1] + board[y + 2][x]);
    // ㅗ
    if (y - 1 >= 0 && x + 2 < M)
        MAX = max(MAX, board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y - 1][x + 1]);
    // ㅓ
    if (y + 2 < N && x - 1 >= 0)
        MAX = max(MAX, board[y][x] + board[y + 1][x] + board[y + 1][x - 1] + board[y + 2][x]);
}

void findNormalMax(int L, int sum, int y, int x)
{
    if (L == 3)
    {
        MAX = max(MAX, sum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if (visit[ny][nx])
            continue;
        visit[ny][nx] = true;
        findNormalMax(L + 1, sum + board[ny][nx], ny, nx);
        visit[ny][nx] = false;
    }
}

void findMax(int y, int x)
{
    findFuckShapeMax(y, x);

    visit[y][x] = true;
    findNormalMax(0, board[y][x], y, x);
    visit[y][x] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            findMax(i, j);

    cout << MAX << '\n';

    return 0;
}