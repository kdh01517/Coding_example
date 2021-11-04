#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef struct
{
    int a;
    int b;
} tmp;
tmp cnt;
vector<tmp> v;
bool cmp(tmp x, tmp y)
{
    if (x.a < y.a)
        return 1;
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        cnt.a = a;
        cnt.b = b;
        v.push_back(cnt);
    }
    sort(v.begin(), v.end(), cmp);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(v[0].b);

    for (int i = 1; i < n; i++)
    {
        if (pq.top() <= v[i].a)
        {
            pq.pop();
            pq.push(v[i].b);
        }
        else
        {
            pq.push(v[i].b);
        }
    }
    cout << pq.size() << '\n';
    return (0);
}