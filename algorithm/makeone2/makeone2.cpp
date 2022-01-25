#include <iostream>
#include <vector>
#include <queue>

int X;
std::vector<int> v, R;
std::queue<int> q;

void init() {
    v.resize(X + 1);
    R.push_back(X);
    q.push(1);
}


void solve() {
    
    int num1, num2, num3;
    
    while (!q.empty()) {
        
        int x = q.front();
        
        num1 = x + 1;
        num2 = x * 2;
        num3 = x * 3;
        
        if (num1 <= X && !v[num1]) {
            v[num1] = x;
            q.push(num1);
        }

        if (num2 <= X && !v[num2]) {
            v[num2] = x;
            q.push(num2);
        }
        
        if (num3 <= X && !v[num3]) {
            v[num3] = x;
            q.push(num3);
        }
        
        if (v[X])
            break;
        
        q.pop();
    }
}


void trace(int num = X) {
    if (num == 1)
        return;
    
    R.push_back(v[num]);
    trace(v[num]);
}

void output() {
    std::printf("%ld\n", R.size() - 1);
    
    for (int num : R)
        std::printf("%d ", num);
}

int main (int argc, const char * argv []) {
    
    std::scanf("%d", &X);
        
    init();
    solve();
    trace();
    output();
    
    return 0;
}
