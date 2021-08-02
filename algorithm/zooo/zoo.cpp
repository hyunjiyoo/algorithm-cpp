#include <iostream>

int N;
int dp[100'000][3];

void input() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin >> N;
}

void solve() {
    
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    
    for (int i = 1; i < N; ++i) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
    }
    
    std::cout << (dp[N - 1][0] + dp[N - 1][1] + dp[N - 1][2]) % 9901;
}

int main (int argc, const char * argv []) {
    
    input();
    solve();
    
    return 0;
}
