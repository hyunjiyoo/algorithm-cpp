#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

int N, R, height;
int AREA[100][100];
bool visited[100][100];
std::queue<std::pair<int, int>> q;
std::set<int> H;
std::set<int>::iterator it;

const int offset[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};


void input() {
    
    std::cin >> N;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> AREA[i][j];
            H.insert(AREA[i][j]);
        }
    }
    
    R = 1;
}

void init() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (AREA[i][j] > height)
                visited[i][j] = false;
            else
                visited[i][j] = true;
        }
    }
    
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j] && AREA[i][j] > height) {
                q.push({i, j});
                visited[i][j] = true;
                return;
            }
        }
    }
}


int dfs(int y, int x) {
    
    for (int i = 0; i < 4; ++i) {
        int ny = y + offset[i][0];
        int nx = x + offset[i][1];
        
        if (!(0 <= ny && ny < N) || !(0 <= nx && nx < N)) continue;
        
        if (!visited[ny][nx] && AREA[ny][nx] > height) {
            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
    
    return 1;
}

void solve() {
    
    for (it = H.begin(); it != H.end(); ++it) {
        
        int count = 0;
        height = *it;
        init();
        
        while (!q.empty()) {
            
            int y = q.front().first;
            int x = q.front().second;
            
            count += dfs(y, x);
            
            bool flag = false;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (!visited[i][j] && AREA[i][j] > height) {
                        q.push({i, j});
                        visited[i][j] = flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
           
            q.pop();
        }
        
        R = std::max(R, count);
    }
}

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve();
    std::cout << R;
    
    return 0;
}
