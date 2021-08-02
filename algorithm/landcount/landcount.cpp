#include <iostream>

int w, h, ans;
bool land[50][50];
bool visited[50][50];

const int offset[8][2] = {
    { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, 1 },
    { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }
};

void input() {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            std::cin >> land[i][j];
            visited[i][j] = false;
        }
    }
    
    ans = 0;
}


void dfs(int y, int x) {
    
    for (int i = 0; i < 8; ++i) {
        int ny = y + offset[i][0];
        int nx = x + offset[i][1];
        
        if (!(0 <= ny && ny < h) || !(0 <= nx && nx < w)) continue;
        
        if (!visited[ny][nx] && land[ny][nx]) {
            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
}


void solve() {
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j] && land[i][j]) {
                dfs(i, j);
                ++ans;
            }
        }
    }
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    while (true) {
        
        std::cin >> w >> h;
        if (w == 0 && h == 0) break;
        
        input();
        solve();
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}
