#include <iostream>
#include <map>
#include <utility>
using namespace std;
int main(void)
{
    int num[7] = {2, 2, 2, 1, 2, 2, 1}; //, 2, 2, 2};
    int k = 2;
    int answer = 0;
    int temp = 0;
    map<int, int> m;
    for (int i = 0; i < 7; i++)
    {
        if (num[i] % 2 == 1)
            temp++;
        if (temp == k)
            answer++;
        if (m[temp - k])
            answer += m[temp - k];
        if (m.find(temp) == m.end())
            m.insert(make_pair(temp, 1));
        else
            m[temp]++;
    }
    cout << answer;
}