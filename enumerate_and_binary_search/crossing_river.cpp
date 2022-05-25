//http://cxsjsx.openjudge.cn/hw202212/D/

#include <iostream>
#include <vector>

int main() {
    int L, N, M;
    std::cin >> L >> N >> M;
    std::vector<int> position(N + 2);
    position[0] = 0;
    position[N + 1] = L;
    for (int i = 1; i <= N; ++i) {
        std::cin >> position.at(i);
    }
    int res = 0;
    int sta = 0, end = position.at(N + 1);
    while (sta <= end) {
        int mid = sta + (end - sta) / 2;
        int num = 0;
        for (int i = 0; i < N + 2; ++i) {
            int now = position.at(i);
            for (int j = i + 1; j < N + 2; ++j) {
                if (position.at(j) - now < mid) {
                    ++num;
                } else {
                    i = j - 1;
                    break;
                }
            }
        }
        if (num > M) {
            end = mid - 1;
        } else {
            res = mid;
            sta = mid + 1;
        }
    }
    std::cout << res << std::endl;
}
