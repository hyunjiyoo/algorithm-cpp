#include <iostream>
#include <algorithm>

int n, r;
int house[1000][3];
int dp[1000][3];

int main (int argc, const char * argv []) {
    
    std::scanf("%d", &n);
    
    for (int i = 0; i < n; ++i)
        std::scanf("%d %d %d", &house[i][0], &house[i][1], &house[i][2]);
    
    dp[0][0] = house[0][0];
    dp[0][1] = house[0][1];
    dp[0][2] = house[0][2];
    
    for (int i = 1; i < n; ++i) {
        dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
        dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
        dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
    }
    
    r = std::min({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] });
    std::printf("%d", r);
    
    return 0;
}
