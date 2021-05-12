// 12ms
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, bomb, answer = "";
    cin >> s >> bomb;
    int bLen = bomb.length();

    for (int i = 0; i < s.length(); i++)
    {
        answer += s[i];
        if (answer.back() != bomb.back())
            continue;
        if (answer.length() < bLen)
            continue;

        int bIdx = bLen - 1, cnt = 1;
        if (answer.substr(answer.length() - bLen, bLen) == bomb)
            answer.erase(answer.length() - bLen);
    }

    if (answer.length() == 0)
        cout << "FRULA" << '\n';
    else
        cout << answer << '\n';
    return 0;
}