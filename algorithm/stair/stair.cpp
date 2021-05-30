#include <iostream>
#include <cmath>

int N, R;
int STEP[301];
int DP[301][2];

void solve() {
    DP[1][0] = DP[1][1] = STEP[1];
    
    for (int i = 2; i <= N; ++i) {
        DP[i][0] = std::max(DP[i - 2][0], DP[i - 2][1]) + STEP[i];
        DP[i][1] = DP[i - 1][0] + STEP[i];
    }
    
    R = std::max(DP[N][0], DP[N][1]);
}

int main(int argc, const char* argv[]) {
    
    std::scanf("%d", &N);
    
    for (int i = 1; i <= N; ++i)
        std::scanf("%d", STEP + i);
    
    solve();
    
    std::printf("%d", R);
    
    return 0;
}
