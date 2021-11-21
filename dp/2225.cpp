#include <iostream>
using namespace std;

long long dp[201][201];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	for (int i = 0; i <= N; i++)
	{
		dp[1][i] = 1;
	}

	for (int k = 2; k <= K; k++)
	{
		for (int n = 0; n <= N; n++)
		{
			for (int i = 0; i <= n; i++)
			{
				dp[k][n] = dp[k][n] + dp[k-1][i];
			}
			dp[k][n] = dp[k][n] % 1000000000;
		}
	}
	cout << dp[K][N] << '\n';
}