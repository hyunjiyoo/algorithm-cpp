#include <iostream>
#include <queue>

const int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

typedef struct {
    int y;
    int x;
} point;

int C, I, R;
int chess[300][300];
std::queue<point> q;
point src, dst;

void init() {
    R = 0;
    while (!q.empty()) q.pop();
}

void input() {
    
    std::scanf("%d", &I);
    std::scanf("%d %d", &src.y, &src.x);
    std::scanf("%d %d", &dst.y, &dst.x);
    
    for (int i = 0; i < I; ++i) {
        for (int j = 0; j < I; ++j) {
            chess[i][j] = 0;
        }
    }
    
    q.push({src.y, src.x});
}


void move() {
    
    int y, x;
    
    while (!q.empty()) {
        y = q.front().y;
        x = q.front().x;
        
        if (y == dst.y && x == dst.x) {
            R = chess[y][x];
            break;
        }
        
        for (int i = 0; i < 8; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (!(0 <= ny && ny < I) || !(0 <= nx && nx < I))
                continue;
            
            if (chess[ny][nx] == 0) {
                chess[ny][nx] = chess[y][x] + 1;
                q.push({ny, nx});
            }
        }
        
        q.pop();
    }
}


int main (int argc, const char * argv []) {
    
    std::scanf("%d", &C);
    
    for (int i = 0; i < C; ++i) {
        init();
        input();
        move();
        std::printf("%d\n", R);
    }
    
    return 0;
}
