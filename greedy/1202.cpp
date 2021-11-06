#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct
{
    int weight;
    int value;
} jew;
int n, k;
jew a;
int c;
vector<jew> v;
vector<int> bag;
long long ans;
bool cmp(jew a, jew b)
{
    if (a.weight < b.weight)
        return 1;
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    priority_queue <int> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> a.weight >> a.value;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < k; i++)
    {
        cin >> c;
        bag.push_back(c);
    }
    sort(bag.begin(), bag.end());
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        while (index < n && v[index].weight <= bag[i])
        {
            pq.push(v[index++].value);
        }
        if (!pq.empty())
        {
            ans += (long long)pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
}