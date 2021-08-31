#include <iostream>
using namespace std;
int n;
int board[20][20];
int dp[3][17][17];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];

    for(int i = 2; i <= n; i++)
    {
        if(board[1][i] == 1) break;
        dp[0][1][i] = 1;
    }
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(board[i][j] != 1)
            {
                dp[0][i][j] = dp[0][i][j-1] + dp[2][i][j-1];
                dp[1][i][j] = dp[1][i-1][j] + dp[2][i-1][j];
                if(board[i-1][j] != 1 && board[i][j-1] != 1)
                    dp[2][i][j] = dp[0][i-1][j-1] + dp[1][i-1][j-1] + dp[2][i-1][j-1];
            }
        }
    cout << dp[0][n][n] + dp[1][n][n] + dp[2][n][n];
}