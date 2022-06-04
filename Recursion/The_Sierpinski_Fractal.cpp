// http://cxsjsx.openjudge.cn/hw202213/C/
#include <iostream>

using std::cin, std::cout, std::endl;
const int kMaxN = (1 << 11);
char triangle[kMaxN][kMaxN];

void fill(int x, int y, int size) {
    if (size == 1) {
        triangle[x + 1][y] = triangle[x][y + 1] = '/';
        triangle[x][y + 2] = triangle[x + 1][y + 3] = '\\';
        triangle[x + 1][y + 1] = triangle[x + 1][y + 2] = '_';
        return;
    } else {
        fill(x + (1 << (size - 1)), y, size - 1);
        fill(x, y + (1 << (size - 1)), size - 1);
        fill(x + (1 << (size - 1)), y + (1 << size), size - 1);
    }
}

int main() {
    int n;
    while (cin >> n, n) {
        memset(triangle, ' ', sizeof(triangle));
        fill(0, 0, n);
        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < (2 << n); ++j)
                cout << triangle[i][j];
            cout << endl;
        }
    }
}
