#include <iostream>
#include <algorithm>
using namespace std;
int dp[302][302];
int map[302][302];
int n, m;
int ans;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	int index = 0;
	for (int i = 1; i <= n; i++)
		if (map[i][1] == 1)
			dp[i][1] = ++index;
		else
			dp[i][1] = index;
	index = 0;
	for (int i = 1; i <= m; i++)
		if (map[1][i] == 1)
			dp[1][i] = ++index;
		else
			dp[1][i] = index;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			if (map[i][j] == 1)
				dp[i][j] = max(dp[i][j-1] + 1, dp[i-1][j] + 1);
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	cout << dp[n][m] << '\n';
}