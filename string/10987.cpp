#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'a' || s[i] == 'e' || s[i] ==  'i' || s[i] ==  'o' || s[i] == 'u')
			ans++;
	cout << ans;
}