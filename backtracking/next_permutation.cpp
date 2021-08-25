#include <iostream>
using namespace std;
int main(void)
{
    int a[3] = {1, 2, 3};
    do
    {
        for (int i = 0; i < 3; i++)
            cout << a[i];
        cout << '\n';
    } while (next_permutation(a, a + 3));
    /* 순열 뽑기
    123 
    132
    213
    231
    312
    321
    */
    int b[4] = {0, 0, 1, 1};
    do
    {
        for (int i = 0; i < 4; i++)
            if(b[i] == 0)
                cout << i + 1;
        cout << '\n';
    } while (next_permutation(b, b + 4));
    /* 조합 뽑기 - 4개중 2개 뽑기
    12
    13
    14
    23
    24
    34 
    */
    int c[5] = {0, 0, 0, 1, 1};
    do
    {
        for (int i = 0; i < 5; i++)
            if(c[i] == 0)
                cout << i + 1;
        cout << '\n';
    } while (next_permutation(c, c + 5));
    /*
    5개중 3개 뽑기
    */
}