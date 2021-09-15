#include <iostream>
using namespace std;
long long dp[110][30];
int d[110];
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> d[i];

    dp[0][d[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (j - d[i] >= 0)
            {
                dp[i][j] += dp[i - 1][j - d[i]];
            }
            if (j + d[i] <= 20)
            {
                dp[i][j] += dp[i - 1][j + d[i]];
            }
        }
    }
    cout << dp[n - 2][d[n - 1]];
}
