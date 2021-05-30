#include <iostream>

int N, R;
int DP[1'001];

void solve() {
    DP[0] = DP[1] = 1;
    
    for (int i = 2; i <= N; ++i)
        DP[i] = (DP[i - 1] + DP[i - 2] * 2) % 10'007;
    
    R = DP[N];
}

int main(int argc, const char* argv[]) {
    
    std::scanf("%d", &N);
    solve();
    std::printf("%d", R);
    
    return 0;
}
