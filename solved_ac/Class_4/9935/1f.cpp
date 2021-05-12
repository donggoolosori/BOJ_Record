// string의 find, erase 사용
// 당연히 시간초과
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, exp_s;
    cin >> s >> exp_s;
    int exp_len = exp_s.length();

    while (true)
    {
        int idx = s.find(exp_s);
        if (idx == string::npos)
            break;
        s.erase(idx, exp_len);
    }

    if (s.length() == 0)
        cout << "FRULA" << '\n';
    else
        cout << s << '\n';
    return 0;
}