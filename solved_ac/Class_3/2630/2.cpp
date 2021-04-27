#include <iostream>

using namespace std;

int answer[2];
int paper[128][128];
int N;

void makeColorPaper(int y, int x, int size)
{
    int curr = paper[y][x];

    for (int i = y; i < y + size; i++)
        for (int j = x; j < x + size; j++)
            if (paper[i][j] != curr)
            {
                makeColorPaper(y, x, size / 2);
                makeColorPaper(y, x + size / 2, size / 2);
                makeColorPaper(y + size / 2, x, size / 2);
                makeColorPaper(y + size / 2, x + size / 2, size / 2);
                return;
            }
    answer[curr]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];

    makeColorPaper(0, 0, N);
    cout << answer[0] << '\n'
         << answer[1];
    return 0;
}