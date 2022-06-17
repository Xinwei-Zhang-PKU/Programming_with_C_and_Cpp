// http://cxsjsx.openjudge.cn/hw202216/B/

#include <iostream>
#include <cstring>

using std::cin, std::cout, std::endl;

char chess[8][8];
int n, k;
long long res;
bool row[8];

void dfs(int col) {
    if (k == 0) {
        ++res;
        return;
    }
    if (col >= n)
        return;
    for (int i = 0; i < n; ++i) {
        if (!row[i] && chess[col][i] == '#') {
            row[i] = true;
            --k;
            dfs(col + 1);
            row[i] = false;
            ++k;
        }
    }
    dfs(col + 1);
}

int main() {
    while (cin >> n >> k) {
        if (n == -1 && k == -1) {
            break;
        }
        res = 0;
        memset(chess, '.', sizeof chess);
        memset(row, 0, sizeof row);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> chess[i][j];
            }
        }
        dfs(0);
        cout << res << endl;
    }
}
