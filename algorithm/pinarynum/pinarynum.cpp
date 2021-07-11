#include <iostream>

int N, R;
int64_t dp[91] = { 0, 1, 1, 2, };

void solve() {
    for (int i = 4; i < 91; ++i)
        dp[i] = dp[i - 2] + dp[i - 1];
    
}

int main (int argc, const char * argv []) {
    
    std::scanf("%d", &N);
    solve();
    std::printf("%lld", dp[N]);
    
    
    return 0;
}
