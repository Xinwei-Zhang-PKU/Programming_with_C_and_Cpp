// http://cxsjsx.openjudge.cn/hw202212/A/

#include <iostream>
#include <vector>
#include <limits>

int a[9];
int b[9];
std::vector<int> res;
int min_num = std::numeric_limits<int>::max();

int main() {
    for (int &i: a) {
        std::cin >> i;
    }
    for (int i1 = 0; i1 < 4; ++i1)
        for (int i2 = 0; i2 < 4; ++i2)
            for (int i3 = 0; i3 < 4; ++i3)
                for (int i4 = 0; i4 < 4; ++i4)
                    for (int i5 = 0; i5 < 4; ++i5)
                        for (int i6 = 0; i6 < 4; ++i6)
                            for (int i7 = 0; i7 < 4; ++i7)
                                for (int i8 = 0; i8 < 4; ++i8)
                                    for (int i9 = 0; i9 < 4; ++i9) {
                                        b[0] = a[0] + i1 + i2 + i4;
                                        b[1] = a[1] + i1 + i2 + i3 + i5;
                                        b[2] = a[2] + i2 + i3 + i6;
                                        b[3] = a[3] + i1 + i4 + i5 + i7;
                                        b[4] = a[4] + i1 + i3 + i5 + i7 + i9;
                                        b[5] = a[5] + i3 + i5 + i6 + i9;
                                        b[6] = a[6] + i4 + i7 + i8;
                                        b[7] = a[7] + i5 + i7 + i8 + i9;
                                        b[8] = a[8] + i6 + i8 + i9;
                                        if (std::all_of(b, b + 9, [](int x) {
                                            return !(x % 4);
                                        })) {
                                            int num = i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9;
                                            if (num < min_num) {
                                                min_num = num;
                                                std::vector<int> tmp{i1, i2, i3, i4, i5, i6, i7, i8, i9};
                                                res = tmp;
                                            }
                                        }
                                    }
    bool first = true;
    for (int i = 0; i < 9; ++i) {
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
