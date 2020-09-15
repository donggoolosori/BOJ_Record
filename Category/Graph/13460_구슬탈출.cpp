#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct balls
{
    int depth;
    int rx, ry, bx, by;
};

int irx, iry, ibx, iby, hx, hy;
int n, m, ans = -1;
char board[10][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool visit[10][10][10][10];

void move(int &x, int &y, int d)
{
    while (1)
    {
        x += dx[d];
        y += dy[d];
        if (board[y][x] == '#')
        {
            x -= dx[d];
            y -= dy[d];
            break;
        }
        else if (board[y][x] == 'O')
            break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                iry = i;
                irx = j;
            }
            else if (board[i][j] == 'B')
            {
                iby = i;
                ibx = j;
            }
            else if (board[i][j] == 'O')
            {
                hy = i;
                hx = j;
            }
        }
    }
    queue<balls> q;
    q.push({0, irx, iry, ibx, iby});
    visit[iry][irx][iby][ibx] = true;

    while (!q.empty())
    {
        balls cur = q.front();
        q.pop();
        if (cur.depth > 10)
            break;
        if (cur.rx == hx && cur.ry == hy)
        {
            ans = cur.depth;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int rx = cur.rx;
            int ry = cur.ry;
            int bx = cur.bx;
            int by = cur.by;
            move(rx, ry, i);
            move(bx, by, i);

            if (bx == hx && by == hy)
                continue;
            if (rx == bx && ry == by)
            {
                switch (i)
                {
                case 0:
                    cur.rx < cur.bx ? bx++ : rx++;
                    break;
                case 1:
                    cur.ry < cur.by ? by++ : ry++;
                    break;
                case 2:
                    cur.rx < cur.bx ? rx-- : bx--;
                    break;
                case 3:
                    cur.ry < cur.by ? ry-- : by--;
                    break;
                }
            }
            if (!visit[ry][rx][by][bx])
            {
                balls next = {cur.depth + 1, rx, ry, bx, by};
                q.push(next);
                visit[ry][rx][by][bx] = true;
            }
        }
    }
    cout << ans;

    return 0;
}