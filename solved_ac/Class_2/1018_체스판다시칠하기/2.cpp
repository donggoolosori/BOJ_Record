#include <iostream>
#include <algorithm>

using namespace std;

string white[8] = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};
string black[8] = {"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};
string board[50];
int n, m;

int getNumOfDiff(int y, int x)
{
    int whiteDiff = 0, blackDiff = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (white[i][j] != board[y + i][x + j])
                whiteDiff++;
            if (black[i][j] != board[y + i][x + j])
                blackDiff++;
        }
    }
    return min(whiteDiff, blackDiff);
}

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i];
}

int main()
{
    input();
    int answer = 2500;

    for (int i = 0; i <= n - 8; i++)
        for (int j = 0; j <= m - 8; j++)
            answer = min(answer, getNumOfDiff(i, j));

    cout << answer << '\n';
    return 0;
}