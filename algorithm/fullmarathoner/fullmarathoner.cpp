#include <iostream>
#include <string>
#include <set>

int N;
std::multiset<std::string> s;

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::string str;
        std::cin >> str;
        s.insert(str);
    }
    
    while (1) {
        std::string str;
        std::cin >> str;
        if (std::cin.eof()) break;
        s.erase(s.find(str));
    }
    
    for (auto name : s)
        std::cout << name << std::endl;
    
    return 0;
}
