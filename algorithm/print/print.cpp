#include <iostream>
#include <string>

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    std::string str;
    while (true) {
        getline(std::cin, str);
        if(str.empty()) break;
        std::cout << str << std::endl;
    }
    
    return 0;
}
