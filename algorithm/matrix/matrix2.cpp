#include <iostream>
#include <vector>

const int D = 1'000;
int64_t B;
int N;
// 필요한 만큼만 만들어 사용하기위해 2차원 벡터를 만듬
using mat_t = std::vector<std::vector<int>>;
// M : 입력행렬
// E : 영행렬
// R : 결과행렬
mat_t M, E, R;

// 행렬곱 편하게 하기위해 연산자 오버로딩
// 아래처럼 사용가능
//
// mat_t a, b;
// a *= b (a = a * b)
const mat_t& operator*=(mat_t& a, const mat_t& b) {
    mat_t ret = E;
    
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            for (int k = 0; k < N; ++k)
                ret[y][x] += (a[y][k] * b[k][x]) % D;
            ret[y][x] %= D;
        }
    }
    
    a = ret;
    return a;
}

void input() {
    std::cin >> N >> B;
    
    E.resize(N, std::vector<int>(N, 0));
    M = E;
    
    int value;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            std::cin >> value;
            M[y][x] = value % D;
        }
    }
    
    
}

mat_t solve(int64_t step = B) {
    if (step == 1)
        return M;
    
    mat_t ret = solve(step / 2);
    ret *= ret;
    
    if (step & 0x1)
        ret *= M;
    
    return ret;
}

void output() {
    for (int y = 0; y < N; ++y) {
        int x = 0;
        
        for (; x < N - 1; ++x)
            std::cout << R[y][x] << " ";
        
        std::cout << R[y][x] << "\n";
    }
}

int main(int argc, const char* argv[]) {
    input();
    R = solve();
    output();
    return 0;
}
