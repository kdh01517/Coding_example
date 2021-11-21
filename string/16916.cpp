#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> makeTable(string p)
{
    vector<int> table(p.length());
    int j = 0;
    for (int i = 1; i < p.length(); i++)
    {
        while (p[i] != p[j] && j > 0)
        {
            j = table[--j];
        }
        if (p[i] == p[j])
        {
            table[i] = ++j;
        }
    }
    return table;
}

int kmp(string s, string p, vector<int> &table)
{
    int j = 0;
    for (int i = 0; i < s.length(); i++)
    {
        while (s[i] != p[j] && j > 0)
        {
            j = table[--j];
        }
        if (s[i] == p[j])
            if (++j == p.length())
            {
                return 1;
            }
    }
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, cmp;
    cin >> s >> cmp;
    vector<int> table = makeTable(cmp);
    cout << kmp(s, cmp, table);
}