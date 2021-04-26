#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    string temp = "";
    bool flag = false;

    int result = 0;

    // -가 나온 순간부터 나오는 모든 수는 빼주면 됨
    for (const char &ch : s)
    {
        if (!isdigit(ch))
        {
            int num = stoi(temp);
            temp = "";
            if (flag)
                result -= num;
            else
            {
                result += num;
                if (ch == '-')
                    flag = true;
            }
        }
        else
            temp += ch;
    }
    if (flag)
        result -= stoi(temp);
    else
        result += stoi(temp);

    cout << result << '\n';

    return 0;
}