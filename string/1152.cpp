#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string s;
string tmp;
int main(void)
{
    getline(cin, s);
    if (s[0] == ' ')
        for (int i = 1; i < s.length(); i++)
            tmp += s[i];
    else
        tmp = s;
    istringstream ss(tmp);
    string buffer;
    int index = 0;
    while (getline(ss, buffer, ' '))
        index++;
    cout << index;
}