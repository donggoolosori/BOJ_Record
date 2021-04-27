#include <iostream>
#include <vector>

using namespace std;

int n, r, c;
int num = 0;

void zSearch(int y, int x, int size)
{
    if (y == r && x == c)
    {
        cout << num << '\n';
        return;
    }

    // r,c가 현재 사분면에 존재
    if (r < y + size && r >= y && c < x + size && c >= x)
    {
        int newSize = size / 2;
        zSearch(y, x, newSize);
        zSearch(y, x + newSize, newSize);
        zSearch(y + newSize, x, newSize);
        zSearch(y + newSize, x + newSize, newSize);
    }
    else
        num += size * size;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r >> c;
    int size = 1 << n; // 비트연산 사용
    zSearch(0, 0, size);

    return 0;
}