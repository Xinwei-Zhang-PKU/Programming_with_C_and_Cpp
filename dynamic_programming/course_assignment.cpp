// http://cxsjsx.openjudge.cn/hw202215/D/

#include <iostream>
#include <vector>
#include <limits>
#include <cstring>

using std::cin, std::cout, std::endl, std::vector, std::string;

int n;
vector<string> courses;
vector<int> finish_time;
vector<int> ddl;
const int kMaxN{1 << 15};
const int kMaxInt = std::numeric_limits<int>::max();
int dp[kMaxN];
int time_spent[kMaxN];
string ans[kMaxN];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        courses.clear();
        finish_time.clear();
        ddl.clear();
        memset(time_spent, 0, sizeof time_spent);
        for (auto &an: ans) {
            an.clear();
        }
        for (int i = 0; i < n; ++i) {
            string str;
            int x, y;
            cin >> str >> x >> y;
            courses.push_back(str);
            finish_time.push_back(y);
            ddl.push_back(x);
        }
        for (int i = 1; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    time_spent[i] += finish_time[j];
                }
            }
        }
        for (int i = 1; i < (1 << n); ++i) {
            dp[i] = kMaxInt;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    int tmp;
                    if (time_spent[i] <= ddl.at(j)) {
                        tmp = dp[i ^ (1 << j)];
                    } else {
                        tmp = dp[i ^ (1 << j)] + time_spent[i] - ddl.at(j);
                    }
                    if (tmp <= dp[i]) {
                        string res = ans[i ^ (1 << j)] + courses[j] + "\n";
                        if (ans[i].empty() || tmp < dp[i]) {
                            ans[i] = res;
                        } else {
                            ans[i] = std::min(ans[i], res);
                        }
                        dp[i] = tmp;
                    }
                }
            }
        }
        cout << dp[(1 << n) - 1] << endl << ans[(1 << n) - 1];
    }
}
