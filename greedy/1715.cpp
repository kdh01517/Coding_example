#include <iostream>
#include <queue>
using namespace std;
int n;
int result;
priority_queue<int> pq;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tmp = 0;
    cin >> n;
    while (n--)
    {
        cin >> tmp;
        pq.push(-tmp);
    }

    while (pq.size() != 1)
    {
        int one = pq.top();
        pq.pop();
        int two = pq.top();
        pq.pop();
        int sum = one + two;
        result += sum;
        pq.push(sum);
    }
    cout << -result;
}