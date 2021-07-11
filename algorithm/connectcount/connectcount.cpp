#include <iostream>

int N, M, R;
bool edge[1'001][1'001];

void init() {
    R = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            edge[i][j] = false;
        }
    }
}

void input() {
    
    for (int i = 0; i < M; ++i) {
        int u, v;
        std::scanf("%d %d", &u, &v);
        edge[u][v] = edge[v][u] = true;
    }
    
    for (int i = 1; i <= N; ++i)
        edge[i][i] = true;
}


void dfs(int u) {
    
    for (int j = 1; j <= N; ++j) {
        if (edge[u][j]) {
            edge[u][j] = edge[j][u] = false;
            dfs(j);
        }
    }
}


void solve() {
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (edge[i][j]) {
                dfs(i);
                ++R;
            }
        }
    }
    
    
}


int main (int argc, const char * argv []) {
    
    std::scanf("%d %d", &N, &M);
    init();
    input();
    solve();
    std::printf("%d", R);
    
    return 0;
}
