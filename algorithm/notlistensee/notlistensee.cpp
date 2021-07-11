#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

int N, M, R;
std::vector<std::string> nm;

std::set<std::string> s;
std::set<std::string>::iterator it;


int main (int argc, const char * argv[]) {
    
    R = 0;
    std::cin >> N >> M;
    
    for (int i = 0; i < N; ++i) {
        std::string str;
        std::cin >> str;
        s.insert(str);
    }
    
    for (int i = 0; i < M; ++i) {
        std::string str;
        std::cin >> str;
        it = s.find(str);
        if (it != s.end()) {
            ++R;
            nm.push_back(*it);
        }
    }
    
    std::sort(nm.begin(), nm.end());
    
    std::cout << R << std::endl;
    for (auto name : nm)
        std::cout << name << std::endl;
    
    return 0;
}
