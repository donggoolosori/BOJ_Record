#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

unordered_map<char, int> op_power;
stack<char> op_stk;
string infix, postfix = "";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 연산자 우선순위 설정
    op_power['-'] = 1, op_power['+'] = 1, op_power['*'] = 2, op_power['/'] = 2;

    cin >> infix;

    for (const auto &ch : infix)
    {
        if (ch >= 'A' && ch <= 'Z')
            postfix += ch;
        else
        {
            if (ch == '(')
                op_stk.push(ch);
            else if (ch == ')')
            {
                while (!op_stk.empty() && op_stk.top() != '(')
                {
                    postfix += op_stk.top();
                    op_stk.pop();
                }
                op_stk.pop();
            }
            else if (op_power[ch] == 2)
            {
                while (!op_stk.empty() && op_power[op_stk.top()] == 2)
                {
                    postfix += op_stk.top();
                    op_stk.pop();
                }
                op_stk.push(ch);
            }
            else if (op_power[ch] == 1)
            {
                while (!op_stk.empty() && op_stk.top() != '(')
                {
                    postfix += op_stk.top();
                    op_stk.pop();
                }
                op_stk.push(ch);
            }
        }
    }
    while (!op_stk.empty())
    {
        postfix += op_stk.top();
        op_stk.pop();
    }

    cout << postfix << '\n';

    return 0;
}