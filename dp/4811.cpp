#include <iostream>
using namespace std;

long long dp[31][31];
int n;

void calculate()
{
    for (int i = 0; i <= 30; i++)
        dp[0][i] = 1;

    for (int w = 1; w <= 30; w++)
    {
        for (int h = 0; h <= 30; h++)
        {
            if (h == 0)
                dp[w][0] = dp[w-1][1];
            else
                dp[w][h] = dp[w-1][h+1] + dp[w][h-1];
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    calculate();
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        cout << dp[n][0] << '\n';
    }
}