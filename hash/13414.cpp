#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <stdio.h>
using namespace std;
int stu[500050];
map<int, int> m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    int l;
    cin >> k >> l;

    for(int i = 0; i < l; i++)
    {
        cin >> stu[i];
        m[stu[i]] = i;
    }
    int cnt = 0;
    for(int i = 0; i < l; i++)
    {
        if (cnt >= k) break;
        if (m[stu[i]] == i)
        {
            printf("%08d\n", stu[i]);
            cnt++;
        }
    }
}