#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int channel, cLen;
vector<bool> button(10, true);
int ans;

void makeChannel(string num)
{
    if (num.length() > 6)
        return;
    for (int i = 0; i < 10; i++)
    {
        if (!button[i])
            continue;
        string next = num + to_string(i);
        ans = min(ans, int(next.length()) + abs(stoi(next) - channel));
        makeChannel(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M, a;
    cin >> channel >> M;
    ans = abs(channel - 100);
    cLen = to_string(channel).length();

    // 고장 난 버튼 체크
    while (M--)
    {
        cin >> a;
        button[a] = false;
    }

    // 만들 수 있는 버튼 완전 탐색
    makeChannel("");
    cout << ans << '\n';
    return 0;
}