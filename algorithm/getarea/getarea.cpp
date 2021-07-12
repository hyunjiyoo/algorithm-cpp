#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

const int offset[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int M, N, K, tot_cnt, cnt;
bool area[100][100];
bool visited[100][100];
std::queue<std::pair<int, int>> q;
std::vector<int> v;


void input() {
    std::scanf("%d %d %d", &M, &N, &K);
    
    int x1, x2, y1, y2;
    for (int i = 0; i < K; ++i) {
        std::scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int j = y1; j < y2; ++j) {
            for (int k = x1; k < x2; ++k) {
                area[j][k] = true;
            }
        }
    }
    
    tot_cnt = 0;
    
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!area[i][j]) {
                visited[i][j] = true;
                q.push({i, j});
                ++tot_cnt;
                return;
            }
        }
    }
}


void dfs(int y, int x) {
    
    for (int i = 0; i < 4; ++i) {
        int ny = y + offset[i][0];
        int nx = x + offset[i][1];
        
        if (!(0 <= ny && ny < M) || !(0 <= nx && nx < N)) continue;
        
        if (!visited[ny][nx] && !area[ny][nx]) {
            visited[ny][nx] = area[ny][nx] = true;
            ++cnt;
            dfs(ny, nx);
        }
    }
}


void solve() {
    
    while (!q.empty()) {
        
        int y = q.front().first;
        int x = q.front().second;
        
        cnt = 1;
        dfs(y, x);
        v.push_back(cnt);
        
        bool flag = false;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!visited[i][j] && !area[i][j]) {
                    visited[i][j] = true;
                    q.push({i, j});
                    ++tot_cnt;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        
        q.pop();
    }
}


void output() {
    std::sort(v.begin(), v.end());
    
    std::printf("%d\n", tot_cnt);
    for (auto c : v)
        std::printf("%d ", c);
    
}

int main (int argc, const char * argv []) {
    
    input();
    solve();
    output();
    
    return 0;
}
