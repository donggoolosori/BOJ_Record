#include <iostream>
#include <string>

#define MOD 1234567891

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L;
    string input;
    cin >> L >> input;

    long long sum = 0;
    long long R = 1;
    for (int i = 0; i < input.length(); i++)
    {
        sum += ((input[i] - 'a' + 1) * R) % MOD;
        R = (R * 31) % MOD;
    }
    cout << sum % MOD;

    return 0;
}