#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int map[1001][1001];
int map2[1001][1001];
int R, C, T;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > air;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == -1)
                air.push_back({i, j});
        }
    }
    int spread = 0;
    while (T--)
    {
        memset(map2, 0, sizeof(map2));
        // 미세먼지 확산
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                spread = 0;
                if (map[i][j] != -1)
                {
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                            continue;
                        if (map[nx][ny] == -1)
                            continue;
                        map2[nx][ny] += map[i][j] / 5;
                        spread++;
                    }
                    map2[i][j] += map[i][j] - (map[i][j] / 5) * spread;
                }
            }
        }
        // 덮어쓰기 map2 -> map
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (map[i][j] != -1)
                    map[i][j] = map2[i][j];
            }
        }
        // 위쪽 - 바닥
        map[air[0].first][1] = 0;
        for (int j = 2; j < C; j++)
        {
            map[air[0].first][j] = map2[air[0].first][j - 1];
        }
        // 위쪽 - 오른쪽
        for (int j = air[0].first - 1; j >= 0; j--)
        {
            map[j][C - 1] = map2[j + 1][C - 1];
        }
        // 위쪽 - 왼쪽
        if (air[0].first != 0)
        {
            for (int j = 0; j < air[0].first; j++)
            {
                if (map[j + 1][0] != -1)
                    map[j + 1][0] = map2[j][0];
            }
        }
        // 위쪽 - 위쪽
        if (map[0][0] != -1)
        {
            for (int j = C - 1; j >= 1; j--)
            {
                map[0][j - 1] = map2[0][j];
            }
        }
        // 아래쪽 - 위
        map[air[1].first][1] = 0;
        for (int j = 2; j < C; j++)
        {
            map[air[1].first][j] = map2[air[1].first][j - 1];
        }
        // 아래쪽 - 오른쪽
        for (int j = air[1].first + 1; j < R; j++)
        {
            map[j][C - 1] = map2[j - 1][C - 1];
        }
        // 아래쪽 - 왼쪽
        if (map[R - 1][0] != -1)
            for (int j = R - 1; j > air[1].first; j--)
            {
                if (map[j - 1][0] != -1)
                    map[j - 1][0] = map2[j][0];
            }
        // 아래쪽 - 바닥
        if (map[R - 1][0] != -1)
            for (int j = C - 1; j >= 1; j--)
            {
                map[R - 1][j - 1] = map2[R - 1][j];
            }
        // 덮어쓰기 map -> map2
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (map[i][j] != -1)
                    map2[i][j] = map[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] != -1 && map[i][j] != 0)
                ans += map[i][j];
        }
    }
    cout << ans << '\n';
}