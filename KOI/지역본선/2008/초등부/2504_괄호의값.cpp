#include <string>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;

    string cur;
    stack<string> stk;
    for (int i = 0; i < input.size(); i++)
    {
        cur = input.at(i);
        if (cur == "(" || cur == "[")
            stk.push(cur);
        else
        {
            int temp = 1;
            // 괄호사이의 숫자들 곱해주기
            while (!stk.empty() && stk.top() != "(" && stk.top() != "[")
            {
                temp *= stoi(stk.top());
                stk.pop();
            }
            // 불가능한 경우
            if (stk.empty() || (cur == ")" && stk.top() != "(") || (cur == "]" && stk.top() != "["))
            {
                cout << 0;
                return 0;
            }
            if (cur == ")")
                temp *= 2;
            else
                temp *= 3;
            stk.pop();
            // 스택에서 앞이 숫자라면 덧셈
            while (!stk.empty() && stk.top() != "(" && stk.top() != "[")
            {
                temp += stoi(stk.top());
                stk.pop();
            }
            stk.push(to_string(temp));
        }
    }
    // (,[ 가 마지막에 푸쉬되는 경우 고려
    if (stk.size() != 1)
        cout << 0;
    else
    {
        cout << stk.top();
    }

    return 0;
}