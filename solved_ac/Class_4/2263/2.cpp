#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> in, post;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        in.push_back(n);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        post.push_back(n);
    }

    return 0;
}