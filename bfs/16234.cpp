#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <stdlib.h>
using namespace std;
int n;
int L, R;
int map[51][51];
int map2[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, -0};
int day;
int sum;
int cnt;
int vis[51][51];
int limit;
vector<pair<int, int> > nation;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> L >> R;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    int flag = 1;
    int index = 0;
    while (flag)
    {
        flag = 0;
        memset(vis, false, sizeof(vis));
        queue<pair<int, int> > q;
        index++;
        limit = index;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                index++;
                sum = 0;
                cnt = 0;
                if (vis[i][j] < limit)
                {
                    q.push(make_pair(i, j));
                    nation.push_back(make_pair(i, j));
                    sum += map[i][j];
                    cnt++;
                    vis[i][j] = index;
                }
                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (abs(map[nx][ny] - map[cur.first][cur.second]) < L || abs(map[nx][ny] - map[cur.first][cur.second]) > R)
                            continue;
                        if (vis[nx][ny] > limit)
                            continue;
                        sum += map[nx][ny];
                        cnt++;
                        flag = 1;
                        vis[nx][ny] = index;
                        q.push(make_pair(nx, ny));
                        nation.push_back(make_pair(nx, ny));
                    }
                }
                if (cnt == 0 || sum == 0)
                    continue;
                int tmp = (sum / cnt);
                for (int x = 0; x < nation.size(); x++)
                    map[nation[x].first][nation[x].second] = tmp;
                nation.clear();
            }
        }
        if (flag == 0)
        {
            cout << day << '\n';
            return 0;
        }
        day++;
    }
}