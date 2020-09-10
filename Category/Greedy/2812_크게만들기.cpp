#include <string>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string str_num;
    cin >> str_num;

    deque<char> dq;

    for (int i = 0; i < n; i++)
    {
        while (k && !dq.empty() && dq.back() < str_num[i])
        {
            dq.pop_back();
            k--;
        }
        dq.push_back(str_num[i]);
    }
    for (int i = 0; i < dq.size() - k; i++)
    {
        cout << dq[i];
    }

    return 0;
}