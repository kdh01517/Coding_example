#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int map[10][10];
int ans[10][10];
vector<pair<int, int>> sudo;

int check(int x, int y, int n)
{
    int a = x / 3;
    int b = y / 3;
    for (int i = 3 * a; i < 3 * a + 3; i++)
        for (int j = 3 * b; j < 3 * b + 3; j++)
        {
            if (map[i][j] == n)
                return 0;
        }
    for (int i = 0; i < 9; i++)
    {
        if (map[x][i] == n)
            return 0;
    }
    for (int i = 0; i < 9; i++)
    {
        if (map[i][y] == n)
            return 0;
    }
    return 1;
}

bool isfound;

void DFS(int cnt)
{
    if (isfound)
        return;
    if (cnt == sudo.size())
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                ans[i][j] = map[i][j];
        isfound = true;
        return;
    }
    auto cur = sudo[cnt];
    for (int i = 1; i <= 9; i++)
    {
        if (check(cur.first, cur.second, i))
        {
            map[cur.first][cur.second] = i;
            DFS(cnt + 1);
            map[cur.first][cur.second] = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
                sudo.push_back(make_pair(i, j));
        }
    }
    DFS(0);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}