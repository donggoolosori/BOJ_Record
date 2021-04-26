#include <iostream>
#include <vector>

using namespace std;

int N;
int answer[3];

void cutPaper(vector<vector<int>> &paper, int y, int x, int size)
{
    int curr = paper[y][x];
    int nextSize = size / 3;
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (paper[i][j] != curr)
            {
                for (int k = 0; k < 3; k++)
                    for (int l = 0; l < 3; l++)
                        cutPaper(paper, y + nextSize * k, x + nextSize * l, nextSize);
                return;
            }
        }
    }
    answer[curr + 1]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<vector<int>> paper(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];

    cutPaper(paper, 0, 0, N);
    for (int cnt : answer)
        cout << cnt << '\n';
    return 0;
}