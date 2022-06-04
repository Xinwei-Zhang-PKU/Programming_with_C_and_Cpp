// http://cxsjsx.openjudge.cn/hw202214/C/
#include <iostream>
#include <vector>

using std::cin, std::cout, std::vector, std::endl;
vector<int> heights;

int main() {
    int K;
    cin >> K;
    while (K--) {
        heights.clear();
        int N;
        int res = 0;
        cin >> N;
        vector<int> dp_left(N);
        vector<int> dp_right(N);
        for (int j = 0; j < N; ++j) {
            int h;
            cin >> h;
            heights.push_back(h);
        }
        for (int i = 0; i < N; ++i) {
            dp_left[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (heights[j] < heights[i]) {
                    dp_left[i] = std::max(dp_left[i], dp_left[j] + 1);
                }
            }
            res = std::max(res, dp_left[i]);
        }
        for (int i = N - 1; i >= 0; --i) {
            dp_right[i] = 1;
            for (int j = N - 1; j > i; --j) {
                if (heights[j] < heights[i]) {
                    dp_right[i] = std::max(dp_right[i], dp_right[j] + 1);
                }
            }
            res = std::max(res, dp_right[i]);
        }
        cout << res << endl;
    }
}
