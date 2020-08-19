#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int *res = new int[n];
    stack<int> line;
    stack<int> tmp;
    for (int i = 0; i < n; i++)
    {
        int p;
        scanf("%d", &p);
        for (int j = 0; j < p; j++)
        {
            tmp.push(line.top());
            line.pop();
        }
        line.push(i + 1);
        while (!tmp.empty())
        {
            line.push(tmp.top());
            tmp.pop();
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        res[i] = line.top();
        line.pop();
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", res[i]);
    }
    delete[] res;
    return 0;
}