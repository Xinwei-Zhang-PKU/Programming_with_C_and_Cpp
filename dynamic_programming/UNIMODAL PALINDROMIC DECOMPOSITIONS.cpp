// http://cxsjsx.openjudge.cn/hw202215/A/
#include <iostream>

int n;
const int kMaxN = 255;
long long dp[kMaxN][kMaxN];

int main() {
    for (int i = 1; i < kMaxN; ++i) {
        for (int j = i / 2 + 1; j <= i; ++j)
            dp[i][j] = 1;
        if (!(i & 1)) {
            dp[i][i / 2] = 2;
        } else if (i == 3) {
            dp[i][i / 2] = 2;
        } else {
            dp[i][i / 2] = 1;
        }
        for (int j = i / 2 - 1; j >= 1; --j) {
            int remain = i - 2 * j;
            dp[i][j] = dp[remain][j] + dp[i][j + 1];
        }
    }
    while (std::cin >> n, n) {
        std::cout << n << ' ' << dp[n][1] << std::endl;
    }
}
