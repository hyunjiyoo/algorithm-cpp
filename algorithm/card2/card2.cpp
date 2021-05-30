#include <iostream>
#include <queue>

int N;
std::queue<int> q;

int main (int argc, const char * argv []) {
    std::scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }
    
    int num = 0;
    while(1) {
        if (q.size() == 1) break;
        
        q.pop();
        num = q.front();
        q.pop();
        q.push(num);
    }
    
    std::printf("%d", q.front());
    
    return 0;
}
