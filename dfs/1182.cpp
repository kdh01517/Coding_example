#include <iostream>
using namespace std;

int arr[22];
int vis[22];
int n;
int s;
int ans;

void DFS(int cnt, int sum)
{
    if (cnt == n)
    {
        if (sum == s)
            ans++;
        return;
    }
    DFS(cnt+1, sum);
    DFS(cnt+1, sum + arr[cnt]);
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    DFS(0, 0);
    if (s == 0)
        ans--;
    cout << ans;
}