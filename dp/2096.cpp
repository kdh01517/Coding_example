#include <iostream>
using namespace std;
int map[3];
int map_min[3];
int N;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int a, b, c;
	cin >> map[0] >> map[1] >> map[2];
	map_min[0] = map[0];
	map_min[1] = map[1];
	map_min[2] = map[2];
	int tmp_zero, tmp_two;
	int zero_tmp, two_tmp;
	for (int i = 1; i < N; i++)
	{
		cin >> a >> b >> c;
		tmp_zero = map[0];
		tmp_two = map[2];
		map[0] = max(map[0], map[1]) + a;
		map[2] = max(map[2], map[1]) + c;
		map[1] = max(tmp_zero, max(map[1], tmp_two)) + b;

		zero_tmp = map_min[0];
		two_tmp = map_min[2];
		map_min[0] = min(map_min[0], map_min[1]) + a;
		map_min[2] = min(map_min[2], map_min[1]) + c;
		map_min[1] = min(zero_tmp, min(map_min[1], two_tmp)) + b;
	}
	int ans_max = max(map[0], max(map[1], map[2]));
	int ans_min = min(map_min[0], min(map_min[1], map_min[2]));
	cout << ans_max << ' ' << ans_min <<'\n';
}