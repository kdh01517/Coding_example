#include <iostream>
#include <algorithm>
using namespace std;
int ans;
int ar[100];
int ar2[100];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    for (int i = 0; i < n; i++)
        cin >> ar2[i];
    sort(ar, ar+n);
    sort(ar2, ar2+n, greater<int>());
    for (int i = 0; i < n; i++)
        ans += ar[i]*ar2[i];
    cout << ans << '\n';
}