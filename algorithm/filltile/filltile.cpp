#include <iostream>

int N;
int dp[31] = { 1, 0, 3, };

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    std::cin >> N;
    
    for (int i = 4; i <= N; ++i) {
        
        if (i & 1) continue;
        
        for (int j = 0; j < i; ++j) {
            if (j & 1) continue;
            dp[i] += (dp[j] * 2);
        }
        
        dp[i] += dp[i - 2];
    }
    
    std::cout << dp[N];
    
    return 0;
}
