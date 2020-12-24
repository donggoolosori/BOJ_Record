#include <iostream>
#include <deque>

using namespace std;

int x;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x;
}

int getNumOfStick()
{
    int sum = 64;
    deque<int> dq;
    dq.push_front(64);
    while (true)
    {
        if (sum == x)
            return dq.size();
        int minVal = dq.front();
        dq.pop_front();
        int half = minVal >> 1;

        dq.push_front(half);
        if (sum - half >= x)
            sum -= half;
        else
            dq.push_front(half);
    }
}

int main()
{
    input();
    cout << getNumOfStick() << '\n';
    return 0;
}