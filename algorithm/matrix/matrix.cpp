#include <iostream>
using namespace std;

int N;
int64_t B;

int A[5][5];
int TMP[5][5];
int R[5][5];

bool CHK[37];
int finalIdx;

void init() {
    finalIdx = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            A[i][j] = R[i][j] = TMP[i][j] = 0;
}


void input() {
    scanf("%d %lld", &N, &B);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &A[i][j]);
            R[i][j] = A[i][j];
        }
    }
}


void copy() {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            R[i][j] = TMP[i][j];
}


void divideB() {
    int i = 0;
    while (B > 0) {
        if (B % 2 == 1)
            CHK[i] = true;
        else
            CHK[i] = false;
        
        i += 1;
        B /= 2;
    }
    
    finalIdx = i - 1;
}


void solve() {
    
    for (int idx = finalIdx - 1; idx >= 0; --idx) {
        
        // 같은거 곱해줄때
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                TMP[i][j] = R[i][0] * R[0][j] % 1000;
                for (int k = 1; k < N; ++k)
                    TMP[i][j] += R[i][k] * R[k][j] % 1000;
            }
        }
        // R에 TMP 복사
        copy();
        
        if (CHK[idx]) {
            // A행렬 곱해주기
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    TMP[i][j] = R[i][0] * A[0][j] % 1000;
                    for (int k = 1; k < N; ++k)
                        TMP[i][j] += R[i][k] * A[k][j] % 1000;
                }
            }
            // R에 TMP 복사
            copy();
        }
    }
}


void print() {
    for (int i = 0; i < N; ++i) {
        
        for (int j = 0; j < N; ++j) {
            if (j != N - 1)
                printf("%d ", R[i][j] % 1000);
            else
                printf("%d", R[i][j] % 1000);
        }
        
        if (i != N - 1) printf("\n");
    }
}


int main (int argc, const char * argv []) {
   
    init();
    input();
    divideB();
    solve();
    print();

    return 0;
}
