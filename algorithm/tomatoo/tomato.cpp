#include <iostream>
#include <queue>

int M, N;
int tomato[1'000][1'000];
std::queue<std::pair<int, int>> q;

const int offset[4][2] = {
    {0, -1}, {-1, 0}, {0, 1}, {1, 0}
};


void input() {
    std::ios::sync_with_stdio(false);
    std::cin >> M >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> tomato[i][j];
            if (tomato[i][j] == 1)
                q.push({i, j});
        }
    }
}


void solve() {

    while (!q.empty()) {
        
        int y = q.front().first;
        int x = q.front().second;
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + offset[i][0];
            int nx = x + offset[i][1];
            
            if (!(0 <= ny && ny < N) || !(0 <= nx && nx < M))
                continue;
            
            if (tomato[ny][nx] == 0) {
                tomato[ny][nx] = tomato[y][x] + 1;
                q.push({ny, nx});
            }
        }
        
        q.pop();
    }
}


bool ripenTomato() {
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (tomato[i][j] == 0)
                return false;
        }
    }
    
    return true;
}

void output() {
    
    int day = 0;
    if (ripenTomato()) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                day = std::max(day, tomato[i][j]);
            }
        }
        
        std::cout << day - 1;
    }
    else
        std::cout << -1;
}

int main (int argc, const char * argv []) {
    
    input();
    solve();
    output();
    
    return 0;
}
