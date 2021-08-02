#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int N;
bool able;
std::vector<int> v, visited;
std::queue<std::pair<int, int>> q;

void input() {
    std::ios::sync_with_stdio(false);
    std::cin >> N;
    
    visited.resize(N);
    
    v.resize(N);
    for  (int i = 0; i < N; ++i)
        std::cin >> v[i];
    
    q.push({0, v[0]});
    able = false;
    visited[0] = 1;
}


void solve() {
    
    while (!q.empty()) {
        
        if (visited[N - 1] != 0) {
            able = true;
            break;
        }
        
        int pos = q.front().first;
        int jump = q.front().second;
        
        for (int i = pos + 1; i <= pos + jump; ++i) {
            if (i >= N) break;
            
            if (visited[i] == 0) {
                visited[i] = visited[pos] + 1;;
                q.push({i, v[i]});
            }
        }
        
        q.pop();
    }
    
}

int main (int argc, const char * argv []) {
    
    input();
    solve();
    
    if (able)
        std::cout << visited[N - 1] - 1;
    else
        std::cout << "-1";
    
    return 0;
}
