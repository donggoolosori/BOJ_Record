#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<string> maps(25);
vector<vector<bool>> visit(25, vector<bool>(25));
int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

int countHouses(int y, int x, const char &cls)
{
    visit[y][x] = true;

    int cnt = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N || visit[ny][nx])
            continue;
        if (maps[ny][nx] != cls)
            continue;
        cnt += countHouses(ny, nx, cls);
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> maps[i];

    int total = 0;
    vector<int> vill;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visit[i][j] || maps[i][j] == '0')
                continue;
            total++;

            vill.push_back(countHouses(i, j, maps[i][j]));
        }
    }
    sort(vill.begin(), vill.end());
    cout << total << '\n';
    for (const auto &v : vill)
        cout << v << '\n';

    return 0;
}