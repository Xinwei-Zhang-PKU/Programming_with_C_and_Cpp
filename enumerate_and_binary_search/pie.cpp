//http://cxsjsx.openjudge.cn/hw202212/C/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>

const double pi = M_PI;
const double eps = 1e-5;
const int kMaxN = 10010;
int N, F;
double v[kMaxN];
double res = 0;

bool check(double x) {
    int num = 0;
    for (int i = 0; i < N; ++i) {
        num += static_cast<int>(v[i] / x);
    }
    if (num >= F)
        return true;
    else
        return false;
}

int main() {
    std::cin >> N >> F;
    ++F;
    for (int i = 0; i < N; ++i) {
        int x;
        std::cin >> x;
        v[i] = pi * x * x;
    }
    double sta = 0, end = *std::max_element(v, v + N);
    while (sta + eps < end) {
        double tmp = sta + (end - sta) / 2;
        if (check(tmp)) {
            res = tmp;
            sta = tmp;
        } else {
            end = tmp;
        }
    }
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(3);
    std::cout << res << std::endl;
}
