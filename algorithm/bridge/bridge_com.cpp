#include <iostream>

int T, N, M;
int C[30][30];

int comb(int n, int k) {
    if (n == 1 || k == 0 || k == n)
        return 1;

    if (C[n][k] == 0)
        C[n][k] = comb(n-1, k) + comb(n-1, k-1);

    return C[n][k];
}

int main() {
    std::scanf("%d", &T);
    
    for(int i = 0; i < T; ++i) {
        std::scanf("%d %d", &N, &M);
        
        int result = comb(M, N);
        
        std::printf("%d\n", result);
    }
    
    return 0;
}

// 팩토리얼은 결과값보다 너무 큰 수를 미리 구해버려서 숫자가 너무 커져서 int자료형이 담을 수 없다.
//
//#include <iostream>
//
//int T, N, M;
//int F[31] = { 0, 1, };
//
//void init() {
//    for (int i = 2; i <= 30; ++i)
//        F[i] = F[i - 1] * i;
//}
//
//int main(int argc, const char* argv[]) {
//    init();
//
//    std::scanf("%d", &T);
//
//    for(int i = 0; i < T; ++i) {
//        std::scanf("%d %d", &N, &M);
//
//        int result = (F[M] / F[N]) * F[M - N];
//
//        std::printf("%d\n", result);
//    }
//
//    return 0;
//}
