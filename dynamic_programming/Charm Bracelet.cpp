// http://cxsjsx.openjudge.cn/hw202215/C/

// The following answer gets "memory limit exceed":
/*
#include <iostream>
#include <vector>
#include <utility>

using std::cin, std::cout, std::endl, std::vector, std::pair;
const int kMaxN = 3412;
const int kMaxM = 12890;
int dp[kMaxN][kMaxM];

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> charms;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        charms.emplace_back(std::make_pair(x, y));
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (charms.at(i - 1).first <= j) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - charms.at(i - 1).first] + charms.at(i - 1).second);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[N][M] << endl;
}
*/

// After applying the rolling array:

#include <iostream>
#include <vector>
#include <utility>

using std::cin, std::cout, std::endl, std::vector, std::pair;
const int kMaxM = 12890;
int dp[kMaxM][2];

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> charms;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        charms.emplace_back(std::make_pair(x, y));
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (i & 1) {
                if (charms.at(i - 1).first <= j) {
                    dp[j][0] = std::max(dp[j][1], dp[j - charms.at(i - 1).first][1] + charms.at(i - 1).second);
                } else {
                    dp[j][0] = dp[j][1];
                }
            } else {
                if (charms.at(i - 1).first <= j) {
                    dp[j][1] = std::max(dp[j][0], dp[j - charms.at(i - 1).first][0] + charms.at(i - 1).second);
                } else {
                    dp[j][1] = dp[j][0];
                }
            }
        }
    }
    if (N & 1) {
        cout << dp[M][0] << endl;
    } else {
        cout << dp[M][1] << endl;
    }
}
