#include <iostream>
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b
using namespace std;

int n;
int num[12];
int possibleOp[12];
int op[4]; // index 0 +, 1 - , 2 *, 3 /
int maxAns = -1000000000, minAns = 1000000000;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < 4; i++)
        cin >> op[i];
}

int getCalculation()
{
    int res = num[0];
    for (int i = 1; i < n; i++)
    {
        switch (possibleOp[i - 1])
        {
        case 0:
            res += num[i];
            break;
        case 1:
            res -= num[i];
            break;
        case 2:
            res *= num[i];
            break;
        case 3:
            res /= num[i];
            break;
        default:
            break;
        }
    }
    return res;
}

void solve(int L)
{
    if (L == n - 1)
    {
        int calc = getCalculation();
        maxAns = max(maxAns, calc);
        minAns = min(minAns, calc);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (op[i] > 0)
        {
            op[i]--;
            possibleOp[L] = i;
            solve(L + 1);
            op[i]++;
        }
    }
}

int main()
{
    input();
    solve(0);
    cout << maxAns << '\n'
         << minAns << '\n';
    return 0;
}