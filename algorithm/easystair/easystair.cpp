#include <iostream>

int N, count;
int dp[100][9] = {
    { 1,1,1,1,1,1,1,1,1 },
    { 2,2,2,2,2,2,2,2,1 },
    { 3,4,4,4,4,4,4,3,2 }
};


void solve() {
    
    for (int i = 2; i < 100; ++i) {
        dp[i][0] = (dp[i - 1][8] + dp[i - 1][1]) % 1'000'000'000;
        for (int j = 1; j < 8; ++j) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1'000'000'000;
        }
        dp[i][8] = dp[i - 1][7];
    }
    
    count = 0;
    for (int i = 0; i < 9; ++i) {
        count = (count + dp[N - 1][i]) % 1'000'000'000;
    }
    
}

int main (int argc, const char * argv []) {
    
    std::scanf("%d", &N);
    solve();
    std::printf("%d", count);
    
    return 0;
}
