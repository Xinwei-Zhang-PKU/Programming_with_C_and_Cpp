// http://cxsjsx.openjudge.cn/hw202216/C/

#include <iostream>
#include <cstring>

using std::cin, std::cout, std::endl;
const int kMaxN = 16;
int dp[(1 << kMaxN)][kMaxN];
int cost[kMaxN][kMaxN];
bool check[1 << kMaxN];

int main() {
    int n;
    while (cin >> n) {
        memset(dp, 0, sizeof dp);
        memset(check, 0, sizeof check);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                cin >> cost[i][j];
            }
        for (int i = 0; i < n - 1; ++i) {
            dp[(1 << i)][i] = cost[0][i + 1];
        }
        for (int i = 0; i < (1 << (n - 1)); ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (i & (1 << j)) {
                    bool first = true;
                    for (int k = 0; k < n - 1; ++k) {
                        if (k == j)
                            continue;
                        if (i & (1 << k)) {
                            if (first) {
                                dp[i][j] = dp[i ^ (1 << j)][k] + cost[k + 1][j + 1];
                                first = false;
                            } else {
                                dp[i][j] = std::min(dp[i][j], dp[i ^ (1 << j)][k] + cost[k + 1][j + 1]);
                            }
                        }
                    }
                }
            }
        }
        cout << dp[(1 << (n - 1)) - 1][n - 2] << endl;
    }
}
