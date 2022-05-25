//http://cxsjsx.openjudge.cn/hw202212/B/
#include<iostream>
#include<string>

void change(char &c) {
    if (c == '0')
        c = '1';
    else if (c == '1')
        c = '0';
}

int main() {
    std::string a, b, c;
    std::cin >> a >> b;
    c = a;
    auto length = a.length();
    bool flag_1 = true, flag_2 = true;
    int num_1 = 0, num_2 = 0;
    for (int i = 1; i < length; ++i) {
        if (c[i - 1] != b[i - 1]) {
            ++num_1;
            change(c[i]);
            change(c[i - 1]);
            change(c[i + 1]);
        }
    }
    if (c[length - 1] != b[length - 1]) {
        flag_1 = false;
    }
    c = a;
    change(c[0]);
    if (length > 1)
        change(c[1]);
    ++num_2;
    for (int i = 1; i < length; ++i) {
        if (c[i - 1] != b[i - 1]) {
            ++num_2;
            change(c[i]);
            change(c[i - 1]);
            change(c[i + 1]);
        }
    }
    if (c[length - 1] != b[length - 1]) {
        flag_2 = false;
    }
    if (flag_1 && flag_2) {
        int res = std::min(num_1, num_2);
        std::cout << res << std::endl;
    } else if (flag_1) {
        std::cout << num_1 << std::endl;
    } else if (flag_2) {
        std::cout << num_2 << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }
}
