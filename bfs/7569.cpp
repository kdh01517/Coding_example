#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int board[110][110][110];
int day[110][110][110];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int dh[2] = {1, -1};
int M, N, H; // 가로 세로 높이

void printMap()
{
    cout<<"\n";
    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                cout << board[h][n][m] << " ";
                
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

void printDay()
{
    cout<<"\n";
    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                cout << day[h][n][m] << " ";
                
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> H;
    
    queue <pair<pair<int, int>, int> > q;
    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                cin >> board[h][n][m];
                if (board[h][n][m] == 1)
                {
                    q.push({{n,m}, h});
                    day[h][n][m] = 1;
                }
            }
        }
    }
    while(!q.empty())
    {
        pair<pair<int, int>, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 2; dir++)
        {
            int nh = cur.second + dh[dir];
            if (nh < 0 || nh >= H) continue;
            if (board[nh][cur.first.first][cur.first.second] != 0 || day[nh][cur.first.first][cur.first.second] >= 1) continue;
            q.push({{cur.first.first, cur.first.second}, nh});
            board[nh][cur.first.first][cur.first.second] = 1;
            day[nh][cur.first.first][cur.first.second] = day[cur.second][cur.first.first][cur.first.second]+ 1;
        }
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first.first + dx[dir];
            int ny = cur.first.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[cur.second][nx][ny] != 0 || day[cur.second][nx][ny] >= 1) continue;
            q.push({{nx,ny}, cur.second});
            board[cur.second][nx][ny] = 1;
            day[cur.second][nx][ny] = day[cur.second][cur.first.first][cur.first.second] + 1;
        }
    }
    // printDay();
    int mx = 0;
     for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                if (board[h][n][m] == 0)
                {
                    cout << "-1";
                    return 0;
                }
                mx = max(mx, day[h][n][m]);
                
            }
        }
    }
    if (mx == 1)
        cout << "0";
    else
        cout << mx-1;
    return 0;
}

