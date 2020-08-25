#include <string>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void bfs(vector<string> &village, int n)
{
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {-1, 0, 1, 0};

    queue<pair<int, int>> q;
    vector<int> vNum;
    int c_row, c_col, n_row, n_col;
    int cnt;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (village[i][j] == '1')
            {
                cnt = 0;
                q.push(make_pair(i, j));
                village[i][j] == '0';
                while (!q.empty())
                {
                    cnt++;
                    c_row = q.front().first;
                    c_col = q.front().second;
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        n_row = c_row + dr[i];
                        n_col = c_col + dc[i];
                        if ((0 <= n_row && n_row < n) && (0 <= n_col && n_col < n))
                        {
                            if (village[n_row][n_col] == '1')
                            {
                                village[n_row][n_col] = '0';
                                q.push(make_pair(n_row, n_col));
                            }
                        }
                    }
                }
                vNum.push_back(cnt);
            }
        }
    }
    sort(vNum.begin(), vNum.end());
    cout << vNum.size() << '\n';
    for (int i = 0; i < vNum.size(); i++)
    {
        if (vNum[i] != 1)
            cout << vNum[i] - 1 << '\n';
        else
            cout << 1 << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> village(n);
    for (int i = 0; i < n; i++)
        cin >> village[i];

    bfs(village, n);

    return 0;
}