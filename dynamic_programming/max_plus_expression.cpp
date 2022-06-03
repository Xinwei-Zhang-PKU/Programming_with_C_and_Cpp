// http://cxsjsx.openjudge.cn/hw202214/B/
#include <iostream>
#include <utility>

const int kMaxN = 60;
const std::string kMaxString(kMaxN, '9');

std::string add(std::string &first, std::string &second) {
    if (first.length() < second.length()) {
        std::swap(first, second);
    }
    size_t length_first = first.length();
    size_t length_second = second.length();
    std::string zeros(length_first - length_second, '0');
    second = zeros + second;
    std::string res;
    int up_digit = 0;
    for (int i = length_first - 1; i >= 0; --i) {
        char c = first[i] + second[i] - '0' + up_digit;
        if (c > '9') {
            c -= 10;
            up_digit = 1;
        } else {
            up_digit = 0;
        }
        res = c + res;
    }
    if (up_digit == 1) {
        res = '1' + res;
    }
    return res;
}

class num {
public:
    std::string str;

    bool operator<(const num &other) const {
        size_t length = str.length();
        size_t other_length = other.str.length();
        if (length == other_length) {
            return str < other.str;
        } else {
            return length < other_length;
        }
    }

    num operator+(const num &other) const {
        std::string other_str = other.str;
        std::string this_str = str;
        std::string res = add(this_str, other_str);
        return num{res};
    }

    explicit num(std::string str) : str(std::move(str)) {
    }

    num() = default;
};

int m;
std::string str;
std::string dp[kMaxN][kMaxN];

int main() {
    while (std::cin >> m >> str) {
        int length = str.length();
        for (int i = 1; i <= length; ++i)
            dp[i][0] = str.substr(0, i);
        for (int str_length = 1; str_length <= length; ++str_length) {
            for (int plus_num = 1; plus_num <= str_length - 1 && plus_num <= m; ++plus_num) {
                num res{kMaxString};
                for (int pos = plus_num; pos < str_length; ++pos) {
                    std::string next{str.substr(pos, str_length - pos)};
                    num first{dp[pos][plus_num - 1]};
                    num second{next};
                    num tmp{first + second};
                    res = std::min(res, tmp);
                }
                dp[str_length][plus_num] = res.str;
            }
        }
        std::cout << dp[length][m] << std::endl;
    }
}
