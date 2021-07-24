#include <iostream>

int n;
int dp[1'001] = { 1, 1, 3, 5, };

int main(int argc, const char * argv[]) {
    
    std::ios::sync_with_stdio(false);
    
    std::cin >> n;
    
    for (int i = 3; i <= n; ++i) {
        if (i & 1)
            dp[i] = (dp[i - 1] * 2 - 1) % 10'007;
        else
            dp[i] = (dp[i - 1] * 2 + 1) % 10'007;
    }
    
    std::cout << dp[n];
    
    return 0;
}
