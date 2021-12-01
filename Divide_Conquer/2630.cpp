#include <iostream>
using namespace std;
int map[130][130];
int white, blue;

void divide_conquer(int x, int y, int N)
{
	int cnt = 0;
	for (int i = x; i < x + N; i++)
		for (int j = y; j < y + N; j++)
			if (map[i][j])
				cnt++;
	if (!cnt) white++;
	else if (cnt == N*N) blue++;
	else
	{
		divide_conquer(x, y, N/2);
		divide_conquer(x, y + N/2, N/2);
		divide_conquer(x + N/2, y, N/2);
		divide_conquer(x + N/2, y + N/2, N/2);
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
	cout << white << '\n' << blue << '\n';
}