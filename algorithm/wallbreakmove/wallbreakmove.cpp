#include <iostream>
#include <string>
#include <queue>

const int offset[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int N, M;
bool able;
int map[1'000][1'000];
bool visited[1'000][1'000][2];
std::queue<std::pair<int, int>> q;


void input() {
    std::string str;
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        std::cin >> str;
        for (int j = 0; j < M; ++j) {
            map[i][j] = str[j] - '0';
            visited[i][j][0] = visited[i][j][1] = false;
        }
    }
    
    able = false;
    map[0][0] = 1;
    q.push({0, 0});
    visited[0][0][0] = true;
}


void solve() {
    
    int y, x;
    
    while (!q.empty()) {
        
        y = q.front().first;
        x = q.front().second;
        
        if (y == N-1 && x == M-1) {
            able = true;
            break;
        }
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + offset[i][0];
            int nx = x + offset[i][1];
            
            if (!(0 <= ny && ny < N) || !(0 <= nx && nx < M)) continue;
            
            visited[ny][nx][1] = visited[y][x][1];
            
            if (!visited[ny][nx][1] && map[ny][nx] == 1) {
                map[ny][nx] = 0;
                visited[ny][nx][1] = true;
            }
            
            if (!visited[ny][nx][0] && map[ny][nx] == 0) {
                visited[ny][nx][0] = true;
                map[ny][nx] = map[y][x] + 1;
                q.push({ny, nx});
            }
        }
        
        q.pop();
    }
}


int main (int argc, const char * argv []) {
    
    input();
    solve();
    
    if (able)
        std::cout << map[N-1][M-1];
    else
        std::cout << -1;
    
    return 0;
}
