#include <iostream>

int T, n;
int dp[100'001][3] = { { 0,0,0 }, { 1,0,0 }, { 1,0,0}, { 1,1,1 }, { 2,0,1 }, { 1,2,1 }, { 3,3,2 }, };


void solve() {
    
    for (int i = 7; i < 100'001; ++i) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 1'000'000'009;
        dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % 1'000'000'009;
        dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % 1'000'000'009;
    }
}


int main (int argc, const char * argv []) {
    
    solve();
    
    std::scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        std::scanf("%d", &n);
        int sum = (((dp[n][0] + dp[n][1]) % 1'000'000'009) + dp[n][2]) % 1'000'000'009;
        std::printf("%d\n", sum);
    }
    
    return 0;
}
