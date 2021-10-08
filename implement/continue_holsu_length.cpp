#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> vec, int n, int k) {
    int cnt = 0;
    vector<int> oddIdxes;
    oddIdxes.push_back(-1);
    for (int i = 0 ;i < n ;i ++) {
        if (vec[i] % 2 == 1) {
            oddIdxes.push_back(i);
        }
    }
    oddIdxes.push_back(n);
    for (int i = 0 ; i < oddIdxes.size() - k - 1 ; i ++) {
        int lDiff = oddIdxes[i+1] - oddIdxes[i];
        int rDiff = oddIdxes[i+k+1] - oddIdxes[i+k];
        cnt += lDiff * rDiff;
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> vec;
    int n, k;
    cin >> n >> k;
    for (int i = 0 ; i < n ; i ++) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    solve(vec, n, k);

    return 0;
}