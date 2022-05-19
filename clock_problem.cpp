// http://cxsjsx.openjudge.cn/hw202212/A/
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>
const int kMaxN = 9;
const int kTime = 4;
int a[kMaxN];
int b[kMaxN];
std::vector<int> res;
bool check(const std::vector<int> &c) {
    b[0] = c[0] + c[1] + c[3] + a[0];
    b[1] = a[1] + c[0] + c[1] + c[2] + c[4];
    b[2] = a[2] + c[1] + c[2] + c[5];
    b[3] = a[3] + c[0] + c[3] + c[4] + c[6];
    b[4] = a[4] + c[0] + c[2] + c[4] + c[6] + c[8];
    b[5] = a[5] + c[2] + c[4] + c[8];
    b[6] = a[6] + c[3] + c[6] + c[7];
    b[7] = a[7] + c[4] + c[6] + c[7] + c[8];
    b[8] = a[8] + c[5] + c[7] + c[8];
    for (int i = 0; i < kMaxN; ++i) {
        if (b[i] % kTime != 0) {
            return false;
        }
    }
    return true;
}
int main() {
    for (auto &i : a) {
        std::cin >> i;
    }
    int min_time = std::numeric_limits<int>::max();
    for (int i1 = 0; i1 < kTime; ++i1)
        for (int i2 = 0; i2 < kTime; ++i2)
            for (int i3 = 0; i3 < kTime; ++i3)
                for (int i4 = 0; i4 < kTime; ++i4)
                    for (int i5 = 0; i5 < kTime; ++i5)
                        for (int i6 = 0; i6 < kTime; ++i6)
                            for (int i7 = 0; i7 < kTime; ++i7)
                                for (int i8 = 0; i8 < kTime; ++i8)
                                    for (int i9 = 0; i9 < kTime; ++i9) {
                                        std::vector<int> tmp{i1, i2, i3, i4, i5, i6, i7, i8, i9};
                                        if (check(tmp)) {
                                            int t = std::accumulate(tmp.begin(), tmp.end(), 0);
                                            if (t < min_time) {
                                                min_time = t;
                                                res = tmp;
                                            }
                                        }
                                    }
    bool first = true;
    for (int i = 0; i < kMaxN; ++i) {
        while (res[i]--) {
            if (first) {
                std::cout << i + 1;
                first = false;
            } else {
                std::cout << ' ' << i + 1;
            }
        }
    }
    std::cout << std::endl;
}