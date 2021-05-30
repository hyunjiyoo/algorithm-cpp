#include <iostream>

int N, M, S, R;
int V[100];

void solve0(int idx = 0, int accum = S) {
    if (idx == N) {
        if((M - R) > (M - accum))
            R = accum;
        return;
    }
    
    if (accum - V[idx] >= 0)
        solve0(idx + 1, accum - V[idx]);

    if (accum + V[idx] <= M)
        solve0(idx + 1, accum + V[idx]);
    
    return;
}

void print_cast() {
    std::printf("%d %d %d\n", N, S, M);
    for(int i = 0; i < N; ++i)
        std::printf("%d ", V[i]);
    std::printf("\n%d\n\n", R);
    
    return;
}

int main(int argc, const char* argv[]) {
    while (true) {
        N = rand() % 3 + 1;
        M = rand() % 10 + 1;
        S = rand() % M + 1;
        R = -1;

        for(int i = 0; i < N; ++i)
            V[i] = rand() % M + 1;

        solve0();

        print_cast();
    }

    return 0;
}
