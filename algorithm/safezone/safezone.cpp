#include <iostream>
#include <algorithm>
#include <vector>

const int offset[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int N, R, zone_cnt;
int zone[100][100];
bool visited[100][100];
std::vector<int> v;

void input() {
    
    R = 1;
    v.push_back(0);
    
    std::scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::scanf("%d", &zone[i][j]);
            visited[i][j] = false;
            v.push_back(zone[i][j]);
        }
    }
    
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
}


void init(int height) {
    
    zone_cnt = 0;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            visited[i][j] = (zone[i][j] <= height) ? true : false;
        }
    }
}

void dfs(int y, int x, int height) {
    
    for (int i = 0; i < 4; ++i) {
        int dy = y + offset[i][0];
        int dx = x + offset[i][1];
        
        if (!(0 <= dy && dy < N) || !(0 <= dx && dx < N)) continue;
        
        if (!visited[dy][dx]) {
            visited[dy][dx] = true;
            dfs(dy, dx, height);
        }
    }
}

std::pair<int, int> pick_base() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

bool is_complete(std::pair<int, int> base) {
    return (base.first == -1 && base.second == -1);
}


void solve() {
    
    for (auto height : v) {
        
        init(height);
        
        while (true) {
            auto base = pick_base();
            
            if (is_complete(base))
                break;
            
            int y = base.first;
            int x = base.second;
            
            dfs(y, x, height);
            ++zone_cnt;
        }
        
        R = (R > zone_cnt) ? R : zone_cnt;
    }
    
    std::printf("%d", R);
}

int main (int argc, const char * argv []) {
    
    input();
    solve();
    
    return 0;
}
