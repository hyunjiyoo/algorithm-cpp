#include <iostream>
#include <queue>
#include <string>

int T, H, W, R;
int field[100][100];
bool visited[100][100];
std::queue<std::pair<int, int>> q;

const int offset[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};


void input() {
    
    std::string str;
    
    std::cin >> H >> W;
    for (int i = 0; i < H; ++i) {
        std::cin >> str;
        for (int j = 0; j < W; ++j) {
            field[i][j] = str[j];
        }
    }
}

void init() {
    
    R = 0;
    
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            visited[i][j] = false;

    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (field[i][j] == '#') {
                q.push({i, j});
                visited[i][j] = true;
                return;
            }
        }
    }
}

int dfs(int y, int x) {
    
    for (int i = 0; i < 4; ++i) {
        int ny = y + offset[i][0];
        int nx = x + offset[i][1];
        
        if (!(0 <= ny && ny < H) || !(0 <= nx && nx < W))
            continue;
        
        if (!visited[ny][nx] && field[ny][nx] == '#') {
            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
    
    return 1;
}


void solve() {
   
    while (!q.empty()) {
        
        int y = q.front().first;
        int x = q.front().second;
        
        R += dfs(y, x);
        
        bool flag = false;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j] && field[i][j] == '#') {
                    q.push({i, j});
                    visited[i][j] = flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        
        q.pop();
    }
}



int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        input();
        init();
        solve();
        std::cout << R << std::endl;
    }
    
    return 0;
}
