// http://cxsjsx.openjudge.cn/hw202213/
#include <iostream>
#include <algorithm>

bool val_expression();

bool val_item();

bool val_factor();

int pos = 0;
int length = 0;
std::string str;

int main() {
    int num = 0;
    while (std::getline(std::cin, str)) {
        pos = 0;
        str.erase(std::remove_if(str.begin(), str.end(), [](char c) {
            return c == ' ';
        }), str.end());
//        std::cout << str << std::endl;
        length = str.length();
        std::cout << "Expression " << ++num << ": ";
        bool res = val_expression();
        if (res) {
            std::cout << 'V' << std::endl;
        } else {
            std::cout << 'F' << std::endl;
        }
    }
}

bool val_expression() {
    bool res = val_item();
    while (pos < length && str[pos] == '|') {
        ++pos;
        bool tmp = val_item();
        res = res | tmp;
    }
    return res;
}

bool val_item() {
    bool res = val_factor();
    while (pos < length && str[pos] == '&') {
        ++pos;
        bool tmp = val_factor();
        res = res & tmp;
    }
    return res;
}

bool val_factor() {
    char c = str[pos];
    if (c == '(') {
        ++pos;
        bool tmp = val_expression();
        ++pos;
        return tmp;
    } else if (c == '!') {
        ++pos;
        bool tmp = val_factor();
        return !tmp;
    } else if (c == 'V') {
        ++pos;
        return true;
    } else if (c == 'F') {
        ++pos;
        return false;
    } else {
        throw "error";
    }
}
