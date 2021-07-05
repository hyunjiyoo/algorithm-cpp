#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
#include <queue>

using pair = std::pair<int, int>;

int N, M, R, count;
int map[8][8];
int ori[8][8];
bool visited[8][8];
std::vector<int> wall;
std::queue<pair> q;


void init() {
    R = std::numeric_limits<int>::min();
    
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            visited[i][j] = false;
            map[i][j] = ori[i][j] = 0;
        }
    }
}


void input() {
    std::scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::scanf("%d", &map[i][j]);
            ori[i][j] = map[i][j];
        }
    }
}


pair point(int num) {
    int y = num / M;
    int x = num % M;

    return {y, x};
}

void makewall() {
    for (int i = 0; i < wall.size(); ++i) {
        pair p = point(wall[i]);
        
        int y = p.first;
        int x = p.second;
        
        if (map[y][x] == 0)
            map[y][x] = 1;
    }
}


void bfs() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] == 2) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    
    int y, x;
    int offset[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    while (!q.empty()) {
     
        y = q.front().first;
        x = q.front().second;
        
        for (int i = 0; i < 4; ++i) {
            int dy = y + offset[i][0];
            int dx = x + offset[i][1];
            
            if (!(0 <= dy && dy < N) || !(0 <= dx && dx < M)) continue;
            
            if (!visited[dy][dx] && map[dy][dx] == 0) {
                map[dy][dx] = 2;
                visited[dy][dx] = true;
                q.push({dy, dx});
            }
        }
        
        q.pop();
    }
}

void countsafezone() {
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] == 0) ++count;
        }
    }
    
    R = R > count ? R : count;
}

void copymap() {
    count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            map[i][j] = ori[i][j];
            visited[i][j] = false;
        }
    }
}


void solution() {
    makewall();
    bfs();
    countsafezone();
    copymap();
}


void combination(int step = 0, int num = -1) {
    if (step == 3) {
        solution();
        return;
    }
    
    for (int i = num + 1; i < N * M; ++i) {
    
        int y = point(i).first;
        int x = point(i).second;
        
        if (map[y][x] == 0) {
            wall.push_back(i);
            combination(step + 1, i);
            wall.pop_back();
        }
    }
}


int main (int argc, const char * argv []) {
    
    init();
    input();
    combination();
    std::printf("%d", R);
    
    return 0;
}
