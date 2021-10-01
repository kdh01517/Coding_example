#include <vector>
#include <iostream>
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        auto it = lower_bound(a.begin(), a.end(), num);
        if (it != a.end()) *it = num;
        else a.push_back(num);
    }
    cout << a.size() << '\n';
}