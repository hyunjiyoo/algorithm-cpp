#include <iostream>
#include <queue>
#include <limits>

int n, m, r, sum, min;
bool friends[101][101];
bool visited[101];
std::queue<std::pair<int, int>> q;

void input() {
    
    std::cin >> n >> m;
    
    int a, b;
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b;
        friends[a][b] = friends[b][a] = true;
    }
    
    min = std::numeric_limits<int>::max();
}

void init(int start) {
    
    for (int i = 1; i <= n; ++i)
        visited[i] = false;
    
    sum = 0;
    q.push({start, 1});
}

void bfs() {
    
    while (!q.empty()) {
        int basis = q.front().first;
        int count = q.front().second;
        
        visited[basis] = true;
        
        for (int i = 1; i <= n; ++i) {
            if (basis == i || visited[i]) continue;
            
            if (friends[basis][i]) {
                visited[i] = true;
                sum += count;
                q.push({i, count + 1});
            }
        }
        
        q.pop();
    }
}

void solve() {
    
    for (int i = 1; i <= n; ++i) {
        init(i);
        bfs();
        
        if (min > sum) {
            min = sum;
            r = i;
        }
    }
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve();
    std::cout << r;
    
    return 0;
}
