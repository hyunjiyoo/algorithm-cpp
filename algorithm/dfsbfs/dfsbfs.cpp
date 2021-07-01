#include <iostream>
#include <queue>
#include <vector>

int N, M, V;
std::vector<bool> visited;
std::vector<std::vector<bool>> v;
std::queue<int> q;

void input() {
    std::scanf("%d %d %d", &N, &M, &V);
    
    v.resize(N + 1);
    visited.resize(N + 1);
    for (int i = 0; i <= N; ++i)
        v[i].resize(N + 1);
    
    for (int i = 0; i < M; ++i) {
        int v1, v2;
        std::scanf("%d %d", &v1, &v2);
        v[v1][v2] = v[v2][v1] = true;
    }
}

void init() {
    std::fill_n(visited.begin(), N + 1, false);
    visited[V] = true;
}

void dfs(int pos = V) {
    
    std::printf("%d ", pos);
    
    for (int i = 1; i <= N; ++i) {
        if (!visited[i] && v[pos][i]) {
            visited[i] = true;
            dfs(i);
        }
    }
}

void bfs() {
    
    std::printf("\n");
    q.push(V);
    visited[V] = true;
    
    while (!q.empty()) {
        int pos = q.front();
        std::printf("%d ", pos);
        
        for (int i = 1; i <= N; ++i) {
            if (!visited[i] && v[pos][i]) {
                q.push(i);
                visited[i] = true;
            }
        }
        
        q.pop();
    }
}


int main (int argc, const char * argv []) {
    
    input();
    
    init();
    dfs();
    
    init();
    bfs();
    
    return 0;
}
