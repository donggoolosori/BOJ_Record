// 스택 사용
// 시간 초과
#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Node
{
    int cnt;
    char ch;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, bomb;
    cin >> s >> bomb;
    int bLen = bomb.length();

    stack<Node> stk;

    for (int i = 0; i < s.length(); i++)
    {
        if (!stk.empty() && s[i] == bomb[stk.top().cnt])
        {
            if (stk.top().cnt + 1 == bLen)
                for (int i = 0; i < bLen - 1; i++)
                    stk.pop();
            else
                stk.push({stk.top().cnt + 1, s[i]});
        }
        else
        {
            if (s[i] == bomb[0])
                stk.push({1, s[i]});
            else
                stk.push({0, s[i]});
        }
    }
    string answer = "";
    while (!stk.empty())
    {
        answer = stk.top().ch + answer;
        stk.pop();
    }

    if (answer.length() == 0)
        cout << "FRULA" << '\n';
    else
        cout << answer << '\n';
    return 0;
}