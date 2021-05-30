#include <iostream>

void setBinary(int num) {
    if (num == 0)
        return;
    
    setBinary(num / 2);
    std::cout << num % 2;
}

int main(int argc, const char* argv[]) {
    while (true) {
        int num = 0;
        std::cin >> num;
            
        if (num < 0)
            break;
        
        if (num == 0)
            std::cout << "0";
        else
            setBinary(num);
        
        std::cout << std::endl;
    }
    return 0;
}
