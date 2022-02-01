#include <iostream>
#include <vector>
#include <queue>

int n;
int r[100'001];
std::vector<int> v[100'001];
std::queue<int> q;

void input() {
    
    std::scanf("%d", &n);
    
    int a, b;
    for (int i = 1; i < n; ++i) {
        std::scanf("%d %d", &a, &b);
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    r[1] = 1;
    q.push(1);
}

void solve() {
    
    while (!q.empty()) {
        int num = q.front();
                    
        for (int i : v[num]) {
            if (!r[i]) {
                r[i] = num;
                q.push(i);
            }
        }
        
        q.pop();
    }
}

void output() {
    
    for (int i = 2; i <= n; ++i)
        std::printf("%d\n", r[i]);
}


int main (int argc, const char * argv []) {
    
    input();
    solve();
    output();
    
    return 0;
}
