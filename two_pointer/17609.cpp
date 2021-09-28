#include <iostream>
#include <string>
#include <vector>
using namespace std;

int del;
int n;
int ans;
string str;
vector <int> v;
int main()
{
	cin >> n;
	while (n--)
	{
        del = 0;
        ans = 0;
		cin >> str;
		int en = str.size() - 1;
        int st1;
        int en1 = str.size() - 1;
		for (int st = 0; st < en; st++)
		{
            st1 = st;
			if (str[st] != str[en])
			{
				if (del == 1)
				{
					ans = 2;
					break;
				}
				if (st + 1 != en && str[en] == str[st + 1])
				{
					st++;
					del = 1;
				}
				else if (st != en - 1 && str[st] == str[en - 1])
				{
					en--;
                    del = 1;
				}
				else
				{
					ans = 2;
					break;
				}

                if (st1 != en - 1 && str[st1] == str[en1 - 1])
				{
					en1--;
                    del = 1;
				}
				else if (st1 + 1 != en1 && str[en1] == str[st1 + 1])
				{
					st1++;
					del = 1;
				}
				else
				{
					ans = 2;
					break;
				}
			}
			en--;
            en1--;
		}
		if (del == 1 && ans != 2)
			ans = 1;
        v.push_back(ans);
	}
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
}
