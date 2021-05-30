#include <iostream>
#include <string>
#include <stack>
#include <deque>

int C;
std::deque<char> s, pwd;
std::stack<char> tmp;

void init() {
    s.clear();
    pwd.clear();
    while(!tmp.empty()) tmp.pop();
}

void input() {
    std::string str;
    std::cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        s.push_back(str[i]);
    }
}

void solve() {
    char item;
    while (1) {
        if (s.empty()) {
            while (!tmp.empty()) {
                pwd.push_back(tmp.top());
                tmp.pop();
            }
            break;
        }
        
        item = s.front();
        s.pop_front();
        
        if (item == '<') {
            if (!pwd.empty()) {
                tmp.push(pwd.back());
                pwd.pop_back();
            }
        }
        else if (item == '>') {
            if (!tmp.empty()) {
                pwd.push_back(tmp.top());
                tmp.pop();
            }
        }
        else if (item == '-') {
            if (!pwd.empty())
                pwd.pop_back();
        }
        else {
            pwd.push_back(item);
        }
    }
}

void output() {
    while (1) {
        if (pwd.empty()) break;
        std::cout << pwd.front();
        pwd.pop_front();
    }
    std::cout << std::endl;
}

int main (int argc, const char * argv []) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin >> C;
    for (int i = 0; i < C; ++i) {
        init();
        input();
        solve();
        output();
    }
    
    return 0;
}
