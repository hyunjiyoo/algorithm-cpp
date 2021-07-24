#include <iostream>
#include <algorithm>

int n;
int wine[10'001];
int dp[10'001][3];

void input() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> wine[i];
}

void solve() {
    dp[0][0] = dp[0][1] = dp[0][2] = dp[1][0] = dp[1][2] = 0;
    dp[1][1] = wine[1];

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = std::max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
        dp[i][1] = dp[i - 1][0] + wine[i];
        dp[i][2] = dp[i - 1][1] + wine[i];
    }
    
    int R = std::max({ dp[n][0], dp[n][1], dp[n][2] });
    
    std::cout << R;
}

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve();
    
    return 0;
}
