#include <iostream>
#include <vector>

const int offset[8][2] = { {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} };

int w, h, cnt;
std::vector<std::vector<bool>> island, visited;

void init() {
    cnt = 0;
    island.clear();
    visited.clear();
    
    island.resize(h);
    visited.resize(h);
    
    for (int i = 0; i < h; ++i) {
        island[i].resize(w);
        visited[i].resize(w);
    }
}

void input() {
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int tmp;
            std::scanf("%d", &tmp);
            island[i][j] = tmp;
        }
    }
}

void dfs (int y, int x) {
    
    for (int i = 0; i < 8; ++i) {
        int ny = y + offset[i][0];
        int nx = x + offset[i][1];
        
        if (!(0 <= ny && ny < h) || !(0 <= nx && nx < w)) continue;
        
        if (!visited[ny][nx] && island[ny][nx]) {
            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
}


void solve() {
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j] && island[i][j]) {
                visited[i][j] = true;
                dfs(i, j);
                cnt++;
            }
        }
    }
}


int main (int argc, const char * argv []) {
    
    while (true) {
        std::cin >> w >> h;
        if (w == 0 && h == 0) break;
        
        init();
        input();
        solve();
        std::printf("%d\n", cnt);
    }
    
    return 0;
}
