#include <iostream>
#include <algorithm>

int N, R;
int S[10'001];
int W[10'001][3];

void solve() {
    W[1][0] = 0;
    W[1][1] = S[1];
    W[1][2] = 0;
    
    for(int i = 2; i <= N; ++i) {
        W[i][0] = std::max({ W[i - 1][0], W[i - 1][1], W[i - 1][2] });
        W[i][1] = W[i - 1][0] + S[i];
        W[i][2] = W[i - 1][1] + S[i];
    }
    
    R = std::max({ W[N][0], W[N][1], W[N][2] });
}

int main(int argc, const char* argv[]) {
    
    std::scanf("%d", &N);
    
    for(int i = 1; i <= N; ++i) {
        std::scanf("%d", S + i);
    }
    
    solve();
    
    std::printf("%d", R);
    
    return 0;
}
