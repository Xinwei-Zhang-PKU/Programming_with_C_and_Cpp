// http://cxsjsx.openjudge.cn/hw202216/A/

#include <iostream>
#include <queue>
#include <utility>

using std::cin, std::cout, std::endl;

int maze[5][5];
std::pair<int, int> res[5][5];
bool visited[5][5];
int move_x[]{1, -1, 0, 0};
int move_y[]{0, 0, 1, -1};

struct point {
    int x, y;

    point(int x, int y) : x(x), y(y) {

    }
};

bool inBorder(int x, int y) {
    return (0 <= x) && (x < 5) && (0 <= y) && (y < 5);
}

int main() {
    for (auto &i: maze)
        for (int &j: i) {
            cin >> j;
        }
    std::queue<point> que;
    point end(4, 4);
    que.push(end);
    visited[4][4] = true;
    while (!que.empty()) {
        point tmp = que.front();
        int x = tmp.x;
        int y = tmp.y;
        if (x == 0 && y == 0)
            break;
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int next_x = x + move_x[i];
            int next_y = y + move_y[i];
            if (!visited[next_x][next_y] && inBorder(next_x, next_y) && maze[next_x][next_y] == 0) {
                point next(next_x, next_y);
                que.push(next);
                res[next_x][next_y] = std::make_pair(x, y);
                visited[next_x][next_y] = true;
            }
        }
    }
    int x = 0, y = 0;
    while (!(x == 4 && y == 4)) {
        cout << '(' << x << ',' << ' ' << y << ')' << endl;
        std::pair<int, int> next_point = res[x][y];
        x = next_point.first;
        y = next_point.second;
    }
    cout << "(4, 4)" << endl;
}
