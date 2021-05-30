#include <iostream>

int N;
int T[15];
int P[15];
bool consult[15];
int profit;


void init() {
    profit = -999;
    
    for (int i = 0; i < N; ++i) {
        std::cin >> T[i] >> P[i];
    }
}

bool possible(int date) {
    
    bool flag = false;
    if (date + T[date] <= N)
        flag = true;
    return flag;
    
}


void consulting(int date = 0, int sum = 0) {
    
    if (date >= N) {
        profit = std::max(profit, sum);
        return;
    }
    
    for (int i = date; i < N; ++i) {
        if (possible(i))
            consulting(i + T[i], sum + P[i]);
        else
            profit = std::max(profit, sum);
    }
    
}


int main(int argc, const char * argv[]) {
    
    std::cin >> N;
    
    init();
    consulting();
    
    std::cout << profit << std::endl;
    
    return 0;
}
