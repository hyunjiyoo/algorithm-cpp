#include <iostream>
#include <vector>

int n, a, b, m;
bool able;
std::vector<std::vector<bool>> v;
std::vector<int> visited;

void input() {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin >> n >> a >> b >> m;
    
    v.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        v[i].resize(n + 1);
    
    int x, y;
    for (int i = 0; i < m; ++i) {
        std::cin >> x >> y;
        v[x][y] = v[y][x] = true;
    }
    
    for (int i = 1; i <= n; ++i)
        v[i][i] = true;
    
    able = false;
    visited[a] = 1;
}

void solve(int basis = a) {
    
    if (basis == b) {
        able = true;
        return;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 0 && v[basis][i]) {
            visited[i] = visited[basis] + 1;
            solve(i);
        }
    }
}

int main (int argc, const char * argv []) {
    
    input();
    solve();
    
    if (able)
        std::cout << visited[b] - 1;
    else
        std::cout << "-1";
    
    return 0;
}
