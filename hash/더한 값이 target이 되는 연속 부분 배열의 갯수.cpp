#include <map>
#include <utility>
#include <iostream>
using namespace std;
int main(void)
{
    int nums[8] = {1, 2, 3, -3, 1, 2, 4, 2};
    map<int, int> m;
    int target = 3;
    int n;
    int sum = 0;
    int answer = 0;
    int temp = 0;
    for (int i = 0; i < 8; i++)
    {
        sum += nums[i];
        if (sum == target)
            answer++;
        temp = sum - target;
        if (m.find(temp) != m.end())
            answer += m[temp];
        if (m.find(sum) == m.end())
            m.insert(make_pair(sum, 1));
        else
            m[sum]++;
    }
    cout << answer;
}