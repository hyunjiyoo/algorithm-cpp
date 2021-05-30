#include <iostream>
int N;
int DP[1'001] = { 0, 1, 3, 5, 11, 21, 43, 85, 171, };


void solve() {
    for (int i = 2; i <= N; ++i) {
        if (i % 2 == 0)
            DP[i] = (DP[i - 1] * 2 + 1) % 10'007;
        else
            DP[i] = (DP[i - 1] * 2 - 1) % 10'007;
    }
}

int main(int argc, const char * argv []) {
    std::scanf("%d", &N);
    
    solve();
    
    std::printf("%d", DP[N]);
    
    return 0;
}
