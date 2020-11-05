#include <iostream>

using namespace std;

int h, m, s;
int start, current;

void input()
{
    scanf("%d:%d:%d", &h, &m, &s);
    current = h * 3600 + m * 60 + s;
    scanf("%d:%d:%d", &h, &m, &s);
    start = h * 3600 + m * 60 + s;
}

void solve()
{
    if (start < current)
        start += 24 * 3600;
    int ansT = start - current;
    int ansH = ansT / 3600;
    int ansM = (ansT % 3600) / 60;
    int ansS = ((ansT % 3600) % 60);
    printf("%02d:%02d:%02d", ansH, ansM, ansS);
}

int main()
{
    input();
    solve();

    return 0;
}