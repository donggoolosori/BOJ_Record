#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 1001

using namespace std;

struct Node
{
    int y, x, isDrilled;
};
const int INF = 987654321;
int N, M;
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};
char maps[MAX][MAX];
int dist[MAX][MAX][2]; // 0은 벽을 뚫지 않은 상태, 1은 벽을 뚫은 상태

int bfs()
{
    int ret = INF;
    queue<Node> q;
    q.push({1, 1, 0});
    dist[1][1][0] = 1;

    while (!q.empty())
    {
        Node curr = q.front();
        int y = curr.y, x = curr.x, isDrilled = curr.isDrilled;
        q.pop();

        if (y == N && x == M)
            return dist[y][x][isDrilled];

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny <= 0 || nx <= 0 || ny > N || nx > M)
                continue;
            if (dist[ny][nx][isDrilled])
                continue;
            if (isDrilled && maps[ny][nx] == '1')
                continue;

            if (maps[ny][nx] == '1')
            {
                dist[ny][nx][1] = dist[y][x][0] + 1;
                q.push({ny, nx, true});
            }
            else
            {
                dist[ny][nx][isDrilled] = dist[y][x][isDrilled] + 1;
                q.push({ny, nx, isDrilled});
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> maps[i][j];

    cout << bfs();

    return 0;
}