#include <iostream>
#include <string>
#include <queue>

const int offset[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int N, R1, R2;
char grid[100][100];
bool visited[100][100];
std::queue<std::pair<int, int>> q;

void input() {
    std::string str;
    
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> str;
        for (int j = 0; j < N; ++j) {
            grid[i][j] = str[j];
        }
    }
    R1 = R2 = 0;
}

void dfs(int y, int x, bool rgblind) {
    
    for (int i = 0; i < 4; ++i) {
        int dy = y + offset[i][0];
        int dx = x + offset[i][1];
        
        if (!(0 <= dy && dy < N) || !(0 <= dx && dx < N)) continue;
            
        if (visited[dy][dx]) continue;
    
        if (rgblind) {
            if (grid[y][x] == 'B') {
                if (grid[dy][dx] == 'B') {
                    visited[dy][dx] = true;
                    dfs(dy, dx, true);
                }
            }
            else {
                if (grid[dy][dx] == 'R' || grid[dy][dx] == 'G') {
                    visited[dy][dx] = true;
                    dfs(dy, dx, true);
                }
            }
        }
        else {
            if (grid[y][x] == grid[dy][dx]) {
                visited[dy][dx] = true;
                dfs(dy, dx, false);
            }
        }
    }
}


void solve(bool rgblind) {
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            visited[i][j] = false;
        }
    }
    
    int y, x;
    q.push({0, 0});
    visited[0][0] = true;
    
    while (!q.empty()) {
        
        y = q.front().first;
        x = q.front().second;
        
        if (rgblind) {
            dfs(y, x, true);
            ++R2;
        }
        else {
            dfs(y, x, false);
            ++R1;
        }
        
        bool flag = false;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!visited[i][j]) {
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
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve(false);
    solve(true);
    
    std::cout << R1 << ' ' << R2;
    
    return 0;
}
