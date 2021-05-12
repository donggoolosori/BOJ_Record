#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
string pascal[101][101];

string sum_string(string a, string b)
{
    int up = 0;
    string ret = "";

    while (!a.empty() || !b.empty() || up)
    {
        if (!a.empty())
        {
            up += a.back() - '0';
            a.pop_back();
        }
        if (!b.empty())
        {
            up += b.back() - '0';
            b.pop_back();
        }
        ret += (up % 10 + '0');
        up /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    pascal[0][0] = "1";
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                pascal[i][j] = "1";
            else
                pascal[i][j] = sum_string(pascal[i - 1][j - 1], pascal[i - 1][j]);
        }
    }
    cout << pascal[N][M] << '\n';
    return 0;
}