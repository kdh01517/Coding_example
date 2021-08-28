#include <iostream>
using namespace std;

int n;
int tall[10];
int tmp[10];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tall[i];
        for (int j = 0; j < n; j++)
        {
            if (tall[i] == 0 && tmp[j] == 0)
            {
                tmp[j] = i + 1;
                break;
            }
            else if (tmp[j] == 0)
            {
                tall[i]--;
            }
        }
    }
    for(int i = 0; i < n; i++)
        cout << tmp[i] << ' ';
}