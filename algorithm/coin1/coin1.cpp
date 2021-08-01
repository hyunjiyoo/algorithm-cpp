#include <iostream>
#include <algorithm>
#include <vector>

int n, k;
std::vector<int> coin;
std::vector<std::vector<int>> dp;
std::vector<int> R;


void input() {
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    
    R.resize(k);
    
    dp.resize(n);
    for (int i = 0; i < n; ++i)
        dp[i].resize(k);
    
    coin.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> coin[i];
        
        for (int j = 1; j <= k; ++j) {
            dp[i][j - 1] = j % coin[i];
        }
    }
}

void solve() {
    
    for (int i = 0; i < k; ++i) {
        R[i] = dp[0][i];
    }
    
    for (int i = 1; i < n; ++i) {
        
        for (int j = 1; j < k; ++j) {
            
            std::cout << "R[j]: " << R[j] << " dk: " << R[j - 1] + dp[i][j] << std::endl;
            
            if (dp[i][j])
                R[j] = R[j - 1] + dp[i][j];
            else
                R[j] = std::max(R[j], R[j - 1]);
        }
    }
}



int main (int argc, const char * argv []) {
    
    input();
    solve();
    

    return 0;
}
