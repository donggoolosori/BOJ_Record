#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

int N;
int ocean[20][20];
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};
struct Fish
{
    int y, x, dist;
};
queue<Fish> shark;

struct compare
{
    bool operator()(Fish a, Fish b)
    {
        if (a.dist == b.dist)
        {
            if (a.y == b.y)
                return a.x > b.x;
            return a.y > b.y;
        }
        return a.dist > b.dist;
    }
};

int getMaxTime()
{
    int time = 0, eat = 0, size = 2;

    while (true)
    {
        priority_queue<Fish, vector<Fish>, compare> feed;
        vector<vector<bool>> visit(N, vector<bool>(N));
        // bfs로 먹을 수 있는 먹이 모두 찾기
        while (!shark.empty())
        {
            Fish curr = shark.front();
            shark.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = curr.y + dy[i], nx = curr.x + dx[i];
                if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                    continue;
                if (visit[ny][nx] || ocean[ny][nx] > size)
                    continue;
                visit[ny][nx] = true;
                shark.push({ny, nx, curr.dist + 1});
                if (ocean[ny][nx] < size && ocean[ny][nx] != 0)
                    feed.push({ny, nx, curr.dist + 1});
            }
        }
        // feed가 비어있으면 break
        if (feed.empty())
            break;
        // 먹이 먹기
        Fish selected = feed.top();
        int feedY = selected.y, feedX = selected.x, feedSize = ocean[feedY][feedX];
        if (++eat == size)
        {
            eat = 0;
            size++;
        }
        // 먹이 위치로 이동
        ocean[feedY][feedX] = 0;
        shark.push({feedY, feedX, 0});

        time += selected.dist;
    }

    return time;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> ocean[i][j];
            if (ocean[i][j] == 9)
            {
                ocean[i][j] = 0;
                shark.push({i, j, 0});
            }
        }
    cout << getMaxTime() << '\n';

    return 0;
}