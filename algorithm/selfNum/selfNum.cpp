#include <iostream>
#include <string>

bool disable[10'001];

int main (int argc, const char * argv []) {
    
    for (int i = 1; i <= 10'000; ++i) {
        int sum = i;
        std::string s = std::to_string(i);
        
        for (char c : s) 
            sum += (c - '0');
        
        disable[sum] = true;
    }
    
    for (int i = 1; i <= 10'000; ++i) {
        if (!disable[i])
            std::cout << i << std::endl;
    }
    
    return 0;
}
