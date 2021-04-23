#include <iostream>
#include <queue>

using namespace std;

int M, N;
int box[1000][1000];
bool visit[1000][1000];
struct Tomato
{
    int y, x;
};
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

int getMinDay(queue<Tomato> &q)
{
    while (!q.empty())
    {
        Tomato curr = q.front();
        visit[curr.y][curr.x] = true;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = curr.y + dy[i], nx = curr.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx])
                continue;
            if (box[ny][nx] != 0)
                continue;
            box[ny][nx] = box[curr.y][curr.x] + 1;
            q.push({ny, nx});
        }
    }
    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (box[i][j] == 0)
                return -1;
            ret = max(ret, box[i][j]);
        }
    }
    return ret - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<Tomato> q;

    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
                q.push({i, j});
        }
    }
    cout << getMinDay(q) << '\n';

    return 0;
}