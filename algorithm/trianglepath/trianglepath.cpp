#include <iostream>

int C, N;
int T[100][100];
int DP[100][100];
int R;

void init() {
    R = 0;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            T[i][j] = 0;
            DP[i][j] = 0;
        }
    }
}

void input() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::scanf("%d", &T[i][j]);
        }
    }
    
    DP[0][0] = T[0][0];
    
    for (int i = 1; i < N; ++i) {
        DP[i][0] = DP[i - 1][0] + T[i][0];
    }
}

void solve() {
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= i; ++j) {
            DP[i][j] = std::max(DP[i-1][j-1], DP[i-1][j]) + T[i][j];
        }
    }
}


int main (int argc, const char * argv []) {
    std::scanf("%d", &C);
    
    for (int i = 0; i < C; ++i) {
        
        std::scanf("%d", &N);
        init();
        input();
        solve();
        
        for (int j = 0; j < N; ++j)
            R = std::max(R, DP[N - 1][j]);
        
        std::cout << R << std::endl;
    }
    
    return 0;
}
