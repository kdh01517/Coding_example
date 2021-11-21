#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int dp[101];
int max_height;
typedef struct {
	int weight;
	int height;
	int width;
	int block;
} tmp;


bool cmp_width(tmp a, tmp b)
{
	if (a.width < b.width)
		return 1;
	return 0;
}
vector <int> num;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n;
	int a, b, c;
	vector <tmp> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i].width >> v[i].height >> v[i].weight;
		v[i].block = i;
	}
	sort(v.begin(), v.end(), cmp_width);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i].weight > v[j].weight)
			{
				dp[i] = max(dp[i], dp[j] + v[i].height);
			}
		}
		max_height = max(max_height, dp[i]);
	}
	while (n)
	{
		if (max_height == dp[n])
		{
			num.push_back(v[n].block);
			max_height -= v[n].height;
		}
		n--;
	}
	cout << num.size() << '\n';
	for (int i = num.size()-1; i >= 0; i--)
		cout << num[i] << '\n';
}