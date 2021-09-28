#include <bits/stdc++.h>
using namespace std;
int n, s, tot;
int a[100005];
int mn = 2100000000;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    tot = a[0];
    int en = 0;
    for(int st = 0; st < n; st++)
    {
        while(en < n && tot < s)
        {
            en++;
            if(en != n) tot += a[en];
        }
        if (en == n) break;
        mn = min(mn, en - st + 1);
        tot -= a[st];
    }
    if(mn == 2100000000) mn = 0;
    cout << mn;
}