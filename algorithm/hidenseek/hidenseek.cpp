#include <iostream>
#include <cstring>
#include <queue>

int N, K;
std::queue<int> q;
int number[100'001];

void init() {
    std::memset(number, 0, sizeof number);
    
    q.push(N);
    number[N] = 1;
}


void solve() {
    
    while (!q.empty()) {
        
        if (number[K])
            break;
        
        int num1 = q.front() * 2;
        int num2 = q.front() + 1;
        int num3 = q.front() - 1;
        
        if (num1 <= 100'000 && !number[num1]) {
            number[num1] = number[q.front()] + 1;
            q.push(num1);
        }
            
        if (num2 <= 100'000 && !number[num2]) {
            number[num2] = number[q.front()] + 1;
            q.push(num2);
        }

        if (num3 >= 0 && !number[num3]) {
            number[num3] = number[q.front()] + 1;
            q.push(num3);
        }
        
        q.pop();
    }
}

int main (int argc, const char * argv[]) {
    
    std::scanf("%d %d", &N, &K);
    init();
    solve();
    std::printf("%d", number[K] - 1);
    
    return 0;
}
