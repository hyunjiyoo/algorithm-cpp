#include <iostream>

int n, k;
int coin[100];
int dp[10'001];

void solve() {
    dp[0] = 1;
    
    for (int i = 0; i < n; ++i) {
        
        for (int j = 1; j <= k; ++j) {
         
            if (j >= coin[i])
                dp[j] += dp[j - coin[i]];
        }
    }
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    std::fill_n((int*)dp, 10'001, 0);
    
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i)
        std::cin >> coin[i];

    solve();
    
    std::cout << dp[k];
    
    return 0;
}
