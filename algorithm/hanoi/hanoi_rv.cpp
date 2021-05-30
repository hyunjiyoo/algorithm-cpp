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
    if (n == 1) {
        return 1;
    }
    
    int cnt = 2*print(n-1) + 1;
    return cnt;
}



int main() {
    int n;
    std::cin >> n;
    
    std::printf("%d\n", print(n));
    
    move(n, 1, 3);
    
    return 0;
}
