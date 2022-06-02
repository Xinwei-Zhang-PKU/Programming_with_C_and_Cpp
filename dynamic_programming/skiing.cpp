// http://cxsjsx.openjudge.cn/hw202214/A/
#include <iostream>
#include <vector>
#include <algorithm>

const int kMaxN = 110;
const int kMaxH = 10010;
const int pos_x[]{0, 0, 1, -1};
const int pos_y[]{1, -1, 0, 0};

struct point {
    int x, y;
    int height;

    point(int x, int y, int height) : x(x), y(y), height(height) {

    }

    bool operator<(const point &other) const {
        return height < other.height;
    }
};

std::vector<point> p;
int dp[kMaxN][kMaxN];
int h[kMaxN][kMaxN];

int main() {
    int R, C;
    int res = 0;
    std::cin >> R >> C;
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j) {
            int x;
            std::cin >> x;
            p.emplace_back(i, j, x);
            h[i][j] = x;
        }
    for (int i = 0; i < std::max(R, C); ++i) {
        h[0][i] = h[i][0] = h[R + 1][i] = h[i][C + 1] = kMaxH;
    }
    std::sort(p.begin(), p.end());
    for (const auto &i: p) {
        int x = i.x;
        int y = i.y;
        int tmp = 1;
        for (int j = 0; j < 4; ++j) {
            int _x = x + pos_x[j];
            int _y = y + pos_y[j];
            if (h[_x][_y] < h[x][y]) {
                tmp = std::max(tmp, dp[_x][_y] + 1);
            }
        }
        dp[x][y] = tmp;
        res = std::max(res, dp[x][y]);
    }
    std::cout << res << std::endl;
}
