#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int stat[20][20];

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> stat[i][j];
}

int getSum(vector<int> &v)
{
    int ret = 0;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            if (i == j)
                continue;
            ret += stat[v[i]][v[j]];
        }
    }
    return ret;
}

bool isHalf(int x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if ((x & (1 << i)) != 0)
            cnt++;
    }
    if (cnt == n / 2)
        return true;
    return false;
}

int main()
{
    input();

    int answer = 987654321;

    for (int i = (1 << (n / 2)) - 1; i < (1 << n); i++)
    {
        vector<int> start, link;
        // 비트의 0과 1의 개수가 같지 않으면 continue
        if (!isHalf(i))
            continue;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) == 0)
                start.push_back(j);
            else
                link.push_back(j);
        }

        int startSum = getSum(start);
        int linkSum = getSum(link);
        answer = min(abs(startSum - linkSum), answer);
    }

    cout << answer << '\n';

    return 0;
}