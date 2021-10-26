#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int parent[100002];
typedef struct
{
    int weight;
    int cur;
    int nex;
} tmp;
typedef struct
{
    int pos;
    int index;
} spot;
vector<tmp> edge;
vector<tmp> wei;

vector<spot> x_node;
vector<spot> y_node;
vector<spot> z_node;
int res;
bool flag;
bool cmp(tmp wei1, tmp wei2)
{
    if (wei1.weight < wei2.weight)
        return 1;
    return 0;
}
bool cmp2(spot wei1, spot wei2)
{
    if (wei1.pos < wei2.pos)
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
    flag = false;
	start = find(start);
	end = find(end);
	
	if (start == end)
		return ;
	parent[start] = end;
	flag = true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v, a, b, c;

    cin >> v;
    for (int i = 0; i < v; i++)
    {
        cin >> a >> b >> c;
        x_node.push_back({a, i});
        y_node.push_back({b, i});
        z_node.push_back({c, i});
        parent[i] = i;
    }
    sort(x_node.begin(), x_node.end(), cmp2);
    sort(y_node.begin(), y_node.end(), cmp2);
    sort(z_node.begin(), z_node.end(), cmp2);

    for(int i=0; i<v-1; i++) {
        edge.push_back({abs(x_node[i].pos - x_node[i+1].pos),x_node[i].index,x_node[i+1].index});
        edge.push_back({abs(y_node[i].pos - y_node[i+1].pos),y_node[i].index,y_node[i+1].index});
        edge.push_back({abs(z_node[i].pos - z_node[i+1].pos),z_node[i].index,z_node[i+1].index});
    }
    int chk = 0;

    sort(edge.begin(), edge.end(), cmp);   // 간선을 오름차순 정렬
    for (int i = 0; i < edge.size(); i++) // 사이클이 존재하지 않도록 연결할 수 있나 보기
    {
        merge(edge[i].cur, edge[i].nex);
        if (flag)
        {
            res += edge[i].weight;
            if (++chk == v - 1)
            {
                cout << res << '\n';
                return 0;
            }
        }
    }
    return 0;
}