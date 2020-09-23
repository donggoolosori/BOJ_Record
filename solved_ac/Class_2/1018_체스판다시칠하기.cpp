#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string white[8] = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};
string black[8] = {"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};
string input[50];
int n, m;
int ans = 2500;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> input[i];

    for (int i = 0; i < n - 7; i++)
    {
        for (int j = 0; j < m - 7; j++)
        {
            int cnt_black = 0;
            int cnt_white = 0;
            for (int r = 0; r < 8; r++)
            {
                for (int c = 0; c < 8; c++)
                {
                    if (white[r][c] != input[i + r][j + c])
                        cnt_white++;
                    if (black[r][c] != input[i + r][j + c])
                        cnt_black++;
                }
            }
            ans = min(ans, min(cnt_white, cnt_black));
        }
    }

    cout << ans << '\n';
    return 0;
}