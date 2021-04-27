#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    string p;
    int n;
    while (T--)
    {
        deque<int> dq;
        cin >> p;
        cin >> n;
        string arr;
        cin >> arr;

        string temp;
        for (int i = 0; i < arr.length(); i++)
        {
            if (arr[i] == '[')
                continue;
            else if (arr[i] >= '0' && arr[i] <= '9')
            {
                temp += arr[i];
            }
            else if (arr[i] == ',' || arr[i] == ']')
            {
                if (!temp.empty())
                {
                    dq.push_back(stoi(temp));
                    temp.clear();
                }
            }
        }

        bool left = true;
        bool error = false;
        for (int i = 0; i < p.length(); i++)
        {
            if (p[i] == 'R')
            {
                left = !left;
            }
            else
            {
                if (dq.empty())
                {
                    error = true;
                    break;
                }
                else if (left)
                {
                    dq.pop_front();
                }
                else
                {
                    dq.pop_back();
                }
            }
        }
        if (error)
        {
            cout << "error" << '\n';
            continue;
        }
        cout << '[';
        while (!dq.empty())
        {
            if (left)
            {
                if (dq.size() == 1)
                    cout << dq.front();
                else
                    cout << dq.front() << ',';
                dq.pop_front();
            }
            else
            {
                if (dq.size() == 1)
                    cout << dq.back();
                else
                    cout << dq.back() << ',';
                dq.pop_back();
            }
        }
        cout << ']' << '\n';
    }
    return 0;
}
