#include <iostream>
#define ll long long

using namespace std;

ll N, B;
struct Matrix
{
    ll mtx[5][5];
    Matrix operator*(const Matrix &B) const
    {
        Matrix ret;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ll sum = 0;
                for (int k = 0; k < N; k++)
                    sum += mtx[i][k] * B.mtx[k][j];
                ret.mtx[i][j] = sum % 1000;
            }
        }
        return ret;
    }
};

Matrix getMtxPow(Matrix A, ll n)
{
    if (n == 1)
        return A;

    if (n % 2 == 0)
    {
        Matrix temp = getMtxPow(A, n / 2);
        return temp * temp;
    }
    else
    {
        Matrix temp = getMtxPow(A, n - 1);
        return temp * A;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> B;
    Matrix A;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A.mtx[i][j];

    Matrix ans = getMtxPow(A, B);
    // 답 출력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << ans.mtx[i][j] % 1000 << ' ';
        cout << '\n';
    }

    return 0;
}