#include <iostream>
#include <algorithm>
using namespace std;
int rope[100001];
long long hap;
long long ans;
bool cmp (int a, int b)
{
    if (a > b)
        return 1;
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> rope[i];
    sort(rope, rope + n, cmp);
    for (int i = 0; i < n; i++)
    {
        hap = rope[i] * (i + 1);
        if (ans < hap)
            ans = hap;
    }    
    cout << ans << '\n';
}