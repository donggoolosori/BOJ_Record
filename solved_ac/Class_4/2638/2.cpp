#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, cheese;
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};
int map[101][101], visit[101][101];
struct Node
{
    int y, x;
};

void bfs()
{
    vector<vector<int>> check(N, vector<int>(M));
    queue<Node> q;
    q.push({0, 0});
    visit[0][0] = true;

    while (!q.empty())
    {
        int y = q.front().y, x = q.front().x;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx])
                continue;
            if (map[ny][nx] == 1)
            {
                check[ny][nx]++;
                continue;
            }
            visit[ny][nx] = true;
            q.push({ny, nx});
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (check[i][j] < 2)
                continue;
            map[i][j] = 0;
            cheese--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            cheese += map[i][j];
        }
    }

    int t = 0;
    while (++t)
    {
        bfs();
        memset(visit, 0, sizeof(visit));
        if (cheese == 0)
            break;
    }
    cout << t << '\n';

    return 0;
}