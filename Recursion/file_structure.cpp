// http://cxsjsx.openjudge.cn/hw202213/B/
#include <iostream>
#include <vector>
#include <algorithm>

const std::string str = "|     ";
int rank = 0;
int num = 0;

void print_vec(std::vector<std::string> &vec) {
    std::sort(vec.begin(), vec.end());
    for (const auto &i: vec) {
        for (int j = rank; j > 0; --j) {
            std::cout << str;
        }
        std::cout << i << std::endl;
    }
}

void load_dir() {
    std::string tmp;
    std::vector<std::string> vec;
    while (std::cin >> tmp) {
        if (tmp == "#") {
            print_vec(vec);
            std::exit(0);
        } else if (tmp == "*") {
            rank = 0;
            print_vec(vec);
            std::cin.get();
            char c = std::cin.peek();
            if (c != '#') {
                std::cout << std::endl;
                std::cout << "DATA SET " << ++num << ':' << std::endl;
                std::cout << "ROOT" << std::endl;
            }
            load_dir();
        } else if (tmp[0] == 'd') {
            ++rank;
            for (int j = rank; j > 0; --j) {
                std::cout << str;
            }
            std::cout << tmp << std::endl;
            load_dir();
            std::cin.ignore();
            --rank;
        } else if (tmp == "]") {
            print_vec(vec);
            return;
        } else {
            vec.push_back(tmp);
        }
    }
}

int main() {
    std::cout << "DATA SET " << ++num << ':' << std::endl;
    std::cout << "ROOT" << std::endl;
    load_dir();
}
