#include <iostream>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[600][600];
int dp[600][600];
int n, m;
int ans;

int DFS(int x, int y){
    if(dp[x][y] != -1) return dp[x][y]; // dp결과가 있으면 바로 return
    if(x == m-1 and y == n-1) return 1; // 최종 목적지로 도착하면 종료
    dp[x][y] = 0;
    for(int dir=0;dir<4;dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if(board[nx][ny] >= board[x][y]) continue;
        // dp값이 있으면 바로 더하기
        if(dp[nx][ny] != -1){
            dp[x][y] += dp[nx][ny];
        }else{
            // dp값이 없으면 구해와서 더하기
            dp[x][y] += DFS(nx,ny);
        }
    }
    return dp[x][y];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            dp[i][j] = -1;
        }
    ans = DFS(0, 0);
    cout << ans;
}