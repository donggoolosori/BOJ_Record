#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(vector<vector<int>> bsb, string num)
{
    int strike, ball;
    string stand;
    for (int i = 0; i < bsb.size(); i++)
    {
        strike = ball = 0;
        stand = to_string(bsb[i][0]);

        for (int j = 0; j < 3; j++)
        {
            // strike count
            if (stand[j] == num[j])
                strike++;
            // ball count
            for (int k = 0; k < 3; k++)
            {
                if (j == k)
                    continue;
                if (stand[j] == num[k])
                    ball++;
            }
        }
        if (strike != bsb[i][1] || ball != bsb[i][2])
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int cnt = 0;
    vector<vector<int>> bsb(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> bsb[i][j];

    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            for (int k = 1; k < 10; k++)
            {
                if (i == j || j == k || k == i)
                    continue;
                int num = i * 100 + j * 10 + k;
                if (check(bsb, to_string(num)))
                    cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}