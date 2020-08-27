#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int btn_time[3] = {300, 60, 10};
    int btn_cnt[3];
    int cnt;
    if (t % 10 != 0)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < 3; i++)
    {
        cnt = t / btn_time[i];
        t -= btn_time[i] * cnt;
        btn_cnt[i] = cnt;
    }
    for (int i = 0; i < 3; i++)
        cout << btn_cnt[i] << ' ';

    return 0;
}