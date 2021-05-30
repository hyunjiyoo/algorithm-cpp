#include <iostream>

// top -> bottom (top - down)
// bottom -> top (bottom - up)
int sum(int num) {
    
    if (num == 1)
        return 1;
    
    if (num == 2)
        return 2;
    
    if (num == 3)
        return 4;
    
    return sum(num+3) - sum(num+2) - sum(num+1);
}


int main(int argc, const char * argv[]) {
    
    int case_cnt;
    std::cin >> case_cnt;
    
    int n;
    for (int i = 0; i < case_cnt; ++i) {
        std::cin >> n;
            
        std::cout << sum(n) << std::endl;
    }
    
    return 0;
}
