#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1002];
char type[1002];
typedef struct
{
    int x;
    int y;
    int weight;
} tmp;
vector<tmp> wei;
int res;

bool cmp(tmp wei1, tmp wei2)
{
    if (wei1.weight < wei2.weight)
        return 1;
    return 0;
}

int find(int dot) // 파인드
{
    if (dot == parent[dot])
        return dot;
    return parent[dot] = find(parent[dot]);
}

void merge(int start, int end) // 유니온
{
    start = find(start);
    end = find(end);

    if (start < end)
        parent[start] = end;
    else
        parent[end] = start;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v, e, a, b, c;

    cin >> v >> e;
    for (int i = 1; i <= v; i++)
    {
        cin >> type[i];
        parent[i] = i;
    }
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        if (type[a] != type[b])
            wei.push_back({a, b, c});
    }
    int chk = 0;
    
    sort(wei.begin(), wei.end(), cmp); // 간선을 오름차순 정렬
    for (int i = 0; i < wei.size(); i++)        // 사이클이 존재하지 않도록 연결할 수 있나 보기
    {
        if (find(wei[i].x) != find(wei[i].y))
        {
            merge(wei[i].x, wei[i].y);
            res += wei[i].weight;
            if (++chk == v-1)
            {
                cout << res << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}