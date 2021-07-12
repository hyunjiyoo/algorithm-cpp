#include <iostream>
#include <queue>

const int offset[6][3] = { {0, -1, 0}, {0, 0, -1}, {0, 1, 0}, {0, 0, 1}, {1, 0, 0}, {-1, 0, 0} };

typedef struct {
    int z;
    int y;
    int x;
} point;

bool able;
int M, N, h, min;
std::queue<point> q;
int tomato[100][100][100];
bool visited[100][100][100];

void input() {
    
    min = 0;
    able = false;
    std::scanf("%d %d %d", &M, &N, &h);
    
    for (int k = 0; k < h; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                
                std::scanf("%d", &tomato[k][i][j]);
                visited[k][i][j] = false;
                
                if (tomato[k][i][j] == 0) {
                    able = true;
                }
                
                if (tomato[k][i][j] == 1) {
                    q.push({k, i, j});
                    visited[k][i][j] = true;
                }
            }
        }
    }
}


void solve() {
    
    int z, y, x;
    
    while(!q.empty()) {
        z = q.front().z;
        y = q.front().y;
        x = q.front().x;
        
        for (int i = 0; i < 6; ++i) {
            int nz = z + offset[i][0];
            int ny = y + offset[i][1];
            int nx = x + offset[i][2];
            
            if (!(0 <= nz && nz < h) ||
                !(0 <= ny && ny < N) ||
                !(0 <= nx && nx < M)) continue;
            
            if (!visited[nz][ny][nx] && tomato[nz][ny][nx] == 0) {
                tomato[nz][ny][nx] = tomato[z][y][x] +  1;
                visited[nz][ny][nx] = true;
                q.push({nz, ny, nx});
            }
        }
        
        q.pop();
    }
}

bool possible() {
    
    for (int k = 0; k < h; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (tomato[k][i][j] == 0)
                    return false;
                else
                    min = std::max(min, tomato[k][i][j]);
            }
        }
    }
    
    return true;
}


int main (int argc, const char * argv []) {
    
    input();
    
    if (able) {
        
        solve();
        
        if (possible())
            std::printf("%d", min - 1);
        else
            std::printf("-1");
    }
    else {
        std::printf("0");
    }
    
    return 0;
}
