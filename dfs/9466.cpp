#include <iostream>
#include <cstring>
using namespace std;
int n;
int ans;
int a;
int team[100002];
bool cycle[100002];
bool stu[100002];
void DFS(int cnt)
{
    stu[cnt] = true;
    int next = team[cnt];
    if (!stu[next])
        DFS(next);
    else if (!cycle[next])
    {
        for (int i = next; i != cnt; i = team[i])
            ans++;
        ans++;        
    }
    cycle[cnt] = true;    
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        memset(stu, false, sizeof(stu));
        memset(cycle, false, sizeof(cycle));
        cin >> a;
        for (int j = 1; j <= a; j++)
            cin >> team[j];

        ans = 0;
        for (int j = 1; j <= a; j++)
            if (!stu[j])
                DFS(j);
        cout << a - ans << '\n';
    }
}