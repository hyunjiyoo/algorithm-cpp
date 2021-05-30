#include <iostream>
#include <numeric>
#include <cstring>

int N, R;
int DP[1'001][10];
const int D = 10'007;

void solve() {
    std::memset(DP, 0, sizeof DP);
    
    DP[0][0] = 1;
    
    for (int i = 1; i <= N; ++i) {
        int accum = 0;
        
        for (int j = 0; j <= 9; ++j) {
            accum += DP[i - 1][j];
            DP[i][j] = accum % D;
        }
    }
    
    R = std::accumulate(DP[N], DP[N] + 10, 0) % D;
}

int main(int argc, const char* argv[]) {
    
    std::scanf("%d", &N);
    solve();
    std::printf("%d", R);
    
    return 0;
}
