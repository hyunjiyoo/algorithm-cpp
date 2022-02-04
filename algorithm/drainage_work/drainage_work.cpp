#include <iostream>

int n, x;
int pipe[100];
int len[100];
int dp[101][10'001];

void input() {
    std::scanf("%d %d", &n, &x);
    
    int l, c;
    for (int i = 0; i < n; ++i) {
        std::scanf("%d %d", &l, &c);
        pipe[i] = l;
        len[i] = c;
    }
}

void init() {
    std::fill_n((int*)dp, 101 * 10'001, -1);
}

int solve(int idx = n, int length = x) {
    
    if (idx < 0 || length < 0)
        return 0;
    
    if (idx == 0 && length == 0)
        return 1;
    
    if (dp[idx][length] == -1) {
        
        dp[idx][length] = 0;
        
        for (int i = 0; i <= len[idx - 1]; ++i)
            dp[idx][length] += solve(idx - 1, length - (pipe[idx - 1] * i));
    }
  
    return dp[idx][length];
}

int main (int argc, const char * argv []) {
    
    input();
    init();
    solve();
    std::printf("%d", dp[n][x]);
    
    return 0;
}
