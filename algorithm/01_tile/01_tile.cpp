#include <iostream>

int n;
int dp[1'000'001];

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    std::cin >> n;
    
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    
    std::cout << dp[n] % 15746;
    
    return 0;
}
