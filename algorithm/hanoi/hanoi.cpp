#include <iostream>

void move(int n, int a, int b) {
    
    if (n == 1) {
        std::printf("%d %d\n", a, b);
        
        return;
    }
    
    move(n-1, a, 6-a-b);
    move(1, a, b);
    move(n-1, 6-a-b, b);
}


int print(int n) {
    
    if (n == 1)
        return 1;
    
    int tot_cnt = 2 * print(n-1) + 1;
    
    return tot_cnt;
}


int main() {
    int n;
    std::cin >> n;
    
    std::printf("%d\n", print(n));
    
    if(n > 20) {
        return 0;
    }
    else {
        move(n, 1, 3);
    }
    
    return 0;
}
