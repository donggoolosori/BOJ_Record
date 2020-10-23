#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    string s;
    vector<int> words(n);
    for (auto &w : words)
    {
        cin >> s;
        for (auto &c : s)
        {
            w |= 1 << (c - 'a');
        }
    }

    int fullBit = 0x3ffffff; // 26개의 비트가 모두 1로 채워져있다. -> 모두 암기한 상태
    int o;
    char x;
    while (m--)
    {
        cin >> o >> x;
        // 알파벳 잊음
        if (o == 1)
            fullBit &= ~(1 << (x - 'a'));
        // 알파벳 기억함
        else
            fullBit |= (1 << (x - 'a'));

        int ans = 0;
        for (auto &w : words)
        {
            if ((fullBit & w) == w)
                ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}