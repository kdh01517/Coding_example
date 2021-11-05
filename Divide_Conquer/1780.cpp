#include <iostream>
using namespace std;

int map[2187][2187];
int one = 0;
int zero = 0;
int minusone = 0;

void quadtree(int n, int y, int x)
{
    int curr = map[y][x];
    if (n == 1)
    {
        if (curr == 1)
            one++;
        else if (curr == 0)
            zero++;
        else
            minusone++;
        return;
    }
    for (int i = y; i < y + n; i++)
    {
        for (int k = x; k < x + n; k++)
        {
            if (map[i][k] != curr)
            {
                quadtree(n / 3, y, x);           /// 1
                quadtree(n / 3, y, x + n / 3);  /// 2
                quadtree(n / 3, y, x + n / 3 * 2); /// 3
                quadtree(n / 3, y + n / 3, x);           /// 4
                quadtree(n / 3, y + n / 3, x + n / 3);   // 5
                quadtree(n / 3, y + n / 3, x + n / 3 * 2);  //6
                quadtree(n / 3, y + n / 3 * 2, x);   // 7
                quadtree(n / 3, y + n / 3 * 2, x + n / 3);  ///8 
                quadtree(n / 3, y + n / 3 * 2, x + n / 3 * 2);    //9
                return;
            }
            else if (i == y + n - 1 && k == x + n - 1)
            {
                if (curr == 1)
                    one++;
                else if (curr == 0)
                    zero++;
                else
                    minusone++;
            }
        }
    }
}

int main()
{
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
            cin >> map[i][k];
    }
    quadtree(n, 0, 0);
    cout << minusone << '\n' << zero << '\n' << one;
    return 0;
}
