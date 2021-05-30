#include <iostream>
#include <cmath>
#include <cassert>
#include <cstdlib>

int n, R;
int A[8];
bool C[8] = { false, };
int S[8];
int LIST[8];

void solve(int step = 0) {
    if (step == n) {
        int result = 0;
        
        for(int i = 1; i < n; ++i)
            result += std::abs(S[i] - S[i - 1]);
        
        if (result > R) {
            for(int i = 0; i < n; ++i)
                LIST[i] = S[i];
        }
        R = std::max(R, result);
    }
    
    for(int i = 0; i < n; ++i) {
        if (C[i] == false) {
            C[i] = true;
            S[step] = A[i];
            solve(step + 1);
            C[i] = false;
        }
    }
}

int newA[8];

void sort() {
    
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (A[j] < A[j + 1]) {
                tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
    }
    return;
}

void maxdiff() {

    int j = 0; int k = (n-1)/2;
    for (int i = (n-1)/2; i < n; i +=2) {
        newA[i] = A[j];
        newA[k+1] = A[n-1-j];
        j += 1;
        k -= 2;
    }
    
    newA[0] = A[(n-1)/2];
    newA[n-1] = A[(n-1)/2 + 1];
}


int calulate() {
    int sum = 0;
    for (int i = 0; i < n-1; ++i) {
        if (newA[i] < newA[i+1])
            sum += newA[i+1] - newA[i];
        else
            sum += newA[i] - newA[i+1];
    }
    
    return sum;
}

void make_input() {
    for (int i = 0; i < n; ++i) {
        A[i] = (std::rand() % 200) - 100;
    }
}

int main(int argc, const char* argv[]) {
    
    
    std::scanf("%d", &n);
    std::printf("\n\n");
    
    while (true) {
        make_input();
        
        R = 0;
        for(int i = 0; i < 8; ++i)
            C[i] = false;
        solve();
        
        sort();
        maxdiff();
        
        int ret = calulate();
        
        if (ret != R) {
            std::printf("%d\n", n);
            for(int i = 0; i < n; ++i)
                std::printf("%d ", A[i]);
            std::printf("\n\n");
            
            
            for(int i = 0; i < n; ++i)
                std::printf("%d ", newA[i]);
            std::printf("\n%d\n\n", ret);
            
            for(int i = 0; i < n; ++i)
                std::printf("%d ", LIST[i]);
            std::printf("\n%d\n\n", R);
            std::printf("------------\n");
    
        }
    }

    return 0;
}
