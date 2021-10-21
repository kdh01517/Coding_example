#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    int range1;
    int height;
    int weight;
    int num;
} building;

bool cmp(building a, building b)
{
    if (a.range1 < b.range1)
		return 1;
	return 0;
}
int rock;
vector <building> v;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, c;
    cin >> n;
    for (int i = 0 ; i < n; i++)
    {
        cin >> a >> b >> c;
        v.push_back({a, b, c, i+1});
    }
    sort(v.begin(), v.end(), cmp);
	vector<int> hap(n, 0);
	hap[0] = v[0].height;
	vector<int> nopi;
	nopi.push_back(v[0].num);
	int last_index = 0;
    for (int i = 1 ; i < n; i++)
    {
        if (v[i-1].weight > v[i].weight)
        {
            hap[i] = v[i].height + hap[last_index]; // 현재 높이 + 이전 높이들
            nopi.push_back(v[i].num);
        }
		else
			last_index = i;
    }

    int tmp = 0;
    for (int i = 0; i < n; i++)
        if (tmp < hap[i])
            tmp = hap[i];
    for (int i = 0; i < n; i++)
    {
        if (tmp == hap[i])
        {
            cout << nopi.size() << "\n";
            for (int j = 0; j < nopi.size(); j++)
                cout << nopi[j] << "\n";
        }
        break;
    }
}