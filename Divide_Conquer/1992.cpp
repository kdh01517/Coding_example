#include <iostream>
#include <string>
using namespace std;
char map[65][65];
int zero, one;
string ans = "";
void divide_conquer(int x, int y, int N)
{
	int cnt = 0;
	for (int i = x; i < x + N; i++)
		for (int j = y; j < y + N; j++)
			if (map[i][j] == '1')
				cnt++;
	
	if (!cnt) ans += '0';
	else if (cnt == N*N) ans += '1';
	else
	{
		ans += '(';
		divide_conquer(x, y, N/2);
		divide_conquer(x, y + N/2, N/2);
		divide_conquer(x + N/2, y, N/2);
		divide_conquer(x + N/2, y + N/2, N/2);
		ans += ')';
	}
	
	return;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	divide_conquer(0, 0, n);
	cout << ans << '\n';
}