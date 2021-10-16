#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
char arr[20];
vector<char> v;
bool isused[10];
int flag_i;
int flag_j;
void func(int k, int cnt)
{
    if (k == n)
    {
        if (flag_i < 1)
            return;
        if (flag_j < 2)
            return;
        for (int i = 0; i < n; i++)
            cout << arr[i];
        cout << '\n';
        return;
    }
    for (int i = cnt; i < m; i++)
    {
        arr[k] = v[i];
        if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
            flag_i++;
        else
            flag_j++;
        func(k + 1, i + 1);
        if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
            flag_i--;
        else
            flag_j--;
    }
}
// a e i o u
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    char tmp;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    func(0, 0);
}