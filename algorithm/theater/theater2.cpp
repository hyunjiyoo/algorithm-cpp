#include <iostream>

int N;
int M;
int VIP[40];
int DIFF[40];
int DP[40];
int R;

void input() {
    std::scanf("%d\n%d", &N, &M);
    
    for (int i = 0; i < M; ++i) {
        std::scanf("%d", VIP + i);
    }
}


void init() {
    DP[0] = 1;
    DP[1] = 2;
    
    DIFF[0] = VIP[0] - 1;
    
    for (int i = 1; i < M; ++i)
        DIFF[i] = VIP[i] - VIP[i - 1] - 1;
    
    DIFF[M] = N - VIP[M - 1];
}

void solve() {
    
    for (int i = 2 ; i < N; ++i) {
        DP[i] = DP[i - 1] + DP[i - 2];
    }
    
    R = 1;
    for (int i = 0; i <= M; ++i) {
        if (DIFF[i] != 0)
            R *= DP[DIFF[i] - 1];
    }
}


int main(int argc, const char * argv []) {
    input();
    init();
    solve();
    
    std::printf("%d", R);
    
    return 0;
}
