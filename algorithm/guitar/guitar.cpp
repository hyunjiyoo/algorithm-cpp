#include <iostream>
#include <algorithm>

int N, S, M;
int V[101];
bool F[101][1'001];

void isolve(int idx = 1) {
    if (idx > N)
        return;
    
    bool empty = true;
    
    for (int i = 0; i <= M; ++i) {
        if (F[idx - 1][i]) {
            empty = false;
            
            if (0 <= i - V[idx])
                F[idx][i - V[idx]] = true;
            
            if (i + V[idx] <= M)
                F[idx][i + V[idx]] = true;
            
        }
    }
    
    if (!empty)
        isolve(idx + 1);
}

int solve() {
    isolve();
    
    int result = -1;
    for (int i = M; i >= 0; --i) {
        if (F[N][i]) {
            result = i;
            break;
        }
    }
    return result;
}

void init() {
    N = S = M = 0;
    for (int i = 0; i < 101; ++i)
        V[i] = 0;
    
    for (int i = 0; i < 101; ++i)
        for (int j = 0; j < 1001; ++j)
            F[i][j] = false;
}
    
void input() {
    std::scanf("%d %d %d", &N, &S, &M);
    V[0] = S;
    
    for (int i = 1; i <= N; ++i)
        std::scanf("%d", &V[i]);
    
    F[0][S] = true;
}

int main(int argc, const char * argv []) {
    init();
    input();
    std::printf("%d", solve());
    return 0;
}
