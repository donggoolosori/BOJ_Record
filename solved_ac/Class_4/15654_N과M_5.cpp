#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int num[8];
int ans[8];
bool visit[8];

void Print()
{
    for(int i=0;i<m;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}

void dfs(int L)
{
    if(L==m)
    {
        Print();
    }
    for(int i=0;i<n;i++)
    {
        if(!visit[i])
        {
            ans[L] = num[i];
            visit[i] = true;
            dfs(L+1);
            visit[i]=false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>num[i];
    sort(num,num+n);
    dfs(0);

    return 0;
}