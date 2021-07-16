#include <iostream>
#include <algorithm>

int n;
int w[10'002];
int dp[10'002][3];

void input() {
    std::scanf("%d", &n);
    w[0] = 0;
    for (int i = 0; i < n; ++i) {
        std::scanf("%d", &w[i + 1]);
    }
}

void solve() {
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    dp[1][0] = dp[1][2] = 0;
    dp[1][1] = w[1];
    
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = std::max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
        dp[i][1] = dp[i - 1][0] + w[i];
        dp[i][2] = dp[i - 1][1] + w[i];
    }
    
    int ret = std::max({ dp[n][0], dp[n][1], dp[n][2] });
    
    std::printf("%d", ret);
}

int main (int argc, const char * argv []) {
    
    input();
    solve();
    
    return 0;
}
