#include <bits/stdc++.h>

using namespace std;

int board[4][6][3];
int cur[6][3];
vector<pair<int, int>> teams;
bool res[4];

void isEqual()
{
	for (int k = 0; k < 4; k++) {
		if (res[k])
			continue;
		res[k] = true;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (cur[i][j] != board[k][i][j]) {
					res[k] = false;
				}
			}
			if (!res[k])
				break;
		}
	}
}

void sol(int depth) {
	// 탈출조건
	if (depth >= 15) {
		isEqual();
		return;
	}

	int t1 = teams[depth].first;
	int t2 = teams[depth].second;
	// depth 번째 국가가 이김
	cur[t1][0]++;
	cur[t2][2]++;
	sol(depth + 1);
	cur[t1][0]--;
	cur[t2][2]--;
	// 비김
	cur[t1][1]++;
	cur[t2][1]++;
	sol(depth + 1);
	cur[t1][1]--;
	cur[t2][1]--;
	// depth 번째 국가가 짐
	cur[t1][2]++;
	cur[t2][0]++;
	sol(depth + 1);
	cur[t1][2]--;
	cur[t2][0]--;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> board[i][j][k];
			}
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			teams.push_back({ i, j });
		}
	}

	sol(0);

	for (int i = 0; i < 4; i++) {
		if (res[i])
			cout << "1 ";
		else
			cout << "0 ";
	}

	return 0;
}