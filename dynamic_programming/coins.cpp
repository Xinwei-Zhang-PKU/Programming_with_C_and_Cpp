// http://cxsjsx.openjudge.cn/hw202215/
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin, std::cout, std::endl, std::vector;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1);
    vector<int> a(n);
    vector<int> res;
    for (int &i: a) {
        cin >> i;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = x; j >= a[i - 1]; --j) {
            dp[j] += dp[j - a[i - 1]];
        }
    }
    for (int i = 1; i <= n; ++i) {
        vector<int> check(x + 1);
        check[0] = 1;
        for (int j = 1; j <= x; ++j) {
            if (j < a[i - 1]) {
                check[j] = dp[j];
            } else {
                check[j] = dp[j] - check[j - a[i - 1]];
            }
        }
        if (check[x] == 0) {
            res.push_back(a[i - 1]);
        }
    }
    std::sort(res.begin(), res.end());
    int size = res.size();
    bool first = true;
    cout << size << endl;
    for (int &i: res) {
        if (first) {
            cout << i;
            first = false;
        } else {
            cout << ' ' << i;
        }
    }
    cout << endl;
}
