#include <iostream>
using namespace std;
int n;
int cnt;
long long map[10000100];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    // 1 = 1 2의 0승
    // 2 = 2 00, 11 2의 1승
    // 4 = 5 0011, 0000, 1001, 1100, 1111 2의 2승
    map[0] = 1;
    map[1] = 2;

    for (int i = 2; i < n; i++)
        map[i] = (map[i - 2] + map[i - 1]) % 15746;
    cout << map[n-1];
}