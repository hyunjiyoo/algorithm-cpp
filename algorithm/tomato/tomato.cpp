#include <iostream>
#include <queue>

using pair = std::pair<int, int>;

int M, N, day;
int tomato[1'002][1'002];
std::queue<pair> q;

void init() {
    day = 0;
    
    for (int i = 0; i < N + 2; ++i) {
        for (int j = 0; j < M + 2; ++j) {
            tomato[i][j] = -2;
        }
    }
}

void input() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            std::scanf("%d", &tomato[i][j]);
            
            if (tomato[i][j] == 1)
                q.push({i, j});
        }
    }
}


void solve() {
    
    int y, x;
    int offset[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    while (!q.empty()) {
            
        y = q.front().first;
        x = q.front().second;
        
        for (int i = 0; i < 4; ++i) {
            int dy = y + offset[i][0];
            int dx = x + offset[i][1];
            
            if (tomato[dy][dx] == 0) {
                tomato[dy][dx] = tomato[y][x] + 1;
                day = tomato[dy][dx] - 1;
                q.push({dy, dx});
            }
        }
        
        q.pop();
    }
}


bool output() {

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (tomato[i][j] == 0)
                return false;
        }
    }
    
    return true;
}

int main (int argc, const char * argv []) {
    
    std::scanf("%d %d", &M, &N);
    
    init();
    input();
    solve();
    
    if (output())
        std::printf("%d", day);
    else
        std::printf("-1");
    
    return 0;
}
