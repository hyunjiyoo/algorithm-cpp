#include <iostream>
#include <algorithm>
#include <numeric>

const long long NEGINF = std::numeric_limits<long long>::min();
int C, N, M;
int A[100], B[100];
int cache[101][101];
int R;

void input() {
    std::scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", A + i);
    }
        
    for (int i = 0; i < M; ++i) {
        std::scanf("%d", B + i);
    }
}

void init() {
    R = 0;
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j) {
            cache[i][j] = -1;
        }
    }
}


int solve(int indexA = -1, int indexB = -1) {
    std::cout << indexA << " : " << indexB << std::endl;
    int& ret = cache[indexA + 1][indexB + 1];
    if (ret != -1) return ret;
    
    ret = 2;
    
    long long a = (indexA == -1) ? NEGINF : A[indexA];
    long long b = (indexB == -1) ? NEGINF : B[indexB];
    long long maxElem = std::max(a, b);
    
    for (int nexta = indexA + 1; nexta < N; ++nexta) {
        if (maxElem < A[nexta]) {
            ret = std::max(ret, solve(nexta, indexB) + 1);
        }
    }
    
    for (int nextb = indexB + 1; nextb < M; ++nextb) {
        if (maxElem < B[nextb])
            ret = std::max(ret, solve(indexA, nextb) + 1);
    }
    
    return ret;
}


int main (int argc, const char * argv []) {
    
    std::scanf("%d", &C);
    
    for (int i = 0; i < C; ++i) {
        input();
        init();
        R = solve() - 2;
        std::printf("%d\n", R);
    }
    
    return 0;
}
