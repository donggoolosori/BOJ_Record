#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

// 비의 높이보다 높은 곳을 1로 설정
void afterRain(int n, int rainH, vector<vector<int>> &map, vector<vector<int>> &tempMap)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] > rainH)
                tempMap[i][j] = 1;
        }
    }
}
// dfs함수
void dfs(vector<vector<int>> &tempMap, int n, int r, int c)
{
    int nr, nc;
    for (int i = 0; i < 4; i++)
    {
        nr = r + dr[i];
        nc = c + dc[i];
        if ((0 <= nr && nr < n) && (0 <= nc && nc < n))
        {
            if (tempMap[nr][nc] == 1)
            {
                tempMap[nr][nc] = 0;
                dfs(tempMap, n, nr, nc);
            }
        }
    }
}
// safe zone 개수 세기
int countSafeZone(int n, vector<vector<int>> &tempMap)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tempMap[i][j] == 1)
            {
                cnt++;
                tempMap[i][j] = 0;
                dfs(tempMap, n, i, j);
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));

    int minH = 101;
    int maxH = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            minH = min(minH, map[i][j]);
            maxH = max(maxH, map[i][j]);
        }
    }
    int res = 0;
    for (int rainH = minH - 1; rainH < maxH; rainH++)
    {
        vector<vector<int>> tempMap(n, vector<int>(n, 0));
        // 비의 높이보다 높은 곳을 1로 설정하는 함수호출
        afterRain(n, rainH, map, tempMap);
        // safe zone 개수 세기
        res = max(res, countSafeZone(n, tempMap));
    }
    cout << res;

    return 0;
}