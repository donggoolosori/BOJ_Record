#include <iostream>
#include <algorithm>

using namespace std;

int x, y, w, h;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> y >> w >> h;
}

int main()
{
    input();
    int left = x;
    int right = w - x;
    int up = h - y;
    int down = y;
    cout << min(min(left, right), min(up, down)) << '\n';

    return 0;
}