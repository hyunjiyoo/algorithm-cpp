#include <iostream>
#include <string>
#include <queue>

int N, M;
int miro[102][102];
bool visited[102][102];
std::queue<std::pair<int, int>> q;

void init() {
    for (int i = 0; i < 102; ++i) {
        for (int j = 0; j < 102; ++j) {
            miro[i][j] = -1;
            visited[i][j] = false;
        }
    }
}

void input() {
    
    std::string str;
    for (int i = 1; i <= N; ++i) {
        std::cin >> str;
        for (int j = 1; j <= M; ++j) {
            miro[i][j] = str[j - 1] - '0';
        }
    }
    
    q.push({1, 1});
    visited[1][1] = true;
}


void solve() {
    
    int offset[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    while (!q.empty()) {

        int y = q.front().first;
        int x = q.front().second;
        
        if (y == N && x == M)
            break;
        
        for (int i = 0; i < 4; ++i) {
            int dy = y + offset[i][0];
            int dx = x + offset[i][1];
            
            if (!visited[dy][dx] && miro[dy][dx] == 1) {
                miro[dy][dx] = miro[y][x] + 1;
                visited[dy][dx] = true;
                q.push({dy, dx});
            }
        }
        
        q.pop();
    }
    
    std::printf("%d", miro[N][M]);
}


int main (int argc, const char * argv []) {
    
    std::cin >> N >> M;
    
    init();
    input();
    solve();
    
    return 0;
}
