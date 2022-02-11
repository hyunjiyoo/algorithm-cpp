#include <iostream>
#include <algorithm>

int n, m;
int candy[1001][1001];
int dp[1001][1001];

int main (int argc, const char * argv []) {
    
    std::scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::scanf("%d", &candy[i][j]);
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = std::max({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + candy[i][j];
    
    std::printf("%d", dp[n][m]);
    
    return 0;
}
