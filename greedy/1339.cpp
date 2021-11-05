#include <bits/stdc++.h>
using namespace std;

long long ans;
long long N, arr[27];
vector<long long> V;
string S;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> N;
    // 글자를 개수 생각해서 저장
    for (int i = 0; i < N; ++i)
    {
        cin >> S;
        int cnt = 1;
        for (int j = S.size() - 1; j >= 0; j--)
        {
            arr[S[j] - 'A'] += cnt;
            cnt *= 10;
        }
    }
    // 각 글자수를 sort
    for (int i = 0; i < 27; ++i)
        if (arr[i] != 0)
            V.push_back(arr[i]);
    sort(V.begin(), V.end());
    // 글자수 많은게 높은 값을 갖게 함.
    int value = 9;
    for (int i = V.size() - 1; i >= 0; i--)
    {
        ans += V[i] * value;
        value--;
    }
    cout << ans << '\n';

    return 0;
}