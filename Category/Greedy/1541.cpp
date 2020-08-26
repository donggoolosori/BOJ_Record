#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void divideNumOp(string s, vector<int> &num, queue<char> &op)
{
    int i = 0;
    while (i < s.length())
    {
        string temp;
        if (s[i] == '+' || s[i] == '-')
        {
            op.push(s[i]);
            i++;
        }
        else
        {
            for (int j = i; j < i + 5; j++)
            {
                if (s[j] == '+' || s[j] == '-')
                    break;
                temp += s[j];
            }
            num.push_back(stoi(temp));
            i += (temp.length());
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    vector<int> num;
    queue<char> op;
    divideNumOp(s, num, op);

    int res = num[0];
    bool flag = false;
    for (int i = 1; i < num.size(); i++)
    {
        int cur_op = op.front();
        op.pop();
        if (flag)
            res -= num[i];
        else
        {
            if (cur_op == '-')
            {
                flag = true;
                res -= num[i];
            }
            else
                res += num[i];
        }
    }
    cout << res;
    return 0;
}
