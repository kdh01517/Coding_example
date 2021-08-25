#include <iostream>
using namespace std;

int num[11];
int n;
int vis[11];
int recur()
{
    int ans = 0;
    for(int i = 1; i < n; i++)
    {
        if (vis[i]) continue;
        int left = i - 1;
        int right = i + 1;
        while (vis[left]) --left;
        while (vis[right]) ++right;
        vis[i] = true;
        ans = max(ans, recur() + num[left]*num[right]);
        vis[i] = false;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i < n; i++)
        cin >> num[i];
    cout << recur() << '\n';
}