#include <iostream>
using namespace std;

int h, w;
int map[505][505];
int tmp;
int ans;

int main()
{
	cin >> h >> w;
	for (int i = 0; i < w; i++)
	{
		cin >> tmp;
		for (int j = h - 1; tmp-- > 0; j--)
			map[j][i] = 1;
	}
	for (int i = 0; i < h; i++)
	{
		int start = 0;
		while (start < w && map[i][start] == 0)
			start++;
		int end = start + 1;
		while (end < w)
		{	
			while (end < w && map[i][end] == 0)
				end++;
			if (end == w)
				break;
			ans += end - start - 1;
			start = end;
			end++;
		}
	}
	cout << ans;
}