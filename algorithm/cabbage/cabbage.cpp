#include <iostream>
#include <queue>

int T, M, N, K, R;
int area[52][52];
bool visited[52][52];
std::queue<std::pair<int, int>> q;


void init() {
    R = 0;
    
    for (int i = 0; i < 52; ++i) {
        for (int j = 0; j < 52; ++j) {
            area[i][j] = -2;
            visited[i][j] = false;
        }
    }
}

void input() {
    
    std::scanf("%d %d %d", &M, &N, &K);
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            area[i][j] = 0;
        }
    }
    
    int y, x;
    for (int i = 0; i < K; ++i) {
        std::scanf("%d %d", &x, &y);
        area[y + 1][x + 1] = 1;
    }
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (area[i][j] == 1) {
                q.push({i, j});
                visited[i][j] = true;
                return;
            }
        }
    }
}


void dfs(int y, int x) {
    int offset[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    for (int i = 0; i < 4; ++i) {
        int dy = y + offset[i][0];
        int dx = x + offset[i][1];
        
        if (!visited[dy][dx] && area[dy][dx] == 1) {
            visited[dy][dx] = true;
            dfs(dy, dx);
        }
    }
}

void solve() {
    
    int y, x;
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        
        dfs(y, x);
        ++R;
        
        bool flag = false;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (!visited[i][j] && area[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        
        q.pop();
    }
}

int main (int argc, const char * argv []) {
    
    std::scanf("%d", &T);
    
    for (int i = 0; i < T; ++i) {
        init();
        input();
        solve();
        std::printf("%d\n", R);
    }
    
    return 0;
}
