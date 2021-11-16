#include <iostream>
#include <vector>

using namespace std;
int N;
int M;
int p[101];
int find_parent(int x)
{
    if (x == p[x])
        return x;
    return p[x] = find_parent(p[x]);
}
void union_parent(int a, int b)
{
    int start = find_parent(a);
    int end = find_parent(b);
    if (start < end)
        p[end] = start;
    else
        p[start] = end;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        p[i] = i;
    int a, b;
    vector <pair<int, int> > v;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    for (int i = 0; i < v.size(); i++)
    {
        int start = v[i].first;
        int end = v[i].second;
        if (find_parent(start) != find_parent(end))
        {
            union_parent(start, end);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (find_parent(p[i]) == 1)
            cnt++;
    }
    cout << cnt-1 << '\n';
}