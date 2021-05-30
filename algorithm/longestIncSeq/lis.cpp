#include <iostream>

int C, N;
int seq[500];
int DP[500];
int R;

void init() {
    R = 0;
    
    for (int i = 0; i < 500; ++i) {
        seq[i] = 0;
        DP[i] = 1;
    }
}

void input() {
    std::scanf("%d", &N);
    
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", seq + i);
    }
}


void solve() {
    
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (seq[i] < seq[j])
                DP[j] = std::max(DP[j], DP[i] + 1);
        }
    }
    
    for (int i = 0; i < N; ++i)
        R = std::max(R, DP[i]);
}


int main (int argc, const char * argv []) {
    std::scanf("%d", &C);
    
    for (int i = 0; i < C; ++i) {
        init();
        input();
        solve();
        
        std::printf("%d\n", R);
    }

    return 0;
}
