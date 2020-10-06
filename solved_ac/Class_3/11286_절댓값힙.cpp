#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<long long int> plus;
    priority_queue<long long int> minus;

    int x;
    while (n--)
    {
        cin >> x;
        if (x == 0)
        {
            if (plus.empty() && minus.empty())
            {
                cout << 0 << '\n';
            }
            else if (plus.empty())
            {
                cout << minus.top() << '\n';
                minus.pop();
            }
            else if (minus.empty())
            {
                cout << -plus.top() << '\n';
                plus.pop();
            }
            else
            {
                if (plus.top() > minus.top())
                {
                    cout << -plus.top() << '\n';
                    plus.pop();
                }
                else
                {
                    cout << minus.top() << '\n';
                    minus.pop();
                }
            }
        }
        else if (x > 0)
        {
            plus.push(-x);
        }
        else
        {
            minus.push(x);
        }
    }

    return 0;
}