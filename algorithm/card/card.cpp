#include <iostream>
int N;
int P[1'001];
int DP[1'001];
int R;

void input() {
    std::scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        std::scanf("%d", P + i);
    }
}

void init() {
    R = -1;
    for (int i = 0; i <= N; ++i) {
        DP[i] = 0;
    }
    DP[1] = P[1];
}


void solve() {
    int tmp = -1;
    
    for (int i = 2; i <= N; ++i) {
        
        for (int j = i / 2; j < i; ++j) {
            
            if (DP[j] + P[i - j] >= tmp)
                tmp = DP[j] + P[i - j];
        }
        
        DP[i] = std::max(tmp, P[i]);
    }
}



int main(int argc, const char * argv []) {
    input();
    init();
    solve();
    
    std::printf("%d", DP[N]);
    
    return 0;
}
