#include <iostream>
#include <cstring>
#include <queue>

int N;
int visited[1'000'001];
std::queue<int> q;


void init() {
    std::memset(visited, 0, sizeof visited);
    std::scanf("%d", &N);
    q.push(N);
}

void solve() {
    
    while (!q.empty()) {
        
        int n = q.front();
        if (n == 1) break;
        
        int a;
        if (n % 3 == 0) {
            a = n / 3;
            if (visited[a] == 0) {
                q.push(a);
                visited[a] = visited[n] + 1;
            }
        }
        
        if (n % 2 == 0) {
            a = n / 2;
            if (visited[a] == 0) {
                q.push(a);
                visited[a] = visited[n] + 1;
            }
        }
        
        a = n - 1;
        if (visited[a] == 0) {
            q.push(a);
            visited[a] = visited[n] + 1;
        }
        
        q.pop();
    }
}

int main (int argc, const char * argv []) {
    
    init();
    solve();
    std::printf("%d", visited[1]);
    
    return 0;
}
