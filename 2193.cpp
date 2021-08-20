#include <iostream>
using namespace std;

int d[92];

int main(void)
{
    int n;
    cin >> n;
    d[0] = 1;
    d[1] = 1;
    for(int i = 2; i < n; i++)
        d[i] = d[i-2] + d[i-1];
    cout << d[n-1] << '\n';
}