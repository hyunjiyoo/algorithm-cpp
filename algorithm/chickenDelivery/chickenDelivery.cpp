#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits>

int n, m, ret;
std::vector<std::pair<int, int>> chk, h;
int dist[100][13];
int candidate[13];
int min_dist[100];


void input() {
    std::scanf("%d%d", &n, &m);
    
    int type = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::scanf("%d", &type);
            
            if (type == 2)
                chk.push_back({i, j});
            
            if (type == 1)
                h.push_back({i, j});
        }
    }
}


void init() {
    
    for (int i = 0; i < chk.size(); ++i) {
        int y = chk[i].first;
        int x = chk[i].second;
        
        for (int j = 0; j < h.size(); ++j) {
            int hy = h[j].first;
            int hx = h[j].second;
            int d = std::abs(hy - y) + std::abs(hx - x);
            
            dist[j][i] = d;
        }
    }
    
    ret = std::numeric_limits<int>::max();
    
    for (int i = 0; i < h.size(); ++i)
        min_dist[i] = 1'000'000;
}


void get_min_dist() {
    for (int i = 0; i < m; ++i) {
        int idx = candidate[i];
        
        for (int j = 0; j < h.size(); ++j)
            min_dist[j] = std::min(min_dist[j], dist[j][idx]);
    }
}

void get_total_dist() {
    int sum = 0;
    for (int i = 0; i < h.size(); ++i)
        sum += min_dist[i];
    
    ret = std::min(ret, sum);
}

void init_min_dist() {
    for (int i = 0; i < h.size(); ++i)
        min_dist[i] = 1'000'000;
}


void solve(int step = 0, int num = 0) {
    
    if (step == m) {
        get_min_dist();
        get_total_dist();
        init_min_dist();
        return;
    }
    
    for (int i = num; i < chk.size(); ++i) {
        candidate[step] = i;
        solve(step + 1, i + 1);
    }
}


int main (int argc, const char * argv []) {
    
    input();
    init();
    solve();
    std::printf("%d", ret);
    
    return 0;
}
