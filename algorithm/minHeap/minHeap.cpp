#include <iostream>
#include <queue>

int N;
std::priority_queue<int, std::vector<int>, std::greater<int>> q;

int main (int argc, const char * argv []) {
    std::scanf("%d", &N);
    
    int num = 0;
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", &num);
        
        if (num > 0) {
            q.push(num);
        }
        else if (num == 0) {
            
            int v = 0;
            
            if (!q.empty()) {
                v = q.top();
                q.pop();
            }
            std::printf("%d\n", v);
        }
    }
    
    return 0;
}
