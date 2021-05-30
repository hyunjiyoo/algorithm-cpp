#include <iostream>
#include <algorithm>

int A, B, N, M;
int STONE[100'001];
int R;


void input() {
    std::scanf("%d %d %d %d", &A, &B, &N, &M);
}

void init() {
    R = 0x7fffffff;
    for (int i = 0; i < 100'000; ++i) {
        STONE[i] = 0;
    }
    STONE[N] = 1;
}


void solve(int n = N, int cnt = 1) {
    
    if (n == M) {
        R = std::min(R, cnt);
        return;
    }
        
    
    if (0 <= n && n <= 100'000) {
        
        int W1 = n * A;
        if (W1 <= M) {
            if (!STONE[W1] || STONE[W1] > cnt) {
                STONE[W1] = cnt;
                solve(W1, cnt + 1);
            }
        }
        
        int W2 = n * B;
        if (W2 <= M) {
            if (!STONE[W2] || STONE[W2] > cnt) {
                STONE[W2] = cnt;
                solve(W2, cnt + 1);
            }
        }
        
        int W3 = n + A;
        if (W3 <= M) {
            if (!STONE[W3] || STONE[W3] > cnt) {
                STONE[W3] = cnt;
                solve(W3, cnt + 1);
            }
        }
        
        int W4 = n + B;
        if (W4 <= M) {
            if (!STONE[W4] || STONE[W4] > cnt) {
                STONE[W4] = cnt;
                solve(W4, cnt + 1);
            }
        }
        
        int W5 = n + 1;
        if (W5 <= M) {
            if (!STONE[W5] || STONE[W5] > cnt) {
                STONE[W5] = cnt;
                solve(W5, cnt + 1);
            }
        }
        
        int W6 = n - 1;
        if (W6 >= 0) {
            if (!STONE[W6] || STONE[W6] > cnt) {
                STONE[W6] = cnt;
                solve(W6, cnt + 1);
            }
        }
        
        int W7 = n - A;
        if (W7 >= 0) {
            if (!STONE[W7] || STONE[W7] > cnt) {
                STONE[W7] = cnt;
                solve(W7, cnt + 1);
            }
        }
        
        int W8 = n - B;
        if (W8 >= 0) {
            if (!STONE[W8] || STONE[W8] > cnt) {
                STONE[W8] = cnt;
                solve(W8, cnt + 1);
            }
        }
        
    }

    return;
}


void output() {
    std::printf("%d", R - 1);
}

int main(int argc, const char* argv[]) {

    input();
    init();
    solve();
    output();

    return 0;
}
