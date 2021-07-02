#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

int N, count;
int complex[27][27];
bool visited[27][27];
std::queue<std::pair<int,int>> q;
std::vector<int> v;

void init() {
    for (int i = 0; i < N + 2; ++i) {
        for (int j = 0; j < N + 2; ++j) {
            complex[i][j] = -1;
            visited[i][j] = false;
        }
    }
}


void input() {
    std::string str;
    for (int i = 1; i <= N; ++i) {
        std::cin >> str;
        for (int j = 1; j <= N; ++j) {
            complex[i][j] = str[j - 1] - '0';
        }
    }
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (complex[i][j] == 1) {
                q.push({i, j});
                visited[i][j] = true;
                return;
            }
        }
    }
}


void dfs(int y, int x) {
    int offset[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    for (int i = 0; i < 4; ++i) {
        int dy = y + offset[i][0];
        int dx = x + offset[i][1];
        
        if (!(0 < dy && dy <= N) || !(0 < dx && dx <= N)) continue;
        
        if (!visited[dy][dx] && complex[dy][dx] == 1) {
            ++count;
            visited[dy][dx] = true;
            dfs(dy, dx);
        }
    }
}


void solve() {

    int y, x;
    
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        
        count = 1;
        dfs(y, x);
        v.push_back(count);
        
        bool flag = false;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (!visited[i][j] && complex[i][j] == 1) {
                    visited[i][j] = true;
                    q.push({i, j});
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
    
    std::printf("%d\n", (int)v.size());
    for (int i : v)
        std::printf("%d\n", i);
}


int main (int argc, const char * argv []) {
    
    std::cin >> N;
    init();
    input();
    solve();
    output();
    
    return 0;
}
