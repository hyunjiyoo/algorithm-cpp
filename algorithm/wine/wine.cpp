#include <iostream>
#include <algorithm>

int n;
int wine[10'000];
int DP[10'000][3];

void init() {
    for (int i = 0; i < n; ++i) {
        std::scanf("%d", &wine[i]);
        DP[i][0] = -1;
        DP[i][1] = -1;
        DP[i][2] = -1;
    }
    
    DP[0][0] = 0;
    DP[0][1] = wine[0];
    DP[0][2] = 0;
    
}

void solve() {
    
    for (int i = 1; i < n; ++i) {
        DP[i][0] = std::max({ DP[i-1][0], DP[i-1][1], DP[i-1][2] });
        DP[i][1] = DP[i-1][0] + wine[i];
        DP[i][2] = DP[i-1][1] + wine[i];
    }
}


int main(int argc, const char * argv []) {
    std::scanf("%d", &n);
    
    init();
    solve();
    
    std::printf("%d", std::max({ DP[n-1][0], DP[n-1][1], DP[n-1][2] }));
    
    return 0;
}
