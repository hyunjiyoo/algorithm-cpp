#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

typedef struct {
    int y;
    int x;
} point;

int H, W, R;
int dist[50][50];
char island[50][50];
std::queue<point> lq, q;


void input() {
    R = 0;
    
    std::cin >> H >> W;
    for (int i = 0; i < H; ++i) {
        std::string str;
        std::cin >> str;
        for (int j = 0; j < W; ++j) {
            island[i][j] = str[j];
            if (island[i][j] == 'L')
                lq.push({i, j});
        }
    }
}


void findroad() {
    
    int y = 0;
    int x = 0;
    
    while (true) {
        
        if (q.empty()) {
            R = std::max(R, dist[y][x] - 1);
            break;
        }
        
        y = q.front().y;
        x = q.front().x;
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (!(0 <= ny && ny < H) || !(0 <= nx && nx < W)) continue;
            
            if (dist[ny][nx] == 0 && island[ny][nx] == 'L') {
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
        
        q.pop();
    }
}


void initialize() {
    while (!q.empty()) q.pop();

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            dist[i][j] = 0;
        }
    }
}


void solve() {
    
    while (!lq.empty()) {
        int y = lq.front().y;
        int x = lq.front().x;
        
        q.push({y, x});
        dist[y][x] = 1;
        findroad();
        initialize();
        
        lq.pop();
    }
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve();
    std::cout << R;
    
    return 0;
}
