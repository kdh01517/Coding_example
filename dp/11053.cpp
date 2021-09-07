#include <iostream>
#include <algorithm>
using namespace std;
int d[1010];
int dp[1010];
int n;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> d[i];

    for (int i = 0; i < n; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (d[i] > d[j])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    cout << *max_element(dp, dp+n);
}