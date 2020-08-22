#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int checkSimilar(int *s, int *c)
{

    int cntDiff = 0;
    int f = -1;
    for (int i = 0; i < 26; i++)
    {
        // 차이가 2 이상인 경우 x
        if (abs(s[i] - c[i]) > 1)
            return 0;
        // 갯수가 서로 다른 경우 카운트
        if (s[i] != c[i])
        {
            if (f == -1)
                f = i;
            cntDiff += 1;
            // 갯수 차 2개 이상일 때
            if (cntDiff == 2 && s[f] + s[i] != c[f] + c[i])
                return 0;
            // 갯수가 다른 것이 3개 이상일 경우 x
            if (cntDiff > 2)
                return 0;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int idx;
    int n;
    cin >> n;

    string standard;
    cin >> standard;

    int s_alp[26] = {0};
    for (int i = 0; i < standard.length(); i++)
    {
        idx = standard[i] - 65;
        s_alp[idx]++;
    }

    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        string comp;
        cin >> comp;
        int c_alp[26] = {0};
        for (int j = 0; j < comp.length(); j++)
        {
            idx = comp[j] - 65;
            c_alp[idx]++;
        }
        cnt += checkSimilar(s_alp, c_alp);
    }

    cout << cnt;
    return 0;
}