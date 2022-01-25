#include <iostream>
#include <string>
#include <vector>
#include <queue>

int R, C;
std::queue<std::pair<int, int>> q;
char field[500][500];
bool visited[500][500];
bool able;

const int offset[4][2] = {
    {0, -1}, {0, 1}, {1, 0}, {-1, 0}
};

void input() {
    std::cin >> R >> C;
    
    std::string str;
    for (int i = 0; i < R; ++i) {
        std::cin >> str;
        for (int j = 0; j < C; ++j) {
            field[i][j] = str[j];
            
            if (field[i][j] == 'S')
                q.push({i, j});
        }
    }
    
    able = true;
}


void solve() {
        
    while (!q.empty()) {
        
        int y = q.front().first;
        int x = q.front().second;
        
        visited[y][x] = true;
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + offset[i][0];
            int nx = x + offset[i][1];
            
            if (!(0 <= ny && ny < R) || !(0 <= nx && nx < C))
                continue;
            
            if (visited[ny][nx] || field[ny][nx] == 'S')
                continue;
            
            if (field[ny][nx] == 'W') {
                able = false;
                return;
            }
            
            visited[ny][nx] = true;
            field[ny][nx] = 'D';
        }
           
        q.pop();
    }
}


void output() {
    
    std::cout << able << std::endl;
    
    if (able) {
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j)
                std::cout << field[i][j];
            std::cout << std::endl;
        }
    }
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve();
    output();
    
    return 0;
}
