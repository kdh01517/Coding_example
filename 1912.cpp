#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int d[100002];
    int c[100002];
    int maxi = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
        d[i] = c[i];
    }
    maxi = d[0];
    for(int i = 1; i < n; i++)
    {
        d[i] = max(d[i], d[i-1] + c[i]);
        if (maxi > d[i])
            maxi = d[i];
    }
    cout << maxi << '\n';
}