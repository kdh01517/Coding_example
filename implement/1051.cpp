#include <iostream>
#include <string>
using namespace std;
string board;
int map[51][51];
int n,m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans =1;
    cin >> n >> m;
    for(int i=0; i < n; i++)
    {
        cin >> board;
        for(int j=0; j < m; j++)
            map[i][j] = board[j] - '0';
    }
    for(int i=0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int k = 1; k < min(n,m); k++)
            {
                if(i+k < n && j+k < m && map[i+k][j] == map[i][j] && map[i+k][j+k]== map[i][j] && map[i][j+k] == map[i][j])
                    ans = max(ans, k + 1);
            }
        }
    }

    cout << ans*ans << '\n';
}