#include <iostream>
// top -> bottom (top - down)
// bottom -> top (bottom - up)

int count = 0;
int dp[11] = { 0, 1, 2, 4, -1, -1, -1, -1, -1, -1, -1};

int sum(int num) {
    if (dp[num] != -1) {
        return dp[num];
    } else {
        dp[num] = sum(num-1) + sum(num-2) + sum(num-3);
        
        return dp[num];
    }
}


int main(int argc, const char * argv[]) {
    
    int case_cnt;
    std::cin >> case_cnt;
    
    int n;
    for (int i = 0; i < case_cnt; ++i) {
        count = 0;
        
        std::cin >> n;
            
        std::cout << sum(n) << std::endl;
        
        std::cout << count << std::endl;
    }
    
    return 0;
}
