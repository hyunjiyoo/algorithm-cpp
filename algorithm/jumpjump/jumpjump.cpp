#include <iostream>
#include <queue>

int N;
bool able;
int A[1'000];
int visited[1'000];
std::queue<std::pair<int, int>> q;

void input() {
    std::scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", A + i);
    }
    
    able = false;
    q.push({0, A[0]});
    visited[0] = 1;
}


void solve() {
    
    while (!q.empty()) {
        if (visited[N - 1] != 0) {
            able = true;
            break;
        }
            
        int pos = q.front().first;
        for (int i = 1; i <= q.front().second; ++i) {
            if (visited[pos + i] == 0) {
                q.push({pos + i, A[pos + i]});
                visited[pos + i] = visited[pos] + 1;
            }
        }
    
        q.pop();
    }
}

void output() {
    if (able)
        std::printf("%d", visited[N - 1] - 1);
    else
        std::printf("-1");
}


int main (int argc, const char * argv []) {
    
    input();
    solve();
    output();
    
    return 0;
}
