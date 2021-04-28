#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPi(string p)
{
    // j: 패턴의 인덱스
    int m = p.size(), j = 0;
    vector<int> pi(m);
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

int kmp(string s, string p)
{
    int ret = 0;
    vector<int> pi = getPi(p);
    int n = s.size(), m = p.size(), j = 0;

    for (int i = 0; i < n; i++)
    {
        while (j > 0 && s[i] != p[j])
            j = pi[j - 1];
        if (s[i] == p[j])
        {
            if (j == m - 1)
            {
                j = pi[j];
                ret++;
            }
            else
                j++;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string s, p = "";
    // 입력
    cin >> N >> M >> s;
    // 패턴 생성
    for (int i = 0; i < N; i++)
        p += "IO";
    p += "I";
    // kmp 알고리즘
    cout << kmp(s, p) << '\n';

    return 0;
}