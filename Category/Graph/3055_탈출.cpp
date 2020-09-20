#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct position
{
    int y, x;
};
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
int r, c;
char map[50][50]; // 빈 곳 . , 물 * , 돌 X, 고슴도치 S, 굴 D
int visit[50][50];
int w_time[50][50];
queue<position> water_q;
queue<position> hog_q;
position cave;

void input()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == '*')
            {
                water_q.push({i, j});
            }
            else if (map[i][j] == 'S')
            {
                hog_q.push({i, j});
            }
            else if (map[i][j] == 'D')
            {
                cave.y = i;
                cave.x = j;
            }
        }
    }
}

void water_bfs()
{
    while (!water_q.empty())
    {
        int cur_y = water_q.front().y;
        int cur_x = water_q.front().x;
        water_q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            if (next_y < 0 || next_y > r || next_x < 0 || next_x > c)
                continue;
            if (w_time[next_y][next_x] == 0 && map[next_y][next_x] == '.')
            {
                w_time[next_y][next_x] = w_time[cur_y][cur_x] + 1;
                water_q.push({next_y, next_x});
            }
        }
    }
}
void moving_bfs()
{
    while (!hog_q.empty())
    {
        int y = hog_q.front().y;
        int x = hog_q.front().x;
        hog_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny > r || nx < 0 || nx > c)
                continue;
            if (visit[ny][nx] == 0 && (map[ny][nx] == '.' || map[ny][nx] == 'D'))
            {
                if (w_time[ny][nx] == 0)
                {
                    visit[ny][nx] = visit[y][x] + 1;
                    hog_q.push({ny, nx});
                }
                else
                {
                    if (w_time[ny][nx] > visit[y][x] + 1)
                    {
                        visit[ny][nx] = visit[y][x] + 1;
                        hog_q.push({ny, nx});
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    water_bfs();
    moving_bfs();

    if (visit[cave.y][cave.x])
    {
        cout << visit[cave.y][cave.x];
    }
    else
    {
        cout << "KAKTUS";
    }

    return 0;
}