#include <iostream>
#include <string>
#include <deque>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string order;
    queue<int> q;
    while (n--)
    {
        cin >> order;
        if (order == "push")
        {
            int a;
            cin >> a;
            q.push(a);
        }
        else if (order == "pop")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
            {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (order == "size")
        {
            cout << q.size() << '\n';
        }
        else if (order == "empty")
        {
            if (q.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (order == "front")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.front() << '\n';
        }
        else if (order == "back")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
            {
                cout << q.back() << '\n';
            }
        }
    }
    return 0;
}