#include <iostream>
#include <algorithm>
#include <queue>

using pair = std::pair<int, int>;

int N, M, K;
std::priority_queue<pair, std::vector<pair>, std::greater<pair>> beer; // level, prefer
std::priority_queue<pair, std::vector<pair>, std::greater<pair>> drink; // prefer, level

void input() {
    std::scanf("%d %d %d", &N, &M, &K);
    
    int v, c;
    for (int i = 0; i < K; ++i) {
        std::scanf("%d %d", &v, &c);
        beer.push(std::make_pair(c, v));
    }
}

void solve() {
    
    int level, prefer;
    int sum = 0;
    int R = -1;
    std::pair<int, int> b, d;
    
    while (!beer.empty()) {
        b = beer.top();
        level = b.first;
        prefer = b.second;
        
        drink.push(std::make_pair(prefer, level));
        sum += prefer;
        beer.pop();

        if (drink.size() > N) {
            d = drink.top();
            sum -= d.first;
            drink.pop();
        }
        
        if (sum >= M && drink.size() == N) {
            R = level;
            break;
        }
    }
    
    std::printf("%d", R);
    
    return;
}


int main (int argc, const char * argv []) {
    
    input();
    solve();
    
    return 0;
}
