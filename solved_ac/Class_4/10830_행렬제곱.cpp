#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;

ll n, b;

matrix operator*(const matrix &a, const matrix &b)
{
    matrix res(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
            res[i][j] %= 1000;
        }
    }
    return res;
}

matrix power(matrix a, ll r)
{
    matrix res(n, vector<ll>(n));
    // res를 단위행렬로 설정
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    while (r > 0)
    {
        if (r % 2 == 1)
        {
            res = res * a;
        }
        r /= 2;
        a = a * a;
    }
    return res;
}

void printRes(const matrix &res)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> b;
    matrix origin(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> origin[i][j];
        }
    }

    printRes(power(origin, b));

    return 0;
}