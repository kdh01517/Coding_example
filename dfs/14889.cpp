#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int map[22][22];
int arr[22];
int vis[22];
int n;

int ans = 1000000000;
void DFS(int cnt, int idx)
{
    if (cnt == (n / 2))
    {
        int one = 0;
        int two = 0;
        vector<int> start;
        vector<int> end;
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                start.push_back(i);
            else
                end.push_back(i);
        }
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                one += map[start[i]][start[j]];
                two += map[end[i]][end[j]];
            }
        }
        ans = min(ans, abs(one - two));
        return;
    }
    for (int i = idx; i < n; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            DFS(cnt + 1, i);
            vis[i] = 0;
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    for (int i = 0; i < n; i++)
        arr[i] = i;
    DFS(0, 0);
    cout << ans;
}